#include <stdio.h>
#include "wireless.h"
#include "io.hpp"       // Board sensors
#include "utilities.h"  // delay_ms()
#include <string.h>    // arrays and str
#include <ctype.h>    // toupper/tolower

char lettah;
char numbah;
char letter='A';
char number='1';
char hops=1;
mesh_packet_t pkt;
enum{
    slave_addr=142,
    commander=107,
};

enum{
    SetLeft=1,
    SetRight=2,
};

int main(void){



   while(1){

if(letter>'I'){
    letter='A';
}

if(number>'9'){
    number='1';
}
           if(SW.getSwitch(1)){
                   LD.setLeftDigit(letter++);
                   delay_ms(500);
                   lettah=letter-1;
           } // ends if

           else if(SW.getSwitch(2)){
       LD.setRightDigit(number++);
       delay_ms(500);
       numbah=number-1;
       } // ends else if

       else  if(SW.getSwitch(3)){

                   wireless_form_pkt(&pkt, slave_addr, mesh_pkt_ack, hops,
                                     2,                     /* 2 Pairs below */
                                     &lettah, sizeof(lettah),   /* Pair 1 */
                                     &numbah, sizeof(numbah));  /* Pair 2 */
                   wireless_send_formed_pkt(&pkt);
       }// ends if switch 3



  }// ends while


}// end main

