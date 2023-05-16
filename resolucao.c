#include <stdio.h>


//estrutura da mesa
struct mesa
{
    int inicio;
    int ocupacao;
};


//globais

//iniciar as mesas
struct mesa mesas[4] = {{0,0},{0,0},{0,0},{0,0}};

//variavel de controle da hora
//restaurante abre as 14 e fecha as 23
int hora_atual=14;

//fila
#define MAX 20
//tamanho da fila maximo
int fila[MAX];
//endereco de final
int fim = 0;
//endereco de inicio
int ini = 0;

//funcao de adicao fila
void qstore(int quant){
    //condicao para fila cheia
    if (fim == MAX){
        // printf("Fila cheia.\n");
        return;
    }
    //salva o valor no vetor
    fila[fim] = quant;
    //ajusta o final da fila
    fim++;
}

//funcao de extracao da fila
int qretrieve(){
    //condicao para lista vazia
    if (ini==fim){
        // printf("Fila vazia.\n");
        return NULL;
    }
    //mudar o inicio da fila
    ini++;
    //retornar o valor
    return fila[ini-1];
}

//funcao impressao
void imprimir(struct mesa * mesas,int * fila)
{
    //variavel de controle do for para a fila
    int i = 0;
    
    printf("----------\n");
    //print da fila completa
    printf("Fila:");
    for (i=ini;i<=fim;i++){
        if (fila[i]!=0){
            printf("%d-",fila[i]);
        }
        
    }
    printf("\n");
    //print da hora atual
    printf("Hora Atual: %d\n",hora_atual);
    printf("----------\n\n");

    //print da ocupacao de todas as mesas
    for (i=0;i<4;i++)
        {
            printf("Mesa %d: %d\n", i+1,mesas[i].ocupacao);
            // printf("Hora: %d\n", mesas[i].inicio);
            // printf("--\n");
            
        }
}

//funcao de manutencao
//serve para verificar se alguma mesa ja passou de 2h e preencher o a fila
//2h é o tempo maximo que uma mesa fica ocupada
void manutencao(struct mesa * mesas, int * fila)
{
    //variavel de controle dos loopings
    int i,j;

    //looping para as mesas
    for (i=0;i<=3;i++)
    {
        //condicao para limpar as mesas
        //pessoas ficam somente 2h
        if (mesas[i].inicio < (hora_atual-1))
        {
            //limpeza da mesa
            mesas[i].ocupacao = 0;
            mesas[i].inicio = 0;
            
            //looping 2 para a fila
            //se houver alguem na fila ja preenche as mesas
            for (j=ini;j<=fim;j++)
            {
                //fila com pessoas é diferente de 0
                if (fila[j]!=0)
                {
                    //preencher a mesa
                    //usar o primeiro da fila
                    mesas[i].ocupacao = qretrieve();
                    //ajuste da hora atual
                    mesas[i].inicio = hora_atual;
                    break;
                }
            }
        }     
    }  
}

//funcao principal
int main()
{
    int chegada; //variavel da hora da chegada
    int hora_atual_temp; //variavel para a leitura da hora

    //looping para menu
    do{

        //funcao imprimir as mesas
        imprimir(&mesas[0],&fila[0]);

        //leituras do operador
        printf("\nQuantas pessoas chegaram?\n");
        scanf("%d",&chegada);
        //checagem para ver se a hora digitada é maior ou igual a hora atual
        do{
            printf("Que horas chegaram?\n");
            scanf("%d",&hora_atual_temp);
        }while(hora_atual_temp<hora_atual);
        hora_atual = hora_atual_temp;

        qstore(chegada);
        manutencao(&mesas[0],&fila[0]);



    //restaurante fecha as 23
    }while (hora_atual<23);
    
    return 0;
}
