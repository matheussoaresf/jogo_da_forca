#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>


char spalavra[20];                         // PALAVRA
char bpalavra[100][20];                    // MATRIZ QUE ARMAZENA AS PALAVRAS DO ARQUIVO
char tpalavra[20];                         // PALVRA SORTEADA PREENCHIDA COM UNDERLINE
char letrasdigitadas[20];                  // VETOR QUE ARMAZENA AS LETRAS JA DIGITADAS
char letra;                                // VARIAVEL QUE RECEBE A LETRA DIGITADA PELO USURAIO
int chances = 6;                           // CONTABILIDADE
int indice = 0;                            // DETERMINA A POSIÇÃO DO VETOR letrasdigitadas[]
int qtdletras1=0;                          // CONTABILLIZA QUANTAS LETRAS A PALAVRA SORTEADA POSSUI
int ganhar = 0;                            // CONTA A QUANTIDADE DE LETRAS ACERTADAS PELO USUARIO
char deci = 'S';                           // S/SIM N/NAO
char boneco2[6];


int main()
    {
        void fchances();
        void boneco(int chan);
        void sortear_palavra(void);
        void imprimir();
        void fdigitadas();
        int  bip;
        int  i;

    while(deci=='S')
    {
        for(i=0;i<20;i++)                  // RESETANDO O VETOR DE PALAVRASJA DIGITADAS
        letrasdigitadas[i]='\0';
                                           // RESETANDO VARIAVEIS
        letra = '\0';
        chances = 6;
        indice = 0;
        qtdletras1=0;
        ganhar = 0;

        for(i=0;i<6;i++)
            boneco2[i] = '\0';

        sortear_palavra();                  // SORTEIA UMA PALAVRA ALEATORIA DA NOSSA MATRIZ

        int tama = strlen(spalavra)-1;      // ARMAZENA O TAMANHO DA STRING

        while(chances > -1 )                // O LAÇO SERA EXECUTADO ENQUANTO O USUARIO AINDA TIVER CHANCES
        {
                setbuf(stdin,NULL);
                system("cls");
                //printf("\n------------------->  JOGO DA FORCA  <-------------------\n\n");
                fchances();                 // DEPOIS DESSA FUNÇÃO, CHANCES DECRESCE UMA UNIDADE CASO ELE TENHA ERRADO A LETRA

                if(qtdletras1 == ganhar)    // SE ISSO FOR VERDADE, ENTAO A QTD DE LETRAS DA PALAVRA EQUIVALEU À QTD DE LETRAS ACERTADAS PELO JOGADOR
                {
                     do{
                            system("cls");
                            printf("\t.- - - - - - - - - - - - - - - - - - - - - - - - -.\n");
                            printf("\t|          AEEE ! VOCE ACERTOU A PALAVRA        |\n");
                            printf("\t'- - - - - - - - - - - - - - - - - - - - - - - - -'\n");
                            printf("\t\t          O\n");
                            printf("\t\t        o\n");
                            printf("\t\t      . \n");
                            printf("\t\t   \\O/   \n");
                            printf("\t\t    | \n");
                            printf("\t\t   / \\ \n");
                            printf("\n\n - > A palavra era:  %s\n\n",spalavra);
                            printf("Deseja Tentar Novamente? [S/N] :  ");
                            deci = toupper(getchar());
                            setbuf(stdin,NULL);
                        }while( deci != 'N' && deci != 'S' );   // VERIFICA SE O QUE O USUARIO DIGITOU É UM CARACTERE DIFERENTE DE N ou S
                   break;
                }

                if(chances == -1)                               // SE VERDADE, ENTAO O USUARIO ERROU 6 VEZES
                  {

                     do{
                            system("cls");
                            setlocale(LC_ALL,"");
                            printf("\t.- - - - - - - - - - - - - - - - - - - - - - - - -.\n");
                            printf("\t|                 ENFORCADO !!!                   |\n");
                            printf("\t'- - - - - - - - - - - - - - - - - - - - - - - - -'\n");
                            printf("\t  ______\n");
                            printf("\t |      ,       \n");
                            printf("\t |      `.       \n");
                            printf("\t |     0.´       \n");
                            printf("\t |     /|\\      \n");
                            printf("\t |     / \\     \n");
                            printf("   ______|______   \n");


                            printf("\n\n - > A palavra era:  %s\n\n",spalavra);
                            printf("Deseja Tentar Novamente? [S/N] :  ");
                            deci = toupper(getchar());
                            setbuf(stdin,NULL);
                       }while( deci != 'N' && deci != 'S' );    // VERIFICA SE O QUE O USUARIO DIGITOU É UM CARACTERE DIFERENTE DE N ou S
                        break;
                  }
                  do{
                        system("cls");
                            printf("\n------------------->  JOGO DA FORCA  <-------------------\n\n");
                            printf(" -> A palavra possui  %d  letras\n\n",qtdletras1);  // IMPRIME QUANTAS LETRAS A PALAVRA SORTEADA POSSUI
                            boneco(chances);
                            printf("  |_Chances : %d_|\n\n\n",chances);               // IMPRIME O NUMERO DE CHANCES
                            printf("\n");
                imprimir();                                     // FUNCAO QUE FAZ OPERACOES SOBRE A PALAVRA SORTEADA
                            printf("\n\n");
                fdigitadas();                                  // FUNCAO QUE ARMAZENA AS LETRAS DIGITADAS
                            printf("\n\n\t * Insira uMa letra do alfabeto = ");
                  }while(!isalpha(letra=toupper(getchar())));
        }
    }
    return 0;
    }

void boneco( int chan)
{
    char msg[20] = {'\0'};
   if(chan == 5) boneco2[0] = 'O';
   if(chan == 4) boneco2[1] = '|';
   if(chan == 3) boneco2[2] = '/';
   if(chan == 2) boneco2[3] = '\\';
   if(chan == 1) boneco2[4] = '/';
   if(chan == 0)
   {
       boneco2[5] = '\\';
       strcpy(msg,", Socorro !!! ");
   }

                          printf("\t ______\n");
                          printf("\t |    |  %s\n",msg);
                          printf("\t |    %c     \n",boneco2[0]);
                          printf("\t |   %c%c%c\n",boneco2[2],boneco2[1],boneco2[3]);
                          printf("\t |   %c %c\n",boneco2[4],boneco2[5]);
                          printf("\t |\n");
                          printf("   ______|______\n");

}
void sortear_palavra(void)
    {
            int x,i=0;
            FILE *file;
            file = fopen("palavras.txt","r");

                if(file == NULL)
                {
                    printf("Arquivo nao encontrado !\n");
                    exit(1);
                }

            while(fgets(bpalavra[i],20,file) != NULL)   // ARMAZENA CADA PALAVRA DO ARQUIVO TXT EM CADA LINHA DA MATRIZ DE PALAVRAS
            i++;

            fflush(stdin);
            fclose(file);                               // FECHA O ARQUIVO

            srand(time(NULL));                          // SEMENTE ( HORAS ) PARA O SISTEMA RANDOMICO

            x = rand()%100;                             // SORTEIA UM NUMERO DE 0 A 9

            strcpy(spalavra,bpalavra[x]);               // COPIA A PALAVRA SORTEADA PARA MINHA STRING Palavra Sorteada

            int tam = strlen(spalavra)-1;               // ARMAZENA O TAMANHO DA MINHA STRING (O -1 INDICA QUE NAO CONSIDERAMOS O CARACTERE NULO)

            for(i=0;i<tam;i++)                          // ARMAZENA O CARACTERE "_" EM UM VETOR SEMELHANTE AO DA PALAVRA SORTEADA
            tpalavra[i] = '_';

            for(i=0;i<tam;i++)                          // CONTA QUANTAS LETRAS DO ALFABETO A PALAVRA SORTEADA POSSUI
             if(spalavra[i] != ' ')
                qtdletras1++;
    }

void imprimir()
    {
        int i;
        int tam = strlen(spalavra) - 1;                 // ARMAZENA O TAMANHO DA MINHA STRING (O -1 INDICA QUE NAO CONSIDERAMOS O CARACTERE NULO)

        for(i=0;i<tam;i++)                              // VERIFICA SE A LETRA ESTA PRESENTE NA PALAVRA
            if((spalavra[i]) == letra)
                tpalavra[i] = letra;

        printf(" -> PALAVRA  =  [ ");

        for(i=0;i<tam;i++){
            if(isspace(spalavra[i]))                    // SE O CARACTERE DA PALAVRA SORTEADA FOR UM ESPACO EM BRANCO, SERA IMPRIMIDO DOIS ESPAÇOS EM BRANCOS
                printf("  ");
            else
                printf(" %c",tpalavra[i]);}             // CASO CONTRARIO, SERA IMPRIMIDO UM ESPAÇO SEGUIDO DO UNDERLINE

        printf("  ]");
    }

void fchances()
    {
        int naopertence = 0;                            // VARIAVEL QUE INDICA SE A LETRA PERTENCE OU NAO À PALAVRA
        int i,tam = strlen(spalavra) ,veri=0;

        for(i=0;i<tam;i++)                              // VERIFICA SE A LETRA ESTÁ CONTIDA NA PALAVRA
        {
            if((spalavra[i]) == letra)                  // SE ISSO FOR VERDADE, ENTÃO A LETRA ESTÁ CONTIDO NA PALAVRA
            {
                naopertence = 1;
            }
        }

        if(naopertence == 0)                            // SE ISSO FOR VERDADE, ENTAO A LETRA NAO ESTÁ CONTIDA NA PALAVRA
        {
            for(i=0;i<20;i++)                          // VERIFICA SE A LETRA JA FOI DIGITADA
                if(letra == letrasdigitadas[i])         // SE ISSO FOR VERDADE, ENTAO A LETRA NAO PERTENCE, MAS JA FOI DIGITADA
                    veri=1;
            if(veri == 0)                               // SE ISSO FOR VERDADE ENTAO A LETRA NAO PERTENCE, MAS NAO FOI DIGITADA ANTES
            {
                if((isalpha(letra)))                      // VERIFICA SE A LETRA É UMA LETRA VALIDA
                {
                    letrasdigitadas[indice] = letra;    // ARMAZENA A LETRA DIGITADA (NOVA) NO VETOR DE LETRAS JA DIGITADAS

                    indice++;                           // SEU INDICE, ENTAO, É ACRESCENTADO EM UMA UNIDADE
                    chances--;                          // ESSE IF INDICA QUE ELE NAO ACERTOU A LETRA, ENTAO AS CHANCES DECAI DE UMA UNIDADE
                }
            }
        }
        else                                            // SE ISSO FOR VERDADE, ENTAO A LETRA ESTA CONTIDA NA PALAVRA
        {
            for(i=0;i<20;i++)                          // VERIFICA SE A LETRA JA FOI DIGITADA
                if(letra == letrasdigitadas[i])
                    veri=1;
            if(veri == 0)                               // SE ISSO FOR VERDADE, ENTAO A LETRA AINDA NAO FOI DIGITADA
            {
               if(isalpha(letra))                       // VERIFICA SE O CARACTERE E UMA LETRA VALIDA
                {
                    letrasdigitadas[indice] = letra;    // ARMAZENA A LETRA NO VETOR DE LETRAS JA DIGITADAS
                    indice++;                           // ALOCA A PROXIMA LETRA QUE VIRÁ, NA POSICAO SEGUINTE DO VETOR
                }
             for(i=0;i<tam;i++)                         // VERIFICA QUANTAS LETRAS ELE ACERTOU
                if(spalavra[i] == letra)
                  if(isalpha(letra))
                     ganhar++;                          // NO FINAL, ESSA VARIAVEL INDICARÁ QUANTAS LETRAS NOSSA PALAVRA POSSUI
            }
        }
    }

void fdigitadas()
    {
        int i;
        printf("\n\n -> Letras digitadas :  ");

        for(i=0;i<20;i++)                               // IMPRIME O VETOR DE LETRAS JA DIGITADAS
        printf(" %c",letrasdigitadas[i]);

        printf("\n");
    }





