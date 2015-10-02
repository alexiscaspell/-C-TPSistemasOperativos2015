/*
 * estructuras.h
 *
 *  Created on: 18/9/2015
 *      Author: utnso
 */

#ifndef COMMONSDEASEDIO_ESTRUCTURAS_H_
#define COMMONSDEASEDIO_ESTRUCTURAS_H_

#include <commons/string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cliente-servidor.h"
#include <commons/string.h>


//resultado de ejecucion
#define MANQUEADO 'm'
#define PERFECTO 'p'

//instrucciones
#define FINALIZAR 'f'
#define INICIAR 'i'
#define LECTURA 'l'
#define ESCRIBIR 'e'
#define ENTRADA_SALIDA 's'

typedef struct{
	int pid;
	int insPointer;
	char estado;
	char* ruta;
} tipoPCB;

typedef struct{
	char instruccion;

	int pid;

	int nroPagina;

	char* texto;
}tipoInstruccion;

typedef struct{

	char respuesta;

	char* informacion;
}tipoRespuesta;


void* serializarPCB(tipoPCB pcb);

void deserializarPCB(void* bloque, tipoPCB* pcbrecibido);

tipoPCB* recibirPCB(int socketEnviador);

void enviarPCB(int socketCliente,tipoPCB pcb);

void imprimirBufferPCB(void* buffer);

void* serializarInstruccion(tipoInstruccion instruccion);

void deserializarInstruccion(void* buffer,tipoInstruccion* instruccion);

tipoInstruccion* recibirInstruccion(int socketEnviador);

void enviarInstruccion(int socketCliente,tipoInstruccion instruccion);

void* serializarRespuesta(tipoRespuesta respuesta);

void deserializarRespuesta(void* buffer,tipoRespuesta* respuesta);

tipoRespuesta* recibirRespuesta(int socketEnviador);

void enviarRespuesta(int socketCliente,tipoRespuesta respuesta);

//-------------------LEONEGRO----------------------------------------

//ronan: esto lo hice yo lpm, dejen de robar mi trabajo

tipoRespuesta* crearTipoRespuesta(char respuesta, char* informacion);

void destruirTipoRespuesta(tipoRespuesta* respuesta);

void destruirTipoInstruccion(tipoInstruccion* instruccion);

#endif /* COMMONSDEASEDIO_ESTRUCTURAS_H_ */
