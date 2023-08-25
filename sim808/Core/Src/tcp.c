/*
 * tcp.c
 *
 *  Created on: Aug 18, 2023
 *      Author: Abdullah
 */

#include "tcp.h"

char tx_buffer[100], tmp[100];

void sendCommand(char *cmd) {
	memset(tx_buffer, '\0', sizeof(tx_buffer));
	strcpy((char*) tx_buffer, cmd);
	HAL_UART_Transmit(&MODULE_USART1, (uint8_t*) tx_buffer, sizeof(tx_buffer), 100);
	HAL_Delay(1000);
}

void sendCommandCheck(char *cmd, char *response, char *rxBuffer1) {
	sendCommand(cmd);
	while(strstr(rxBuffer1,response)==NULL){
		sendCommand(cmd);
	}
}

void sendTcpServer(char *rxBuffer3){
	char *cmd;
	sprintf(cmd,"AT+CIPSEND=%d\r\n",strlen(rxBuffer3));
	sendCommand(cmd);
	sendCommand(rxBuffer3);
}

void connect_TCP(char *ip, char *port, char *rxBuffer1) {
	sendCommandCheck("ATE0\r\n","OK",rxBuffer1);
	sendCommandCheck("AT+CIPSHUT\r\n","SHUT OK",rxBuffer1);
	sendCommandCheck("AT+CIPMUX=0\r\n","OK",rxBuffer1);
	sendCommandCheck("AT+CSTT=\"internet\",\"\",\"\"\r\n","OK",rxBuffer1);
	sendCommandCheck("AT+CIICR\r\n","OK",rxBuffer1);
	sendCommand("AT+CIFSR\r\n");
	sprintf(tmp,"AT+CIPSTART=\"TCP\",\"%s\",\"%s\"\r\n",ip,port);
	sendCommandCheck(tmp,"OK",rxBuffer1);
	sendCommandCheck("AT+CIPQSEND=1\r\n","OK",rxBuffer1);
}
