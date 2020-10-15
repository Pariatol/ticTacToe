#include <stdio.h>
#include <stdlib.h>

  void printGrille(char grilleFct[3][3]);
  void saisieUser(int x, int y, char grilleFct[3][3],char joueur);
  int checkWin(char grilleFct[3][3]);
  int checkIfFull(char grilleFct[3][3]);

  int main(){

    int fin_partie = 0;
    char joueur = 'X';
    int tryAgain = 1;
    int coordX,coordY;

    char grille[3][3] = 
    {
      {'.','.','.'},
      {'.','.','.'},
      {'.','.','.'}
    };

    do{

      saisieUser(coordX,coordY,grille,joueur);
      printGrille(grille);

      if(checkIfFull(grille)==1){
        printf("La grille est pleine.\n");
        break;
      }
      if(checkWin(grille)==1)
        break;

      if(joueur=='X')
        joueur='Y';
      else
        joueur='X';

    }while(fin_partie==0);

    

    return 0;

  }

void printGrille(char grilleFct[3][3]){
  for(int i=0;i<3;i++){
      putchar('|');
      for(int j=0;j<3;j++){
        printf(" %c ",grilleFct[i][j]);
      }
      printf("|\n");
    }
}

void saisieUser(int x, int y, char grilleFct[3][3],char joueur){

  int tryAgain = 1;
  while(tryAgain==1){
    printf("Joueur %c, que voulez-vous jouer ?\n",joueur);
    printf("En x: ");
    scanf("%d",&x);
    printf("En y: ");
    scanf("%d",&y);

    if(grilleFct[y][x]=='.' && y<=2 && x<=2){
      grilleFct[y][x] = joueur;
      tryAgain=0;
      } 
    else if(y > 2 || x > 2){
      printf("Coordonnées non disponibles. Recommencez.\n");
    }
    else if(grilleFct[y][x]=='X' || grilleFct[y][x]=='Y'){
      printf("Case déjà occupée, starfoulah\n");
      }
  }
}
  
int checkWin(char grilleFct[3][3]){
  int winner = 0;
  char ligne[3] = {0};
  char colonne[3] = {0};
  char diag1[3] = {0};
  char diag2[3] = {0};


  // remplissage diagonale 1
  diag1[0] = grilleFct[0][0];
  diag1[1] = grilleFct[1][1];
  diag1[2] = grilleFct[2][2];

  diag2[0] = grilleFct[2][0];
  diag2[1] = grilleFct[1][1];
  diag2[2] = grilleFct[0][2];

  // colonnes gagnantes

  if(diag1[0] == diag1[1] && diag1[1] == diag1[2] && diag1[0]!='.'){
      printf("LE JOUEUR %c a gagne !\n",diag1[0]);
      winner = 1;
      } 

  if(diag2[0] == diag2[1] && diag2[1] == diag2[2] && diag2[0]!='.'){
printf("LE JOUEUR %c a gagne !\n",diag2[0]);
winner = 1;
} 
  
  
  for(int i=0;i<3;i++){
        

    for(int j=0;j<3;j++){

      // lignes gagnantes
      ligne[j] = grilleFct[i][j];
      
      if(ligne[0] == ligne[1] && ligne[1] == ligne[2] && ligne[0]!='.'){
      printf("LE JOUEUR %c a gagne !\n",grilleFct[i][j]);
      winner = 1;
      } 
    }

      // colonnes gagnantes
      colonne[i] = grilleFct[i][0];
      if(colonne[0] == colonne[1] && colonne[1] == colonne[2] && colonne[0]!='.'){
      printf("LE JOUEUR %c a gagne !\n",grilleFct[i][0]);
      winner = 1;
      } 


    
  }
  // it works !
  if(winner==1){
    return 1;
  } else {
    return 0;
  }
  

}

int checkIfFull(char grilleFct[3][3]){
  int fullGrid = 1;

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(grilleFct[i][j]=='.'){
        fullGrid = 0;
      }
    }
  }

  return fullGrid==0?0:1;
}
