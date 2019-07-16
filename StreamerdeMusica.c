/*----------------- File: ProjetoMusica.c  -------------------+
|Implementacao do projeto de musicas|	
		      		
|Implementado por Leslye Esteves Gomes em 09/07/2018|
+-------------------------------------------------------+*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct sartista{
	char Nome[30];
	char GeneroMusical[30];
	int QuantidadeAlbuns;	
	int numeroArtista;
}Artista;

typedef struct slista{
		Artista info;
		struct slista *ant;
		struct slista *prox;
}ListaArtista;

ListaArtista* criar_celulaA(){
		ListaArtista *nova;
		nova=(ListaArtista*)malloc(sizeof(ListaArtista));
		if(nova!=NULL){
			nova->ant=NULL;
			nova->prox=NULL;
		}
			return nova;
}

void inicializar_ListaArtista(ListaArtista **li){
		(*li)=NULL;

}

int vazia_ListaArtista(ListaArtista **li){
			if((*li)==NULL){
			return 1;
			}
			return 0;
}
typedef struct smusica{
	char NomeMusica[30];
	int DuracaoMin;
	char Compositor[30];
	char NomeAlbum[30];
	int numeroArtista;
	int numeroMusica;

}Musica;

typedef struct slistam{
		Musica info;
		struct slistam *ant;
		struct slistam *prox;
}ListaMusica;

ListaMusica* criar_celulaM(){
		ListaMusica *nova;
		nova=(ListaMusica*)malloc(sizeof(ListaMusica));
		if(nova!=NULL){
			nova->ant=NULL;
			nova->prox=NULL;
		}
			return nova;

}

void inicializar_ListaMusica(ListaMusica **m){
			(*m)=NULL;
}
int vazia_ListaMusica(ListaMusica **m){
			if((*m)==NULL){
			return 1;
			}
			return 0;
}
void preencherArtista(Artista *info){
    fflush(stdin);
    printf("Informe o nome do artista:\n");
    fflush(stdin);
    gets(info->Nome);
    printf("Informe o genero musical:\n");
    fflush(stdin);
    gets(info->GeneroMusical);
    printf("Informe a quantidade de albuns:\n");
    scanf("%d",&info->QuantidadeAlbuns);
}

int cadastrarArtista(ListaArtista **li, Artista info){
		ListaArtista *nova=criar_celulaA();
		nova->info=info;
		if(vazia_ListaArtista(li)){
			nova->info.numeroArtista=1;
			(*li)=nova;
			nova->prox=nova;
			nova->ant=nova;
			printf("Inserido com sucesso!\n");
			return 1;
	    }
		nova->info.numeroArtista=(*li)->info.numeroArtista+1;
		nova->prox=(*li)->prox;
		nova->ant=(*li);
		((*li)->prox)->ant=nova;
		(*li)->prox=nova;		
		(*li)=nova;
		printf("Inserido com sucesso!\n");
		return 1;
}

int imprimirArtistas(ListaArtista **li){
	if(vazia_ListaArtista(li)){
		printf("Nenhum artista cadastrado!\n");
		return 0;
	}
	
	ListaArtista *aux;
	aux=(*li)->prox;
	
	do{
		printf("%d Nome: %s\n",aux->info.numeroArtista,aux->info.Nome);
		printf("Genero Musical:%s\n",aux->info.GeneroMusical);
		printf("Quantdade de Albuns:%d\n",aux->info.QuantidadeAlbuns);
		printf("----------------------------------------------------\n");
		aux=aux->prox;
	}while(aux!=(*li)->prox);
		
		
}

int imprimirNumeroArtistas(ListaArtista **li){
	
	if(vazia_ListaArtista(li)){
		printf("Nenhum artista cadastrado!\n");
		return 0;
	}
	
	ListaArtista *aux;
	aux=(*li);
	
	do{
		aux=aux->prox;
		printf("%d-%s\n",aux->info.numeroArtista,aux->info.Nome);
	}while(aux!=(*li));
		
}

void preencherMusica(Musica *minfo,int nArtista){
    fflush(stdin);
    printf("Informe o nome da Musica:\n");
    fflush(stdin);
    gets(minfo->NomeMusica);
    printf("Informe a duracao da musica em minutos:\n");
    scanf("%d",&minfo->DuracaoMin);
    printf("Informe o compositor:\n");
    fflush(stdin);
    gets(minfo->Compositor);
    printf("Informe o nome do album:\n");
    fflush(stdin);
    gets(minfo->NomeAlbum);
    minfo->numeroArtista=nArtista;
}

int cadastrarMusicas(ListaMusica **m, Musica minfo){
	ListaMusica *nova=criar_celulaM();
	nova->info=minfo;
	if(vazia_ListaMusica(m)){
		nova->info.numeroMusica=1;
		(*m)=nova;
		nova->prox=nova;
		nova->prox=nova;		
		return 1;
	}
	nova->info.numeroMusica=(*m)->info.numeroMusica+1;
	nova->prox=(*m)->prox;
	nova->ant=(*m);
	((*m)->prox)->ant=nova;
	(*m)->prox=nova;
	(*m)=nova;
	
	return 1;	
}

int atualizarArtista(ListaArtista **li, int nArtista){
	Artista info;
	if(vazia_ListaArtista(li)){
		printf("Nenhum artista encontrado!\n");
		return 0;
	}
	
	ListaArtista *aux;
	aux=(*li);
	do{
		aux=aux->prox;
	}while(aux->info.numeroArtista!=nArtista);	
	
	fflush(stdin);
    printf("Informe o nome do artista:\n");
    fflush(stdin);
    gets(info.Nome);
    printf("Informe o genero musical:\n");
    fflush(stdin);
    gets(info.GeneroMusical);
    printf("Informe a quantidade de albuns:\n");
    scanf("%d",&info.QuantidadeAlbuns);
    
    strcpy(aux->info.GeneroMusical,info.GeneroMusical);
    strcpy(aux->info.Nome,info.Nome);
    aux->info.QuantidadeAlbuns=info.QuantidadeAlbuns;
}


int atualizarMusica(ListaMusica **m, int nMusica){
	Musica info;
	if(vazia_ListaMusica(m)){
		printf("Nenhuma musica encontrada!\n");
		return 0;
	}
	
	ListaMusica *aux;
	aux=(*m);
	
	do{
		aux=aux->prox;
	}while(aux->info.numeroMusica!=nMusica);	
	
	fflush(stdin);
    printf("Informe o Novo nome da  Musica:\n");
    fflush(stdin);
    gets(info.NomeMusica);
    printf("Informe o Compositor:\n");
    fflush(stdin);
    gets(info.Compositor);
    printf("Informe a Duracao da Musica:\n");
    scanf("%d",&info.DuracaoMin);
    fflush(stdin);
    printf("Digite o nome do album\n");
    gets(info.NomeAlbum);
    printf("Musica Atualizada com sucesso!\n");
    
    strcpy(aux->info.Compositor,info.Compositor);
    strcpy(aux->info.NomeAlbum,info.NomeAlbum);
    strcpy(aux->info.NomeMusica,info.NomeMusica);
	aux->info.DuracaoMin=info.DuracaoMin;
}

int imprimirMusicas(ListaMusica **m, ListaArtista **li){
	
	if(vazia_ListaMusica(m)){
		printf("Nenhuma musica cadastrada!\n");
		return 0;
	}
	
	ListaArtista *aux2;
	aux2=(*li)->prox;
	
	ListaMusica *aux;
	aux=(*m)->prox;
	
	
	
	do{
		printf("Nome: %s\n",aux->info.NomeMusica);
		printf("Album: %s\n",aux->info.NomeAlbum);
		printf("Compositor: %s\n",aux->info.Compositor);
		printf("Duracao: %d \n",aux->info.DuracaoMin);
		while(aux->info.numeroArtista!=aux2->info.numeroArtista){
			aux2=aux2->prox;
		}
		printf("Cantor: %s \n",aux2->info.Nome);
		printf("----------------------------------------------------\n");
		aux=aux->prox;
	}while(aux!=(*m)->prox);

	return 0;
		
}

int imprimirNumeroMusicas(ListaMusica **m, ListaArtista **li){
	
	ListaArtista *aux2;
	aux2=(*li)->prox;
	
	ListaMusica *aux;
	aux=(*m)->prox;
	
	if(vazia_ListaMusica(m)){
		printf("Nenhuma musica cadastrada!");
		return 0;
	}

	do{
		printf("Numero da musica %d",aux->info.numeroMusica);
		printf("- Nome: %s\n",aux->info.NomeMusica);
		while(aux->info.numeroArtista!=aux2->info.numeroArtista){
			aux2=aux2->prox;
		}
		printf("Cantor: %s \n",aux2->info.Nome);	
		printf("----------------------------------------------------\n");
		aux=aux->prox;
	
	}while(aux!=(*m)->prox);
	
	return 0;
}

int removerMusicaPeloArtista(ListaMusica **m, int nArtista){
	ListaMusica *aux;
	aux=(*m);
	
	if(vazia_ListaMusica(m)){
		printf("Nenhuma musica cadastrada!");
		return 0;
	}
	
	do{
		if(aux->info.numeroArtista==nArtista){
			if(aux==(*m)){
				((*m)->ant)->prox=(*m)->prox;
				((*m)->prox)->ant=(*m)->ant;
				(*m)=(*m)->ant;
				free(aux);
				printf("Removido com sucesso!\n");
			}else if(aux==(*m)->prox){
				(aux->prox)->ant=(*m);
				(*m)->prox=aux->prox;
				free(aux);	
				printf("Removido com sucesso!\n");
			}else
				(aux->ant)->prox=aux->prox;
				(aux->prox)->ant=aux->ant;
				free(aux);
				printf("Removido com sucesso!\n");
			}
			
		aux=aux->prox;
	}while(aux!=(*m));
}	

int removerArtista(ListaArtista **li, ListaMusica **m, int nArtista){
	
	if(vazia_ListaArtista(li)){
		printf("Nenhum Artista Cadastrado\n");
		return 0;
	}	
	
	ListaArtista *aux;
	aux=(*li);
	
	if(aux->prox==aux){
		(*li)=NULL;
		(*m)=NULL;
		printf("Removido com sucesso\n");
		return 1;
	}
	
	do{
		if(aux->info.numeroArtista==nArtista){
			printf("primeiro if\n");
			if(aux==(*li)){
				((*li)->ant)->prox=(*li)->prox;
				((*li)->prox)->ant=(*li)->ant;
				(*li)=(*li)->ant;
				free(aux);
				removerMusicaPeloArtista(m, nArtista);
				printf("Removido com sucesso!\n");
				return 1;
			}else if(aux==(*li)->prox){
				(aux->prox)->ant=(*li);
				(*li)->prox=aux->prox;
				free(aux);	
				removerMusicaPeloArtista(m, nArtista);
				printf("Removido com sucesso!\n");
				return 1;
			}else
				(aux->ant)->prox=aux->prox;
				(aux->prox)->ant=aux->ant;
				free(aux);
				removerMusicaPeloArtista(m, nArtista);
				printf("Removido com sucesso!\n");
				return 1;
			}
		aux=aux->prox;
 	}while(aux!=(*li));
	return 0;
}
int removerMusicas(ListaMusica **m, int nMusica){
	
	ListaMusica *aux;
	aux=(*m);
	if(vazia_ListaMusica(m)){
		printf("Nenhuma musica adicionada!\n");
		return 0;
	}
	
	do{
		aux=aux->prox;
	}while(nMusica!=aux->info.numeroMusica);
	
	if(aux==(*m)){
		((*m)->ant)->prox=(*m)->prox;
		((*m)->prox)->ant=(*m)->ant;
		(*m)=(*m)->ant;
		free(aux);				
	}else if(aux==(*m)->prox){
		(aux->prox)->ant=(*m);
		(*m)->prox=aux->prox;
		free(aux);
	}
	else{
		(aux->ant)->prox=aux->prox;
		(aux->prox)->ant=aux->ant;
		free(aux);
	}
	return 1;
}

int pesquisarArtista(ListaArtista **li, ListaMusica **m){
	if(vazia_ListaArtista(li)){
		printf("Nenhum artista encontrado!\n");
		return 0;
	}
	
	char Artista[30];
	ListaArtista *aux;
	ListaMusica *aux2;
	aux=(*li);
	aux2=(*m);
	printf("Informe o nome do artista:\n");
	fflush(stdin);
	gets(Artista);
	if(strcmp(Artista,aux->info.Nome)==0){
		printf("Nome:%s\n",aux->info.Nome);
		printf("Genero Musical:%s\n",aux->info.GeneroMusical);
		printf("Quantidade de Albuns:%d\n",aux->info.QuantidadeAlbuns);		
		do{
			if(aux->info.numeroArtista==aux2->info.numeroArtista){
				printf("Nome %s \n",aux2->info.NomeMusica);		
				printf("Compositor %s \n",aux2->info.Compositor);
				printf("Duracao %d \n",aux2->info.DuracaoMin);
				printf("Nome Album %s \n",aux2->info.NomeAlbum);
				printf("----------------------------- \n");
			}
			aux2=aux2->prox;
		}while(aux2!=(*m));		
		return 1;
	}
	
	aux=aux->prox;
	
	while(aux!=(*li)){
		if(strcmp(Artista,aux->info.Nome)==0){
			printf("Nome:%s\n",aux->info.Nome);
			printf("Genero Musical:%s\n",aux->info.GeneroMusical);
			printf("Quantidade de Albuns:%d\n",aux->info.QuantidadeAlbuns);		
			do{
				if(aux->info.numeroArtista==aux2->info.numeroArtista){
					printf("Nome %s \n",aux2->info.NomeMusica);		
					printf("Compositor %s \n",aux2->info.Compositor);
					printf("Duracao %d \n",aux2->info.DuracaoMin);
					printf("Nome Album %s \n",aux2->info.NomeAlbum);
					printf("----------------------------- \n");
					system("pause");
				}
				aux2=aux2->prox;
			}while(aux2!=(*m));		
			return 1;
		}
		aux=aux->prox;
	}		
	printf("Opcao Invalida!\n");
	return 0;
}

int pesquisarMusica(ListaMusica **m){
	if(vazia_ListaMusica(m)){
		printf("Nenhuma musica encontrada!\n");
		return 0;
	}
	char Musica[30];
	ListaMusica *aux;
	aux=(*m);
	printf("Informe o nome da Musica:\n");
	fflush(stdin);
	gets(Musica);
	
	if(strcmp(Musica,aux->info.NomeMusica)==0){
		printf("Nome %s \n",aux->info.NomeMusica);		
		printf("Compositor %s \n",aux->info.Compositor);
		printf("Duracao %d \n",aux->info.DuracaoMin);
		printf("Nome Album %s \n",aux->info.NomeAlbum);
		printf("----------------------------- \n");
		return 1;
	}
	
	aux=aux->prox;
	
	while(aux!=(*m)){
		if(strcmp(Musica,aux->info.NomeMusica)==0){
			printf("Nome: %s \n",aux->info.NomeMusica);		
			printf("Compositor: %s \n",aux->info.Compositor);
			printf("Duracao %d \n",aux->info.DuracaoMin);
			printf("Nome Album: %s \n",aux->info.NomeAlbum);
			printf("----------------------------- \n");
			return 1;
		}
		aux=aux->prox;
	}
	printf("Musica nao encontrada\n");
	return 0;
	
}

int verificaArtista(ListaArtista **li, int nArtista){
	ListaArtista *aux;
	aux=(*li);
	
	if(vazia_ListaArtista(li)){
		printf("Nenhum artista encontrado!\n");
		return 0;
	}
	if((aux->prox==aux)&&(nArtista==aux->info.numeroArtista)){
		return 1;
	}
	
	aux=aux->prox;
	do{
		if(nArtista==aux->info.numeroArtista){
			return 1;
		}
		aux=aux->prox;
	}while(aux->prox!=(*li));
	
	return 0;
}

int verificaMusica(ListaMusica **m, int nMusica){
	ListaMusica *aux;
	aux=(*m);
	
	if(vazia_ListaMusica(m)){
		printf("Nenhuma musica encontrada!\n");
		return 0;
	}
	
	if((aux->prox==aux)&&(nMusica==aux->info.numeroMusica)){
		return 1;
	}
	aux=aux->prox;
	do{
		if(nMusica==aux->info.numeroMusica){
			return 1;
		}
		aux=aux->prox;
	}while(aux->prox!=(*m));
	
	return 0;
}

void menu(){
		printf("--------------------MENU-----------------------\n");
		printf("[1]Cadastrar Artistas.\n");
		printf("[2]Remover Artistas.\n");
		printf("[3]Atualizar Artistas.\n");
		printf("[4]Cadastrar Musicas.\n");
		printf("[5]Remover Musicas.\n");
		printf("[6]Atualizar Musicas.\n");
		printf("[7]Pesquisar Artista.\n");
		printf("[8]Pesquisar Musicas.\n");
		printf("[9]Exibir todos os artistas adicionados.\n");
		printf("[10]Exibir todas as musicas.\n");
		printf("[11]Sair...\n");
		printf("------------------------------------------------\n");
}

int main(){
	int resp;
	int nMusica;
	int nArtista;
	Artista info;
	Musica minfo;
    ListaArtista *li=(ListaArtista*)malloc(sizeof(ListaArtista));
    inicializar_ListaArtista(&li);
    ListaMusica *m=(ListaMusica*)malloc(sizeof(ListaMusica));
    inicializar_ListaMusica(&m);
    
    
	do{
		menu();
		fflush(stdin);
		scanf("%d",&resp);
		
		switch(resp){
			case 1:
				system("cls");
				preencherArtista(&info);
				cadastrarArtista(&li,info);
				system("pause");
			break;
			
			case 2:
				system("cls");
				if(vazia_ListaArtista(&li)){
					printf("Nenhum artista cadastrado\n");
					system("pause");
					break;
				}
				imprimirNumeroArtistas(&li);
				printf("Informe o numero do artista:\n");
				scanf("%d",&nArtista);
				if(verificaArtista(&li,nArtista)==1){
					removerArtista(&li,&m,nArtista);	
					system("pause");
					break;
				}
				printf("Opcao Invalida!\n");
				system("pause");
			break;
			
			case 3:
				system("cls");
				imprimirNumeroArtistas(&li);
				printf("Informe o numero do artista:\n");
				scanf("%d",&nArtista);
				if(verificaArtista(&li,nArtista)==1){
					atualizarArtista(&li,nArtista);
					system("pause");
					break;
				}
				printf("Opcao Invalida\n");
				system("pause");
			break;
			
			case 4:
				system("cls");
				imprimirNumeroArtistas(&li);
				printf("Informe o numero do artista:\n");
				scanf("%d",&nArtista);
				if(verificaArtista(&li,nArtista)==1){
					preencherMusica(&minfo,nArtista);
					cadastrarMusicas(&m,minfo);
					system("pause");
					break;
				}
				printf("Opcao Invalida!\n");
				system("pause");
			break;
			
			case 5:
				system("cls");
				imprimirNumeroMusicas(&m,&li);
				printf("Informe o numero da musica:\n");
				scanf("%d",&nMusica);
				if(verificaMusica(&m,nMusica)==1){
					removerMusicas(&m,nMusica);
					system("pause");
					break;
				}
				printf("Opcao Invalida\n");
			break;
			
			case 6:
				system("cls");
				imprimirNumeroMusicas(&m,&li);
				printf("Informe o numero da musica:\n");
				scanf("%d",&nMusica);
				if(verificaMusica(&m,nMusica)==1){
					atualizarMusica(&m,nMusica);
					system("pause");
					break;
				}
				system("pause");
			break;
			
			case 7:
				system("cls");
				pesquisarArtista(&li,&m);
				system("pause");
			break;
			
			case 8:
				system("cls");
				pesquisarMusica(&m);
				system("pause");
			break;
			
			case 9:
				system("cls");
				imprimirArtistas(&li);
				system("pause");
			break;
			
			case 10:
				system("cls");
				imprimirMusicas(&m,&li);
				system("pause");
			break;
			
			case 11:
				system("cls");
				printf("Saindo..\n");
				return 0;
			break;	

			default:
				printf("Informe um valor valido!\n\n");
				system("pause");
			break;
		}
		system("cls");
	}while(resp!=11);
	return 0;	
}
