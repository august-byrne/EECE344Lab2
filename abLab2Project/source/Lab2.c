/*******************************************************************************
* EECE344 Lab 1 Demo Code
*	Displays 'Hello[n]' on the terminal, where n starts at zero and increments
*   each time through the loop. The user selects 'Enter' to go through the loop
*   again, and 'q' to quit.
* Todd Morton, 09/21/2020
*
* Edited by August Byrne
* 10/8/2020
* 	This demo now has a startup message, and pressing 'q' restarts the counter
* 	and displays a restart message
*******************************************************************************/
#include "MCUType.h"               /* Include header files                    */
#include "BasicIO.h"
#include "K65TWR_ClkCfg.h"

void main(void){

    INT8U cur_count = 0;            /* Current count value                    */
    INT8C char_in;                  /* Received character                     */

    K65TWR_BootClock();             /* Initialize MCU clocks                  */
    BIOOpen(BIO_BIT_RATE_115200);   /* Initialize Serial Port                 */
    BIOPutStrg("Program is running. Press 'q' to reset program,\n\r or anything else to receive a 'hello[n]' message\n\r");	//Program startup message, telling the user that the program is currently running, and available user actions
    while(1){
    	char_in = BIOGetChar();         /* Wait for a character to be entered       */
    	if(char_in != 'q'){          /* Display message if 'q' is not entered   */
			BIOPutStrg("Hello[");
			BIOOutDecWord(cur_count,3,BIO_OD_MODE_LZ);
			BIOPutStrg("]\n\r");
			cur_count++;                /* Increment counter                      */
		}else{					//restarts the counter and gives a message when 'q' is entered
			cur_count = 0;
			BIOPutStrg("Program Restarted\n\r\n\rProgram is running. Press 'q' to reset program,\n\r or anything else to receive a 'hello[n]' message\n\r");	//notification that program has restarted, and startup message
		}
    }
}
