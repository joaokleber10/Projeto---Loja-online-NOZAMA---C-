#include <iostream>
#include <iomanip>
using namespace std;

struct Item{
    double preco;
    int quant;
    string nome;
};

struct Nopilha{
    Item* produto;
    Nopilha* prox;
};
//implementação do historico de compras--------------------------------
struct Nolista{
    double valor_compra;
    int quantidade_itens;
    Nolista* prox;
    Nolista* ant;
};

struct Descritor{
    int tamanho;
    Nolista* ini;
    Nolista* fim;
};

Descritor* criar_lista(){
    Descritor* d = new Descritor;
    d->tamanho = 0;
    d->ini = NULL;
    d->fim = NULL;
    return d;
}

void print(Nolista* lista,int cont){
    if(lista != NULL){
        cout << "Compra [" << cont << "] quantidade de itens: " << lista->quantidade_itens << endl << "Compra [" << cont << "] total da compra: R$" << lista->valor_compra << "\n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n";
        print(lista->prox,cont+1);
    }
}

void append(Descritor* lista,double valor,int quant){
    Nolista* novo = new Nolista;
    novo->valor_compra = valor;
    novo->quantidade_itens = quant;
    novo->prox = NULL;
    novo->ant = NULL;
    if(lista->ini == NULL){
        lista->ini = novo;
        lista->fim = novo;
        lista->tamanho++;
    }else{
        Nolista* p = lista->ini;
        while(p->prox != NULL){
            p = p->prox;
        }
        p->prox = novo;
        novo->ant = p;
        lista->tamanho++;
        lista->fim = novo;
    }
}

//fim das implementações do historico de compras

//função para iniciar a pilha apontada para NULL
Nopilha* criar_Nopilha(){
    return NULL;
}

//função para verificar se a pilha está vazia
bool isempty(Nopilha* carrinho){
    return(carrinho == NULL);
}

//função para adcionar produto no carrinho, produto será sempre adcionado ao topo da pilha
void adcionar_produto(Nopilha*& carrinho,Item* produto){
    Nopilha* novo = new Nopilha;
    novo -> produto = produto;

    //adcionar novo Nopilha no topo
    novo -> prox = carrinho;
    carrinho = novo;
}

//função para remover ultimo produto adcionado ao carrinho e retornar ele
Nopilha* remover_produto(Nopilha*& carrinho){
    if(isempty(carrinho)){
        return NULL;
    }else{
        Nopilha* p = carrinho;
        carrinho = carrinho -> prox;
        return p;
    }
}

void ver_carrinho(Nopilha* carrinho,int cont){
    if(!isempty(carrinho)){
        cout << "["<< cont << "] - "<< carrinho->produto->nome << " - R$" << carrinho->produto->preco << " - " << carrinho->produto->quant << " unidade(s)\n";
        ver_carrinho(carrinho->prox,cont+1);
    }
}

//função para retorna produto preço e quantidade
void nozama(Nopilha*& carrinho,double preco,int quant,string nome){
    Item* produto = new Item;
    produto -> preco = preco;
    produto -> quant = quant;
    produto -> nome = nome;
    adcionar_produto(carrinho,produto);
}
void finalizar_compra(Nopilha* carrinho, Descritor* historico){
    double soma = 0;
    int quantidade_total = 0;
if(carrinho == NULL){
	cout << "Nenhum produto adicionado :( ";
} else{
    pagamento:
    double soma = 0;
    system("cls");
    cout << " -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n RESUMO DA COMPRA \n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "Produtos: \n";
    ver_carrinho(carrinho,1);
    Nopilha *aux = carrinho;
       while(aux != NULL){
        soma += aux->produto->preco * aux->produto->quant;
        quantidade_total += aux->produto->quant;
        aux = aux->prox;
    }
    cout << " -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "O valor total: R$" << soma << endl;
    cout << " -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << " Forma de pagamento: \n [1] Cartao de credito \n [2] Cartao de debito \n [3] Boleto \n [4] Pix \n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n > ";
    char opc;
    cin >> opc;
    switch(opc){
        case '1':
            cout << "CARTAO DE CREDITO\n";
            cout << " -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            cout << "Deseja dividir em quantas parcelas? \n> ";
            int parcelas;
            cin >> parcelas;
            cout << "ATENCAO:\nParcelamos em ate 12x\n A cada parcela sera acrescentado 5% do valor total\n";
            if (parcelas > 12 || parcelas < 1 || parcelas == 0){
                cout << "Numero de parcelas invalido\n";
                system ("pause");
                goto pagamento;
            }
            cout << " -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            cout << fixed << setprecision(2);
            cout << "Voce escolheu pagar em " << parcelas << "x de R$" << (soma/parcelas) + ((soma/parcelas)*0.05) << endl;
            system("pause");
            break;
        case '2':
            cout << "CARTAO DE DEBITO\nEm breve voce recebera um email com o comprovante de pagamento :)\n";
            system("pause");
            break;
        case '3':
            cout << "BOLETO\n";
            cout << "O boleto foi enviado para o seu email\nVoce tem 3 dias ate o vencimento :)\n";
            system("pause");
            break;
        case '4':
            cout << "PIX\nO codigo do pix foi enviado para o seu email\nVoce tem 30 minutos para pagar o pix :)\n";
            system("pause");
            break;
        default:
            cout << "Opcao invalida";
            system ("pause");
            goto pagamento;
    }

    cout << " -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "Obrigado por comprar na Nozama! :D \n";
    append(historico,soma,quantidade_total);
}
}

// FUNÇÃO PARA A ESCOLHA DOS PRODUTOS
void menu(Nopilha* carrinho,Descritor* historico){
// QUANTIDADE DOS PRODUTOS
    int quantidade_max_notebook = 20;
    int quantidade_max_celular = 150;
    int quantidade_max_videogame = 35;
    int quantidade_max_televisao = 200;
    int quantidade_max_geladeira = 45;
    int quantidade_max_fogao = 17;
    int quantidade_max_microondas = 60;
    int quantidade_max_maquina = 25;
    int quantidade_max_arroz = 100;
    int quantidade_max_feijao = 200;
    int quantidade_max_macarrao = 500;
    int quantidade_max_carne = 350;
    int quantidade_max_camiseta = 200;
    int quantidade_max_calca = 20;
    int quantidade_max_casaco = 2;
    int quantidade_max_sapato = 200;
    int quantidade_max_livro1 = 30;
    int quantidade_max_livro2 = 10;
    int quantidade_max_livro3 = 50;
    int quantidade_max_livro4 = 1;

// FUNÇÃO PARA A ESCOLHA DOS PRODUTOS
    string email;
    char remove;
    char opc,opc2;
    string tamanho;
    int quant;
    string nome;
    inicio:
    system("cls");
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\nSEJA BEM-VINDO A NOZAMA! \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "CATEGORIA DE PRODUTOS DISPONIVEIS \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << " [1] Eletronicos \n [2] Eletrodomesticos \n [3] Alimentos \n [4] vestuario \n [5] Livros \n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n [6] Carrinho de compras \n [7] Finalizar compra \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n > ";
    cin >> opc;
    switch(opc){
    case '1':
        cout << "\n *** OFERTAS DO DIA! ***\n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << " [1] Notebook UltraBook 15 - R$2000 \n [2] Celular UIphone 26 - R$1200 \n [3] Videogame Station Play 5 - R$2200 \n [4] Televisao Mansung Smart 4K - R$2500 \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n > ";
        cin >> opc2;
        switch(opc2){
        case '1':
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: "<< quantidade_max_notebook << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_notebook){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_notebook == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                } else{
            nozama(carrinho,2000,quant,"notebook UltraBook 15");
            cout << "Produto adicionado com sucesso!\n";
            quantidade_max_notebook -= quant;
            system ("pause");
            goto inicio;}
        case '2':
            cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: " << quantidade_max_celular << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_celular){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_celular== 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                } else{
            nozama(carrinho,1200,quant,"celular UIphone 26");
            cout << "Produto adicionado com sucesso!\n";
            quantidade_max_celular -= quant; 
            system ("pause");
            goto inicio;}
        case '3':
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: " << quantidade_max_videogame << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_videogame){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_videogame == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                } else{
            nozama(carrinho,2200,quant,"videogame Station Play 5");
            cout << "Produto adicionado com sucesso!\n";
            quantidade_max_videogame -= quant;
            system ("pause");
            goto inicio;}
        case '4':
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: " << quantidade_max_televisao << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_televisao){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
            if(quantidade_max_televisao == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                } else{
            nozama(carrinho,2500,quant,"televisao Mansung Smart 4K");
            cout << "Produto adicionado com sucesso!\n";
            quantidade_max_televisao -= quant;
            system ("pause");
            goto inicio;}
        
        default:
            cout << "Opcao invalida\n";
            cout << "Deseja finalizar a compra? [S] [N] \n";
                cin >> opc2;
                if(opc2 == 'S'|| opc2 == 's'){
                    //chamar função de finalizar compra
                    finalizar_compra(carrinho,historico);
                    system ("pause");
                    goto inicio;
	            }else{
	                	goto inicio;
					};
        
}
    case '2':
        cout << "\n *** OFERTAS DO DIA! ***\n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << " [1] Geladeira R$2000 \n [2] Fogao R$1200 \n [3] Microondas R$2200 \n [4] Maquina de lavar R$2500 \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n >  ";
        cin >> opc2;
        switch(opc2){
            case '1':
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: " << quantidade_max_geladeira << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";;
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_geladeira){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_geladeira == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                } else{
                nozama(carrinho,2000,quant,"geladeira");
                cout << "Produto adicionado com sucesso!\n";
                quantidade_max_geladeira -= quant;
                system ("pause");
                goto inicio;}
            case '2':
                 cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: " << quantidade_max_fogao << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_fogao){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_fogao == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                } else{
                nozama(carrinho,1200,quant,"fogao");
                cout << "Produto adicionado com sucesso!\n";
                quantidade_max_fogao -= quant;
                system ("pause");
                goto inicio;}
            case '3':
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: " << quantidade_max_microondas << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_microondas){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_microondas == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                } else{
                nozama(carrinho,2200,quant,"microondas");
                cout << "Produto adicionado com sucesso!\n";
                system ("pause");
                quantidade_max_microondas -= quant;
                goto inicio;}
            case '4':
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: " << quantidade_max_maquina <<"\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"; 
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_maquina){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_maquina == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                } else{
                nozama(carrinho,2500,quant,"maquina de lavar");
                cout << "Produto adicionado com sucesso!\n";
                quantidade_max_maquina -= quant;
                system ("pause");
                goto inicio;}
            default: 
                cout << "Opcao invalida\n";
                cout << "Deseja finalizar a compra? [S] [N] \n";
                cin >> opc2;
                if(opc2 == 'S'|| opc2 == 's'){
                    //chamar função de finalizar compra
                    finalizar_compra(carrinho,historico);
                    system ("pause");
                    goto inicio;
	            }else{
	                	goto inicio;
					};
        }
    case '3':
        cout << "\n *** OFERTAS DO DIA! ***\n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << " [1] Arroz R$10 \n [2] Feijao R$5 \n [3] Macarrao R$3 \n [4] Carne R$20 \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n >  ";
        cin >> opc2;
        switch(opc2){
            case '1':
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: "<< quantidade_max_arroz << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_arroz){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_arroz == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                } else{
                nozama(carrinho,10,quant,"arroz");
                cout << "Produto adicionado com sucesso!\n";
                quantidade_max_arroz -= quant;
                system ("pause");
                goto inicio;}
            case '2':
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: "<< quantidade_max_feijao << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_feijao){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_feijao == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                } else{
                nozama(carrinho,5,quant,"feijao");
                cout << "Produto adicionado com sucesso!\n";
                quantidade_max_feijao -= quant;
                system ("pause");
                goto inicio;}
            case '3':
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: "<< quantidade_max_macarrao << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_macarrao){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_macarrao == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                } else{
                nozama(carrinho,3,quant,"macarrao");
                cout << "Produto adicionado com sucesso!\n";
                quantidade_max_macarrao -= quant;
                system ("pause");
                goto inicio;}
            case '4':
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: " << quantidade_max_carne << "Kg\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade (Kg): ";
                cin >> quant;
                while(quant > quantidade_max_carne){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_carne == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                } else{
                    nozama(carrinho,20,quant,"carne");
                    cout << "Produto adicionado com sucesso!\n";
                    quantidade_max_carne -= quant;
                    system ("pause");
                    goto inicio;}
            default:
                cout << "Opcao invalida\n";
                cout << "Deseja finalizar a compra? [S] [N] \n";
                cin >> opc2;
                if(opc2 == 'S'|| opc2 == 's'){
                    //chamar função de finalizar compra
                    finalizar_compra(carrinho,historico);
                    system ("pause");
                    goto inicio;
	            }else{
	                	goto inicio;
					};
        }
    case '4':
        cout << "\n *** OFERTAS DO DIA! ***\n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << " [1] Camiseta R$100 \n [2] Calca R$50 \n [3] Casaco R$300 \n [4] Sapato R$250 \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n >  ";
        cin >> opc2;
        
        switch(opc2){
            case '1':
            	cout << "Tamanhos disponiveis: [P] [M] [GG]\n > ";
            	cin >> tamanho;
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                while(tamanho != "P" && tamanho != "M" && tamanho != "GG"){
                	cout << "Tamanho invalido, digite novamente: ";
                	cin >> tamanho;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                cout << "Quantidade disponivel: "<< quantidade_max_camiseta << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_camiseta){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_camiseta == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                } else{
                        nozama(carrinho,100,quant,"camiseta");
                        cout << "Produto adicionado com sucesso!\n";
                        quantidade_max_camiseta -= quant;
                        system ("pause");
                        goto inicio;
                }
            case '2':
            	cout << "Tamanhos disponiveis: [37] [39] [42]\n > ";
            	cin >> tamanho;
                while(tamanho != "37" && tamanho != "39" && tamanho != "42"){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                    cout << "Tamanho invalido, digite novamente: ";
                    cin >> tamanho;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }                       
                cout << "Quantidade disponivel: " << quantidade_max_calca << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_calca){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_calca == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;}
                else{
                    nozama(carrinho,50,quant,"calca");
                    cout << "Produto adicionado com sucesso!\n";
                    quantidade_max_calca -= quant;
                    system ("pause");
                    goto inicio;
                }
            case '3':
                cout << "Tamanhos disponiveis: [P] [M] [G]\n > ";
            	cin >> tamanho;
                while(tamanho != "P" && tamanho != "M" && tamanho != "G"){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                    cout << "Tamanho invalido, digite novamente: ";
                    cin >> tamanho;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                cout << "Quantidade disponivel: "<< quantidade_max_casaco << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_casaco){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                 if(quantidade_max_casaco == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                    }
                    else{
                        nozama(carrinho,300,quant,"casaco");
                        cout << "Produto adicionado com sucesso!\n";
                        quantidade_max_casaco -= quant;
                        system ("pause");
                        goto inicio;
                    }
            case '4':
                cout << "Tamanhos disponiveis: [36] [37] [39] [40] [42] [44]\n > ";
                cin >> tamanho;
                while(tamanho != "36" && tamanho != "37" && tamanho != "39" && tamanho != "40" && tamanho != "42" && tamanho != "44"){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                    cout << "Tamanho invalido, digite novamente: ";
                    cin >> tamanho;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                 cout << "Quantidade disponivel: "<< quantidade_max_sapato << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_sapato){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                } if(quantidade_max_sapato == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                    }
                    else{
                        nozama(carrinho,250,quant,"sapato");
                        cout << "Produto adicionado com sucesso!\n";
                        quantidade_max_sapato -= quant;
                        system ("pause");
                        goto inicio;
                    }
            default:
                cout << "Opcao invalida\n";
                cout << "Deseja finalizar a compra? [S] [N] \n";
                cin >> opc2;
                if(opc2 == 'S'|| opc2 == 's'){
                    //chamar função de finalizar compra
                    finalizar_compra(carrinho,historico);
                    system ("pause");
                    goto inicio;
	            }else{
	                	goto inicio;
					};
        }
    case '5':
        cout << "\n *** OFERTAS DO DIA! ***\n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << " [1] Para todos os garotos que ja matei R$12,50 \n [2] As trancas do rei careca (VOL 1) - R$50 \n [3] A volta dos que nao foram - R$36,90 \n [4] Seneca: Como ser pai de menina R$19,90 \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n >  ";
        cin >> opc2;
        switch(opc2){
            case '1':
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: "<< quantidade_max_livro1 << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_livro1){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                 if(quantidade_max_livro1 == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                    }
                else{
                        nozama(carrinho,12.50,quant,"Para todos os garotos que ja matei");
                        cout << "Produto adicionado com sucesso!\n";
                        quantidade_max_livro1 -= quant;
                        system ("pause");
                        goto inicio;
                    }
            case '2':
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: "<< quantidade_max_livro2 << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_livro2){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_livro2 == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;;
                    }
                	    else{
                            nozama(carrinho,50,quant,"As trancas do rei careca (VOL 1)");
                            cout << "Produto adicionado com sucesso!\n";
                            quantidade_max_livro2 -= quant;
                            system ("pause");
                            goto inicio;
            case '3':
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: "<< quantidade_max_livro3 << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_livro3){
                	cout << "Quantidade maxima excedida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 1){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_livro3 == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                    }
                	    else{
                            nozama(carrinho,36.90,quant,"A volta dos que nao foram");
                            cout << "Produto adicionado com sucesso!\n";
                            quantidade_max_livro3 -= quant;
                            system ("pause");
                            goto inicio;
                	    }   
            case '4':
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade disponivel: "<< quantidade_max_livro4 << "\n";
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Quantidade: ";
                cin >> quant;
                while(quant > quantidade_max_livro4){
                        cout << "Quantidade maxima excedida, digite novamente: ";
                        cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                while (quant < 0){
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                	cout << "Quantidade invalida, digite novamente: ";
                	cin >> quant;
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                }
                if(quantidade_max_livro4 == 0){
                        cout << "Todos foram vendidos :(\nDeixe seu email para receber um aviso quando o produto estiver disponivel novamente: ";
                        cin >> email;
                        cout << "\nObrigado! :D\n";
                        system("pause");
                        goto inicio;
                    }
                	    else{
                            nozama(carrinho,19.90,quant,"Seneca: Como ser pai de menina");
                	        cout << "Produto adicionado com sucesso!\n";
                	        quantidade_max_livro4 -= quant;
                            system ("pause");
                            goto inicio;
                        }
            default:
                cout << "Opcao invalida\n";
                cout << "Deseja finalizar a compra? [S] [N] \n";
                cin >> opc2;
                if(opc2 == 'S'|| opc2 == 's'){
                    //chamar função de finalizar compra
                    finalizar_compra(carrinho,historico);
                    system ("pause");
                    goto inicio;
	            }else{
	                	goto inicio;
					};
                        }
                }
    case '6':
        system("cls");
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n CARRINHO DE COMPRAS \n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        if(carrinho == NULL){
        	cout << "Nenhum produto adicionado :( \n";
        } else{
        ver_carrinho(carrinho,1);
        }
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << "Deseja cancelar o carrinho? [S] [N]\n >";
        cin >> remove;
            if(remove == 'S' || remove == 's'){
             carrinho = NULL;
             goto inicio;
            }
            else{
                goto inicio;          
              }
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
	case '7':
        //chamar função de finalizar compra
        finalizar_compra(carrinho,historico);
        break;
    default:
        cout << "Opcao invalida\n";
        system("pause");
        goto inicio;
    
}
}

void usuario(){
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    string usuario, senha_teste, login, senha_real, senha_novamente;
    cout << "Bem vindo a Nozama!\nPara iniciar, crie um usuario e uma senha.\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n>> Usuario: ";
    cin >> usuario;
    cout << ">> Crie uma senha: ";
    cin >> senha_teste;
    cout << ">> Digite a senha novamente: ";
    cin >> senha_novamente;
    while(senha_teste != senha_novamente){
    	system("cls");
    	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-==-=-=-=-=\n";
    	cout << "** As senhas estao diferentes, digite novamente **\n";
    	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-==-=-=-=-=\n";
    	cout << ">> Crie uma senha: ";
    	cin >> senha_teste;
    	cout << ">> Digite a senha novamente: ";
    	cin >> senha_novamente;
    	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
	}
    system("cls");
    cout << "-=-=-=-=-=-=-=-=- LOGIN -=-=-=-=-=-=-=-=-" << endl;
    cout << ">> Usuario: ";
    cin >> login;
    cout << ">> Senha: ";
    cin >> senha_real;
    while(login != usuario or senha_real != senha_teste){
        system("cls");
        cout << ">> Usuario ou senha incorretos, por favor, tente novamente\n";
        cout << ">> Usuario: ";
        cin >> login;
        cout << ">> Senha: ";
        cin >> senha_real;
    }
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
}

void apresentacao(){
    cout << "\033[33m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\033[32m\n";
    cout << "        \033[32mNOZAMA\033[0m - \033[33mA MELHOR LOJA ONLINE!\n";
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\033[0m\n\n\n";
    cout << "   \033[32m N   N  OOO   ZZZZ  A A A  M   M  A A A" << endl;
    cout << "    NN  N O   O     Z  A   A  MM MM  A   A" << endl;
    cout << "    N N N O   O    Z   AAAAA  M M M  AAAAA" << endl;
    cout << "    N  NN O   O   Z    A   A  M   M  A   A" << endl;
    cout << "    N   N  OOO   ZZZZ  A   A  M   M  A   A\033[0m\n\n\n";
    cout << "\033[33m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\033[0m\n\n\n";
    system("pause");
    system ("cls");

}

int main(){
    apresentacao();
    char opc;
    Nopilha* carrinho = criar_Nopilha();
    usuario();
    Descritor* historico = criar_lista();
    
    do{
        menu(carrinho,historico);
        cout << "Comprar Novamente: [S] [N]\n > ";
        cin >> opc;
        system("cls");
    }
    while(opc == 'S' || opc == 's');
    cout << "Obrigado por comprar na Nozama! Volte Sempre :D \n";
    system("pause");
    system("cls");

    do{
        cout << "Visualizar Minhas Compras: [S] [N]\n > ";
        cin >> opc;
        system("cls");
    }
    while(opc != 'S' && opc != 's');
    if(opc == 's' || opc == 'S'){
        print(historico->ini,1);
        ver_carrinho(carrinho, 1);
    }

    
    system("pause");
    return 0;
}
