#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fun.h"


char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

int chuteserrados(){
	

    int erros = 0;

    for(int i = 0; i < chutesdados; i++) {

        int existe = 0;

        for(int j = 0; j < strlen(palavrasecreta); j++) {
            if(chutes[i] == palavrasecreta[j]) {
                existe = 1;
                break;
            }
        }

        if(!existe) erros++;
    }

    return erros;

}

int enforcou() {

    int erros = 0;

    for(int i = 0; i < chutesdados; i++) {

        int existe = 0;

        for(int j = 0; j < strlen(palavrasecreta); j++) {
            if(chutes[i] == palavrasecreta[j]) {
                existe = 1;
                break;
            }
        }

        if(!existe) erros++;
    }

    return erros >= 5;
}

int ganhou() {
    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }

    return 1;
}


void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

int jachutou(char letra) {
    int achou = 0;
    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaforca() {

    printf("Voc� j� deu %d chutes\n", chutesdados);

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

void escolhepalavra() {
    FILE* f;

    f = fopen("C:\\Users\\Pichau\\OneDrive\\�rea de Trabalho\\PRO C\\palavras.txt", "r");
    if(f == 0) {
        printf("Banco de dados de palavras n�o dispon�vel\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for(int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

void adicionapalavra(){
	char quer;
	printf("Voce deseja adicionar uma nova palavra? (S/N)\n");
	scanf(" %c",&quer);
	
	if(quer == 'S' or quer == 's'){
		char novaPalavra[20];
		printf("Digite a nova palavra, em letras maiusculas\n");
		scanf("%s",&novaPalavra);
		
		FILE* f;
		f = fopen("C:\\Users\\Pichau\\OneDrive\\�rea de Trabalho\\PRO C\\palavras.txt","r+");
		
		if(f == 0){
			printf("Erro ao adicinoar uma palavra!");
			exit(1);
		}
		
		
		int qtd;
		fscanf(f, "%i", &qtd);
		qtd++;
		
		fseek(f,0,SEEK_SET);
		fprintf(f, "%i",qtd);
		
		fseek(f,0,SEEK_END);
		fprintf(f, "\n%s",novaPalavra);
		
		fclose(f);
		
	}
	
}

void desenha(){
	int erros = chuteserrados();

printf("  _______       \n");
printf(" |/      |      \n");
printf(" |      %c%c%c  \n", (erros>=1?'(':' '), 
    (erros>=1?'_':' '), (erros>=1?')':' '));
printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), 
    (erros>=2?'|':' '), (erros>=3?'/': ' '));
printf(" |       %c     \n", (erros>=2?'|':' '));
printf(" |      %c %c   \n", (erros>=4?'/':' '), 
    (erros>=4?'\\':' '));
printf(" |              \n");
printf("_|___           \n");
printf("\n\n");
	
}


int main() {

    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();
		desenha();
    } while (!ganhou() && !enforcou());
    
    if(ganhou()){
    	
         printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");	
	}else{
		printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
	}
    
	adicionapalavra();

}
