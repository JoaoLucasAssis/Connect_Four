
#define linha 6
#define coluna 7

void inicializarJogo();
void imprimir();
void jogar();

int colunaValida(int n);
int opcaoValida(char opcao);
int posicaoVazia(int n, int *l);
int ganhouLinha();
int ganhouColuna();
int ganhouDiagPrincipal();
/*int ganhouDiagSecundaria();*/

char connect[linha][coluna];

int main(void) {
  int opcao;
  
  do {
    inicializarJogo();
    jogar();
    printf("\n\nDeseja jogar novamente?\n");
    printf("[1] SIM | [ ] Qualquer tecla para sair\n");
    scanf("%i", &opcao);

    system("clear");
    
  } while(opcao == 1);
  return 0;
}

void inicializarJogo() {
  for(int i = 0; i < linha; i++) {
    for(int j = 0; j < coluna; j++) 
      connect[i][j] = '.';
  }
}

void jogar() {
  
  int n, l, valida, g = 0;
  char opcao;

  imprimir();
  
  do {
    do {
      printf("\nDigite o número da coluna: ");
      scanf("%i", &n);
      
      valida = colunaValida(n);
      
      if(valida == 1) {
        printf("Sua opção: "); 
        scanf("\n%c", &opcao);
        valida += opcaoValida(opcao);
      }
  } while(valida != 2);
    
    valida += posicaoVazia(n, &l);
    
    if (valida == 3)
      connect[l][n - 1] = opcao;
    else 
      printf("Coluna cheia. Escolha outra coluna.\n\n");

    system("clear");
    
    imprimir();
    
    g += ganhouLinha();
    g += ganhouColuna();
    g += ganhouDiagPrincipal();
    //g += ganhouDiagSecundaria();

  } while(g == 0);

  if(g != 0)
    printf("\nGanhou.");
}

void imprimir() {
  int l = 1, c = 1;
  
  printf("\n\n");
  
  for(int pos = 0; pos < coluna; pos++) {
    printf("   %i", c); c++; 
  }
  printf("\n");
  for(int i = 0; i < linha; i++) {
    printf("%i   ", l);
    l++;
    for(int j = 0; j < coluna; j++) 
      printf("%c   ", connect[i][j]);
    
    printf("\n\n");
  }
}

int colunaValida(int n) {
  if((n - 1) > 6 || n <= 0)
    return 0;
  return 1;
}

int opcaoValida(char opcao) {
  if(opcao == 'x' || opcao == 'o')
    return 1;
  else
    return 0;
}

int posicaoVazia(int n, int *l) {
  
  for(int i = 5; i >= 0; i--) {
    
    if((connect[i][n - 1] != 'x') && (connect[i][n - 1] != 'o'))
    {
      *l = i;
      return 1;
    }
  }
  return 0;
}

int ganhouLinha() {
  int g = 1;
  
  for(int i = 0; i < linha; i++) {
    for(int j = 0; j < coluna; j++) {
      if((connect[i][j] == 'x' || connect[i][j] == 'o') && connect[i][j] == connect[i][j+1])
        g++;
    }
    if(g == 4)
      return 1;
    g = 1;
  }
  return 0;
}

int ganhouColuna() {
  int g = 1;
  for(int j = 0; j < 7; j++) {
    for(int i = 0; i < 6; i++) {
      if((connect[i][j] == 'x' || connect[i][j] == 'o') && connect[i][j] == connect[i+1][j])
        g++;
    }
    if(g == 4)
      return 1;
    else
      g = 1;
  }
  return 0;
}

int ganhouDiagPrincipal() {
  int g1 = 1, g2 = 1, g3 = 1, g4 = 1, g5 = 1, g6 = 1;

  for(int i = 0, j = 1; i < 5; i++, j++) {
      //[0, 0]
      if((connect[i][i] == 'x' || connect[i][i] == 'o') && (connect[i][i] == connect[i+1][i+1]))
        g1++;
      //[0, 1]
      if((connect[i][j] == 'x' || connect[i][j] == 'o') && (connect[i][j] == connect[i+1][j+1]))
        g2++;
      //[0, 2]
      if((connect[i][j+1] == 'x' || connect[i][j+1] == 'o') && (connect[i][j+1] == connect[i+1][j+2]))
        g3++;
      //[0, 3]
      if((connect[i][j+2] == 'x' || connect[i][j+2] == 'o') && (connect[i][j+2] == connect[i+1][j+3]))
        g4++;
  }
  for(int i = 1, j = 0; i < 5; i++, j++) {
    //[1, 0]
    if((connect[i][j] == 'x' || connect[i][j] == 'o') && (connect[i][j] == connect[i+1][j+1]))
      g5++;
    //[2, 0]
    if((connect[i+1][j] == 'x' || connect[i+1][j] == 'o') && (connect[i+1][j] == connect[i+2][j+1]))
      g6++;
  }
  
  if(g1 >= 4 || g2 >= 4 || g3 >= 4 || g4 >= 4 || g5 >= 4 || g6 >= 4) 
    return 1;
  return 0;
}

/*int ganhouDiagSecundaria() {
  int g1 = 1, g2 = 1;
  for(int i = 5, j = 0; i >= 1; i--, j++) {
    //[5, 0]
    if((connect[i][j] == 'x' || connect[i][j] == 'o') && (connect[i][j] == connect[i--][j++]))
      g1++;
    //[5, 1]
    if((connect[i][j++] == 'x' || connect[i][j++] == 'o') && (connect[i][j++] == connect[i--][j+2]))
      g2++;
  }
  if(g1 >= 4 || g2 >= 4) 
    return 1;
  return 0;
}*/