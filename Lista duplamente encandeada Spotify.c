#include <stdio.h>
#include <stdlib.h>


typedef struct No{
   
    char * cantor;
    char * nome_musica;
    int tempo;
    
    //mecanismo p/ unir nos!
    struct No * prox;
    struct No * ant;
}NO;

NO * primeira = NULL;
NO * ultima = NULL;
int tam = 0;

void add_na_playlist(char *cantor, char *nome, int tempo){
    
        NO * novo = malloc(sizeof(NO));
        novo->cantor = cantor;
        novo->nome_musica = nome;
        novo->tempo = tempo;
        novo->prox = novo;
        novo->ant = novo; //NOVIDADE!
    
        if(primeira == NULL){ //playlist vazia
            primeira = novo;
            ultima = novo;
            tam++;
        }else{
            ultima->prox = novo;
            novo->ant = ultima;
            novo->prox = primeira;
            primeira->ant = novo;
            ultima = novo;
            tam++;
        }
    
}


void play_ordem(int num_vezes){
    NO * aux = primeira;
    for(int i = 0; i < num_vezes*tam; i++){
        printf("Cantor: %s\n", aux->cantor);
            aux = aux->prox;
    }
}

NO remove_na_playlist(char *cantor){
    
    
    if(tam == 1 && primeira->cantor == cantor){
        NO *lixo = primeira;
        primeira = NULL;
        ultima = NULL;
        free(lixo);
        tam--;
    }else{
        NO * aux = primeira;
        while(aux != ultima && aux->cantor != cantor){
            //OPERACAO DE CAMINHADA - MUITO IMPORTANTE
            aux = aux->prox;
        }
        if(aux->cantor == cantor){
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            if(primeira->cantor == cantor){
                primeira = primeira->prox;
            }
            if(ultima->cantor == cantor){
                ultima = ultima->prox;
            }
            free(aux);
            tam--;
        }else{
            printf("Não foi encontrado! \n");
        }
   }
}

int main(){

    add_na_playlist("Safadao", "Tatataramm", 200);
    add_na_playlist("Rossi", "Thururummm", 250);
    add_na_playlist("Exalta", "Lelerelereee", 320);
    add_na_playlist("Angra", "HHHAaarrraaa", 500);
    add_na_playlist("Alock", "Tutsturs", 300);
    printf("Impressao antes da remocao:\n");
    play_ordem(2);
    remove_na_playlist("Safadao");
    printf("Impressao depois da remocao:\n");
    play_ordem(1);
    return 0;
}




