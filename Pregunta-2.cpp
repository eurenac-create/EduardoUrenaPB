/* Cifrar y Descifrar mensajes, segun el desplazamiento de letras
* vector char codificacionDecodificacion: contiene todas las letras del abecedario, minusculas 
* como mayusculas
* metodo cifrarMensaje que debe, segun el desplazamiento, cifrar el mensaje
* metodo descifrarMensaje que debe, segun el desplazamiento, descifrar el mensaje
* Todo debe realizarse por punteros
* Debe imprimir el mensaje cifrado y el mensaje descifrado (Que debe ser igual mensaje original)
* EL MENSAJE NO DEBE TENER ESPACIOS EN BLANCO, cuando se le solicite el mensaje
* Ejemplo: digita "HolaComoEstas" cuando se cifre el mensaje debe imprimir algo como esto
* "LCpoGCqCUwxow", y cuando descifre el mensaje de imprimir igual al mensaje original, es decir
* "HolaComoEstas"
* Valor 2 puntos, si realiza de forma correcta los dos metodos
* Valor 1, si solo funciona un solo metodo
* Valor 0, sino funciona ninguno de los dos
*/

#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

char codificacionDecodificacion[] = {
        ' ','A','E','I','O','U','a','e','i','o','u',
        'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z',
        'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'
};

// Función para cifrar un mensaje utilizando el cifrado César
void cifrarMensaje(char* m, int desplazamiento,char* code) {

    int tam = 55;

    for(int i = 0; *(m+i) != '\0'; i++){

        for(int j = 0; j < tam; j++){

            if(*(m+i) == *(code+j)){

                int nuevaPos = (j + desplazamiento) % tam;

                *(m+i) = *(code+nuevaPos);
                break;
            }
        }
    }

    cout << "Mensaje cifrado: " << m;
}

// Función para descifrar un mensaje utilizando el cifrado César
void descifrarMensaje(char* m, int desplazamiento, char* code) {

    int tam = 55;

    for(int i = 0; *(m+i) != '\0'; i++){

        for(int j = 0; j < tam; j++){

            if(*(m+i) == *(code+j)){

                int nuevaPos = (j - desplazamiento) % tam;

                if(nuevaPos < 0)
                    nuevaPos += tam;

                *(m+i) = *(code+nuevaPos);
                break;
            }
        }
    }

    cout << "Mensaje descifrado: " << m;
}

int main() {
    char mensaje[100];
    int d = 0;
    cout << "Digite mensaje a cifrar: ";
    cin >> mensaje;
    cout << "Digite desplazamiento: ";
    cin >> d;
    cifrarMensaje(mensaje, d,codificacionDecodificacion);
    cout <<endl << "Digite mensaje descifrar: ";
    cin >> mensaje;
    descifrarMensaje(mensaje, d, codificacionDecodificacion);

    return 0;
}
