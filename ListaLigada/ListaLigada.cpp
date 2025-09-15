#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* ponteiroParaProximoElementoDaLista;
};

NO* inicioDaLista = NULL;
NO* finalDaLista = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista j� possuir elementos
// libera a memoria ocupada
	NO* aux = inicioDaLista;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->ponteiroParaProximoElementoDaLista;
		free(paraExcluir);
	}

	inicioDaLista = NULL;
	finalDaLista = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = inicioDaLista;
	while (aux != NULL) {
		nElementos++;
		aux = aux->ponteiroParaProximoElementoDaLista;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (inicioDaLista == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = inicioDaLista;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->ponteiroParaProximoElementoDaLista;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o NovoElementoElemento elemento
	NO* NovoElemento = (NO*)malloc(sizeof(NO));
	if (NovoElemento == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> NovoElemento->valor;
	NovoElemento->ponteiroParaProximoElementoDaLista = NULL;

	if (inicioDaLista == NULL)
	{
		inicioDaLista = NovoElemento;
		finalDaLista = NovoElemento;
	}
	else
	{
		finalDaLista->ponteiroParaProximoElementoDaLista = NovoElemento;
		finalDaLista = NovoElemento;
	}
}

void excluirElemento()
{
	int valor;
	cout << "Qual numero quer excluir? " << endl;
	cin >> valor;

	NO* atual = inicioDaLista;
	NO* anterior = NULL;

	while(atual != NULL){
		if(atual->valor == valor){
			break;
		}
		anterior = atual;
		atual = atual->ponteiroParaProximoElementoDaLista;
	}

	if(atual == NULL) {
		cout << "Elemento nao encontrao" << endl;
		return;
	}
	if(anterior == NULL){
		inicioDaLista = inicioDaLista->ponteiroParaProximoElementoDaLista; 
	}else{
		anterior->ponteiroParaProximoElementoDaLista = atual->ponteiroParaProximoElementoDaLista;
	}
	if(atual == finalDaLista){
		finalDaLista = anterior;
	}
	free(atual);
	cout << "Elemento excluido" << endl;
	
}


void buscarElemento()
{
	int valor;
	cout << "Digite o numero" << endl;
	cin >> valor;
	
	if(posicaoElemento(valor) != NULL){
		cout << "Valor encontrado!" << endl;
		return; 
	} else 
	{
		cout << "Valor nao esta na lista" << endl;
		return;
	}	
}



// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento n�o estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = inicioDaLista;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->ponteiroParaProximoElementoDaLista;
	}
	return aux;
}

