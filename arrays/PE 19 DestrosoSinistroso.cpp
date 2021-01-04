//
//  main.cpp
//  destroso
//
//  Created by Stefano Pigliafreddo on 02/01/2021.


/*Si scriva, in linguaggio C++, la funzione individuaSequenza che, avendo come parametri una matrice di interi ad una sola cifra (0-9) di dimensione MxN ed un numero intero, restituisca come valore di ritorno il numero di volte in cui ha trovato le cifre del numero passato come parametro, prese nell’ordine destrorso o sinistrorso lungo la sola direzione orizzontale; la funzione deve inoltre stampare a video e su un file appositamente creato, le coordinate della cella a partire dalla quale è stata individuata la sequenza ed il suo verso. Ogni sequenza individuata non dovrà necessariamente appartenere alla stessa riga. Ad es. passati come parametri l’intero 4213 e la seguente matrice */

#include <iostream>
#include <iomanip>
using namespace std;

int const R = 6;
int const C = 8;


//---PROTOTIPI FUNZIONI
void stampaMatrice(int mat[R][C]);
int individuaSequenza(int mat[R][C], int numero[4]);
    

//----MAIN
int main() {
    int numero[4] = {4,2,1,3};
    int mat[R][C]  = {
            {7,3,5,4,2,1,3,8},
            {9,6,5,3,4,4,2,1},
            {3,7,8,1,5,6,0,2},
            {2,7,6,2,4,3,1,9},
            {0,5,1,4,5,7,9,8},
            {6,3,1,2,4,7,7,0},

};

   stampaMatrice(mat);
    
    int nvolte = individuaSequenza(mat,numero);
    cout << "Il totale dei match è: " << nvolte <<endl;
     
    

};//end of main

    
//----------------------------
int individuaSequenza(int mat[R][C], int numero[4]){
    //ciclo righe
    int contatore = 0;
    int i=0,j=0,k=0;
    
        for (i=0;i<R;i++) {

            //ciclo fino a metà della matrice
            for(j=0;j<=C/2;j++) {
                k=0;
                
                //controllo il primo numero
                if ((mat[i][j]/numero[k]==1)) {
                    if ((mat[i][j+1]/numero[k+1]==1)&& (mat[i][j+2]/numero[k+2]==1)&&(mat[i][j+3]/numero[k+3]==1)){
                      
            //se lo trovo controllo le altre cifre
            cout << "(trovato destroso nella posizione :(" << i <<" - " << j << ")\n";
                        contatore++;}
        }
        // caso a capo TODO
      }
    }

      // SINISTROSO
    
      //itero sulle righe
      for (i=0;i<R;i++) {
          //itero sulle colonne ma dall'ultima indietro fino alla metà compresa
          for (j=C-1;j>=C/2;j--) {
          //k = 0 perchè il numero si resetta controllando le cifre dalla parte zero
              k=0;
              if ((mat[i][j]/numero[k]==1)) {
       
                  //se il primo numero da sinistra a destra per le
                  if ((mat[i][j-1]/numero[k+1]==1)&& (mat[i][j-2]/numero[k+2]==1)&&(mat[i][j-3]/numero[k+3]==1)){
           
                      cout << "trovato sinistroso nella posizione :(" << i << " - " << j << ")\n";
                      contatore++;}
            
        }
       //Caso a capo
      }
    }
    return contatore;
};//end fun

void stampaMatrice(int mat[R][C]){

int i=0,j=0;
for (i=0;i<R;i++) {
    for (j=0;j<C;j++) {
        cout << mat[i][j] << " ";
    }
    cout << endl;
    }
};








/*
 size_t i, j, size, rows, cols;
 int founded = 0;

 size = sizeof(A) / sizeof(A[0]);
 rows = sizeof(B) / sizeof(B[0]);
 cols = sizeof(B[0]) / sizeof(B[0][0]);
 for (i = 0; i < rows; i++) {
     for (j = 0; j < cols - size; j++) {
         if (memcmp(A, &B[i][j], sizeof(A)) == 0) {
             founded = 1;
             break;
         }
     }
     if (founded) break;
 }
 if (founded) printf("Row: /zu Col: /zu\n", i + 1, j + size);
 return 0;
}
*/
