#include <iostream>
#include <fstream>

using namespace std;
void dividir (int a[], int inicial, int final);
void fusionar (int a[], int pinicial, int pfinal, int medio);

ofstream archivo;

int main() {
  
  string nombre;
  cout << "Ingrese el nombre del archivo: ";
  getline (cin, nombre);
  archivo.open(nombre.c_str (), ios::app);

  archivo << "Ordenamiento MergeSort" << endl;

  int numeros[10] = {10, 150, 39, 48, 800, 355, 1, 19, 2, 35};
  
  for(int i = 0; i < 6; i++){
    cout << "|" << numeros[i] << "|"; // imprime arreglo ordenado
    archivo << "|" << numeros[i] << "|";
  }
  
  dividir(numeros, 0, 6);
  cout << endl;
  for(int i = 0; i < 6; i++){
    cout << "|" << numeros[i] << "|";
    archivo << "|" << numeros[i] << "|";
  }

  


  return 0;
}

void dividir (int a[], int inicial, int final){
  int mitad;
  if(inicial < final){
    mitad = (inicial + final) / 2;
    dividir(a, inicial, mitad);
    dividir(a, mitad + 1, final);
    fusionar(a, inicial, final, mitad);
  }
}

void fusionar (int a[], int pinicial, int pfinal, int medio){
  int i, j, k, temp[pfinal - pinicial + 1];
  i = pinicial;
  k = 0;
  j = medio - 1;

  while (i <= medio & j <= pfinal){
    if (a[i] < a[j]){
      temp[k] = a[i];
      k++;
      i++;
    }
    else {
      temp[k] = a[j];
      k++;
      j++;
    }
  }

  while(i <= medio){
    temp[k] = a[i];
    k++;
    i++;
  }
  while(i <= pfinal){
    temp[k] = a[j];
    k++;
    j++;
  }

  for (i = pinicial; i <= pfinal; i++){
    a[i] = temp[i- pinicial];
  }
}