#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include <time.h>
#include <windows.h>
void hora(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int ano = tm.tm_year + 1900;
}

void input(char* var,char* texto){
char resp;
do{
    puts("");
    puts("                 CADASTRO DO PACIENTE");
    printf("        ========================================\n");
    puts("");
    printf("               Digite o(a) %s : ", texto);
scanf("%[^\n]",var);
fflush(stdin);
system("cls");
    puts("");
    puts("                 CADASTRO DO PACIENTE");
    printf("        ========================================\n");
    puts("");
printf("               Confirme os dados do(a) %s: '%s'\n",texto,var);
printf("               [s/n]: ");
resp=getch();
fflush(stdin);
}while (resp != 's' && resp != 'S');
system("cls");

}

struct Paciente{

char nome[30];
char cpf[18];
char telefone[16];
char rua[128];
char numero[10];
char bairro[30];
char cidade[30];
char estado[30];
char cep[12];
int dia_nascimento;
int mes_nascimento;
int ano_nascimento;
char email[80];
char data_do_diagnostico[10];
char comorbidades[128];
char risco[50];
int idade;
};

typedef struct Paciente Paciente;
Paciente paciente;

void getpaciente(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int ano = tm.tm_year + 1900;
    int mes = tm.tm_mon + 1;
    puts("");
    puts("                    PACIENTE CADASTRADO COM SUCESSO");
    puts("");
    printf("     **************************************************************\n");
    printf("               Nome do Paciente: %s\n",paciente.nome);
    printf("               CPF: %s\n",paciente.cpf);
    printf("               Rua: %s\n",paciente.rua);
    printf("               Numero: %s\n",paciente.numero);
    printf("               Bairro: %s\n",paciente.bairro);
    printf("               Cidade: %s\n",paciente.cidade);
    printf("               Estado: %s\n",paciente.estado);
    printf("               CEP: %s\n",paciente.cep);
    printf("               Data de Nascimento: %02d/%02d/%04d\n",paciente.dia_nascimento,paciente.mes_nascimento,paciente.ano_nascimento);
    printf("               Email: %s\n",paciente.email);
    printf("               Data do Diagnostico: %02d/%02d/%04d\n",tm.tm_mday,mes,ano);
    printf("               Comorbidades: %s\n",paciente.comorbidades);
    printf("               O Paciente possui %d anos. \n",paciente.idade);
    printf("               %s \n",paciente.risco);
    printf("     **************************************************************\n");
    }

void novopaciente(){
    FILE *file;
    char arquivo[50];
    char arquivo1[50];
    char pasta[50];
    strcpy(arquivo,paciente.nome);
    strcpy(arquivo1,".txt");
    strcpy(pasta,"Pacientes Cadastrados\\");
    strcat(arquivo,arquivo1);
    strcat(pasta,arquivo);
    file = fopen(pasta,"w");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int ano = tm.tm_year + 1900;
    int mes = tm.tm_mon + 1;
    fprintf(file,"\n");
    fprintf(file,"                 DADOS DO PACIENTE\n");
    fprintf(file,"\n");
    fprintf(file,"************************************************************************\n");
    fprintf(file,"               Nome do paciente: %s\n",paciente.nome);
    fprintf(file,"               CPF: %s\n",paciente.cpf);
    fprintf(file,"               Rua: %s\n",paciente.rua);
    fprintf(file,"               Numero: %s\n",paciente.numero);
    fprintf(file,"               Bairro: %s\n",paciente.bairro);
    fprintf(file,"               Cidade: %s\n",paciente.cidade);
    fprintf(file,"               Estado: %s\n",paciente.estado);
    fprintf(file,"               CEP: %s\n",paciente.cep);
    fprintf(file,"               Data de Nascimento: %02d/%02d/%04d\n",paciente.dia_nascimento,paciente.mes_nascimento,paciente.ano_nascimento);
    fprintf(file,"               Email: %s\n",paciente.email);
    fprintf(file,"               Data do Diagnostico: %02d/%02d/%04d\n",tm.tm_mday,mes,ano);
    fprintf(file,"               Comorbidades: %s\n",paciente.comorbidades);
    fprintf(file,"               O Paciente possui %d anos. \n",paciente.idade);
    fprintf(file,"               %s \n",paciente.risco);
    fprintf(file,"************************************************************************\n");
    fclose(file);
    }

void alerta(){
    FILE *file;
    char arquivo3[50];
    char arquivo4[50];
    char arquivo2[50];
    strcpy(arquivo3,paciente.nome);
    strcpy(arquivo4,".txt");
    strcpy(arquivo2,"Grupo de Risco\\(Paciente de Risco)");
    strcat(arquivo2,arquivo3);
    strcat(arquivo2,arquivo4);
    file = fopen(arquivo2,"w");
    fprintf(file,"\n");
    fprintf(file,"                 PACIENTE DE RISCO \n");
    fprintf(file,"              INFORMAR AS AUTORIDADES \n");
    fprintf(file,"\n");
    fprintf(file,"************************************************************************\n");
    fprintf(file,"               Nome do paciente: %s\n",paciente.nome);
    fprintf(file,"               CEP: %s\n",paciente.cep);
    fprintf(file,"               Comorbidades: %s\n",paciente.comorbidades);
    fprintf(file,"               O Paciente possui %d anos. \n",paciente.idade);
    fprintf(file,"************************************************************************\n");
    fclose(file);
}

int grupo_de_risco(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int diaatual,mesatual,anoatual,diap,mesp,anop;
    diaatual = tm.tm_mday;
    mesatual = tm.tm_mon+1;
    anoatual = tm.tm_year +1900;
    diap = paciente.dia_nascimento;
    mesp = paciente.mes_nascimento;
    anop = paciente.ano_nascimento;
    int idadep;

    if((diaatual < diap) && (mesatual <= mesp)){
        idadep = anoatual-anop-1;
    }else{ idadep = anoatual-anop;}
    paciente.idade = idadep;
    if (idadep>=65 || (strcmp(paciente.comorbidades," ")!=0) ){
        return 1;
    }else{
        return 0;}


}

int main(){
    SetConsoleTitle("Sistema de Cadastro de Paciente Positivo para COVID-19");

int xx = 1;

char user[50];
char pass[50];
do{/*
    puts("               Login do Sistema de Cadastro de Paciente");
    printf("        ===================================================\n");
    printf("                          Digite o Usuario: ");
    scanf("%s",user);
    printf("\n");
    printf("                          Digite a Senha: ");
    scanf("%s",pass);

    if(strcmp(pass,"123") != 0 || strcmp(user,"admin") != 0){
        printf("        ===================================================\n");
        puts("                     Usuario ou Senha inválidos");
        printf("        ===================================================\n");
        system("pause");
        system("cls");}

}while ((strcmp(pass,"123") != 0) && (strcmp(user,"admin") != 0));
printf("        ===================================================\n");
puts("                          Acesso Concedido.");
printf("        ===================================================\n");
system("pause");
system("cls");

do{
    fflush(stdin);
    input(paciente.nome,"Nome");
    input(paciente.cpf,"CPF");
    input(paciente.telefone,"Telefone");
    input(paciente.rua,"Rua");
    input(paciente.numero,"Numero da casa");
    input(paciente.bairro,"Bairro");
    input(paciente.cidade,"Cidade");
    input(paciente.estado,"Estado");
    input(paciente.cep,"CEP");
    input(paciente.email, "E-Mail");
    puts("                 CADASTRO DO PACIENTE");
    printf("        ========================================\n");
    printf("           Digite o Dia do nascimento: ");
    scanf("%02d",&paciente.dia_nascimento);
    system("cls");
    puts("                 CADASTRO DO PACIENTE");
    printf("        ========================================\n");
    printf("           Digite o Mes do nascimento: ");
    scanf("%02d",&paciente.mes_nascimento);
    system("cls");*/
    puts("                 CADASTRO DO PACIENTE");
    printf("        ========================================\n");
    printf("           Digite o Ano do nascimento: ");
    scanf("%04d",&paciente.ano_nascimento);
    system("cls");
    strcpy(paciente.comorbidades," ");
    char ch;
    do{
        puts("                 CADASTRO DO PACIENTE");
        printf("        ========================================\n");
        puts("          O paciente possui alguma comorbidade? [s/n]");
        ch=getch();
        fflush(stdin);
        if (ch == 's'){
            char y;
            char v[50] = " , ";
            char comorbidade[256];
            system("cls");
            puts("                 CADASTRO DO PACIENTE");
            printf("        ========================================\n");
            puts("Digite a comorbidade do paciente(diabetes, obesidade, hipertensao, tuberculose etc.)");
            printf("Comorbidade: ");
            scanf("%s",comorbidade);
            fflush(stdin);
            strcpy(paciente.comorbidades,comorbidade);
            system("cls");
            do{
            puts("                 CADASTRO DO PACIENTE");
            printf("        ========================================\n");
            puts("          O paciente possui outra comorbidade? [s/n]");
            y=getch();
            fflush(stdin);
            if (y == 's'){
            system("cls");
            puts("                 CADASTRO DO PACIENTE");
            printf("        ========================================\n");
            puts("Digite a outra comorbidade do paciente(diabetes, obesidade, hipertensao, tuberculose etc.)");
            printf("Comorbidade: ");
            scanf("%s",comorbidade);
            fflush(stdin);
            strcat(paciente.comorbidades,v);
            strcat(paciente.comorbidades,comorbidade);
            system("cls");
            }
            if (y=='n' || y=='N'){ch='n';}

        }while (y != 'n' && y != 'N');
        }

  }while (ch != 'n' && ch != 'N');

    system("cls");

    int i = grupo_de_risco();
    int x;
    if (i ==1){
        system("cls");
        puts("                 CADASTRO DO PACIENTE");
        printf("        ========================================\n");
        printf("        O paciente pertence ao grupo de risco\n");
        strcpy(paciente.risco,"O paciente pertence ao grupo de risco");
        alerta();
        x = 1;
    }else{
        system("cls");
        puts("                 CADASTRO DO PACIENTE");
        printf("        ========================================\n");
        printf("        O paciente nao pertence ao grupo de risco\n");
        strcpy(paciente.risco,"O paciente nao pertence ao grupo de risco");
        x = 0;
        }
    fflush(stdin);
    system("pause");
    system("cls");

    if ((strcmp(paciente.comorbidades," ")==0)){
            strcpy(paciente.comorbidades,"Nao possui comorbidades");}

    getpaciente();

    novopaciente();

    char c;
    printf("Deseja cadastrar um novo paciente? [s/n] :");
    c=getch();
    do{
    if ((c == 'n') || (c == 'N')){
        xx = 2;
        break;}
    if ((c == 's') || (c == 'S')){
        system("cls");
        break;
    }else{
    printf("Dados inválidos.\n");
    printf("Deseja cadastrar um novo paciente? [s/n] :");
    c=getch();}
    }while(((c != 'n') || (c != 'N') || (c != 's') || (c != 'S')));

}while (xx == 1);


return 0;
}
