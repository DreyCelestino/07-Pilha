#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* topo = NULL;

// headers
void menu();
void inicializar();
void pop();
void push();
void exibir();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 5) {
		system("cls"); // somente no windows
		cout << "Menu Pilha";
		cout << endl << endl;
		cout << "1 - Inicializar Pilha \n";
		cout << "2 - Inserir elemento (Push) \n";
		cout << "3 - Remover elementos (Pop) \n";
		cout << "4 - Exibir elementos" << endl;
		cout << "5 - Sair \n";


		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:push();
			break;
		case 3: pop();
			break;
		case 4: exibir();
			break;
		case 5:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = topo;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	topo = NULL;
	cout << "Pilha inicializada \n";


	//aqui ja estava funcionando, entao deixei quieto.
}


void push()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;


	NO* aux = topo;

	topo = novo;
	topo->prox = aux;
	
	cout << "Elemento " << topo->valor << " inserido na pilha." << endl;
	
}

void pop()
{
	NO* aux = topo;
	if (aux == NULL) {
		cout << "Lista vazia." << endl;
		return;
	}

	cout << aux->valor << " removido." << endl;
	topo = topo->prox;
	free(aux);

}

void exibir()
{
	NO* aux = topo;
	if (aux == NULL) {
		cout << "Lista vazia." << endl;
		return;
	}

	cout << "Conteudo da pilha" << endl;

	//esse primeiro é puramente pra ficar bonito, 
	//é possivel fazer so pelo while.
	cout << aux->valor;
	aux = aux->prox;

	while (aux != NULL) {
		cout << " -> " << aux->valor;
		aux = aux->prox;
	
	}
	cout << endl;
}
