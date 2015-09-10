/*
 * funcionesSWAP.h
 *
 *  Created on: 4/9/2015
 *      Author: utnso
 */

#ifndef FUNCIONESSWAP_H_
#define FUNCIONESSWAP_H_

#include <commons/string.h>
#include <commons/config.h>
#include <stdio.h>
#include <stdlib.h>
#include <commonsDeAsedio/error.h>
#include <string.h>
#include <commonsDeAsedio/mmap.h>

#define PUERTO_ESCUCHA "PUERTO_ESCUCHA"
#define NOMBRE_SWAP "NOMBRE_SWAP"
#define CANTIDAD_PAGINAS "CANTIDAD_PAGINAS"
#define TAMANIO_PAGINA "TAMANIO_PAGINA"
#define RETARDO_COMPACTACION "RETARDO_COMPACTACION"

typedef struct{
	int puertoDeEscucha;
	char* nombreDeSWAP;
	int cantidadDePaginas;
	int tamanioDePagina;
	int retardoDeCompactacion;
}tipoConfigSWAP;


////////////////////FUNCIONES PARA EL MANEJO DE ARCHIVO DE CONFIGURACION///////////////////////

tipoConfigSWAP* crearConfigSWAP();

void destruirConfigSWAP (tipoConfigSWAP* estructuraDeConfiguracion);

tipoConfigSWAP* cargarArchivoDeConfiguracionDeSWAP(char* rutaDelArchivoDeConfiguracion);



//////////////FUNCIONES PARA EL ARCHIVO DE PARTICION///////////////////////

FILE* inicializarParticion(char* nombreDeParticion,int tamanioDePagina,int cantidadDePaginas);



#endif /* FUNCIONESSWAP_H_ */
