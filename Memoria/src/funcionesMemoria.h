/*
 * funcionesMemoria.h
 *
 *  Created on: 4/9/2015
 *      Author: utnso
 */

#ifndef FUNCIONESMEMORIA_H_
#define FUNCIONESMEMORIA_H_

#include <commons/string.h>
#include <commons/config.h>
#include <stdio.h>
#include <stdlib.h>
#include <commonsDeAsedio/error.h>
#include <commonsDeAsedio/cliente-servidor.h>
#include <commonsDeAsedio/estructuras.h>


#define PUERTO_ESCUCHA "PUERTO_ESCUCHA"
#define IP_SWAP "IP_SWAP"
#define PUERTO_SWAP "PUERTO_SWAP"
#define MAXIMO_MARCOS_POR_PROCESO "MAXIMO_MARCOS_POR_PROCESO"
#define CANTIDAD_MARCOS "CANTIDAD_MARCOS"
#define TAMANIO_MARCO "TAMANIO_MARCO"
#define ENTRADAS_TLB "ENTRADAS_TLB"
#define TLB_HABILITADA "TLB_HABILITADA"
#define RETARDO_MEMORIA "RETARDO_MEMORIA"

typedef struct{
	int puertoDeEscucha;
	char* ipSWAP;
	int puertoSWAP;
	int maximoDeMarcosPorProceso;
	int cantidadDeMarcos;
	int tamanioDeMarco;
	int entradasDeTLB;
	char* TLBHabilitada;
	int retardoDeMemoria;
}tipoConfigMemoria;


tipoConfigMemoria* crearConfigMemoria();

void destruirConfigMemoria(tipoConfigMemoria* estructuraDeConfiguracion);

tipoConfigMemoria* cargarArchivoDeConfiguracionDeMemoria(char* rutaDelArchivoDeConfiguracion);

void tratarPeticion(int socketParaCpus,int socketParaSwap,int socketParaLeer);

void tratarPeticiones(int socketParaCpus,int socketParaSwap,t_list* listaLectura);

/***************instrucciones*******************/
void ejecutarInstruccion (tipoInstruccion instruccionCPU);

/****iniciar N*****/
int reservarMemoriaEnSwap(tipoInstruccion instruccion, int socketSwap);

int reservarMemoriaEnRam(tipoInstruccion instruccion);

void cancelarInicializacion(int procesoID);

void reservarMemoriaParaProceso(tipoInstruccion instruccion, int socketCPU, int socketSWAP);

/*******leer pagina***********/
int buscarPaginaEnRam(tipoInstruccion instruccion, char* contenidoDePagina);

int buscarPaginaEnSwap(tipoInstruccion instruccion, char* contenidoDePagina, int socketSwap);

void enviarPaginaACPU(tipoInstruccion instruccion, char* contenidoDePagina);

void pedirPaginaDesdeSwapARam(tipoInstruccion instruccion, char* contenidoDePagina, int socketSwap);

void leerPagina(tipoInstruccion instruccion, int socketSwap);

#endif /* FUNCIONESMEMORIA_H_ */
