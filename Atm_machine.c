#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define MAX_TRANSACTIONS 10
int d=0,w=0;
struct user{
    char name[20];
    char pass[10];
    int bal;

}vk={"Vinay","vk5288",0};
struct Transaction{
    char type[20];
    int amount;
};
struct Transaction history[MAX_TRANSACTIONS];
int tranCount=0;
int deposit();
int Withdraw();
int Enquire();
void Transaction();
int ChangePin();
void recordTransaction(const char *type,float amount){
    if(tranCount<MAX_TRANSACTIONS){
        strcpy(history[tranCount].type,type);
        history[tranCount].amount=amount;
        printf("\n\tYour Transaction:%d",history[tranCount].amount);
        tranCount++;
    }
    else{
        for(int i=1;i<MAX_TRANSACTIONS;i++)
            history[i-1]=history[i];
        strcpy(history[MAX_TRANSACTIONS-1].type,type);
        history[MAX_TRANSACTIONS-1].amount=amount;
    }
}
int Deposit(){
    system("cls");
    printf("\t\t *********************************\n");
    printf("\t\t\t DEPOSIT\n");
    printf("\t\t *********************************\n");
    int n;
    /*printf("\n\tEnter your Password: ");
    char pin[200];
    int i=0;
    char ch;
    while((ch=getch())!='\r'&& i<6){
          putch('*');
          pin[i++]=ch;
    }
    pin[i]='\0';
    if(strcmp(pin,vk.pass)==0){
        printf("\n\tSuccess");*/
        printf("\n\tEnter the amount to deposit:");
        scanf("%d",&n);
        vk.bal+=n;
        recordTransaction("Deposit",n);
        return 0;
}
int Withdraw(){
    system("cls");
    printf("\t\t *********************************\n");
    printf("\t\t\t Withdraw\n");
    printf("\t\t *********************************\n");

    int n;
    char pin[200];
    int i=0;
    char ch,np;
    printf("\n\tEnter Password:");
    while((ch=getch())!='\r'&& i<6){
          putch('*');
          pin[i++]=ch;
    }
    pin[i]='\0';
    int j=0;
    if(strcmp(pin,vk.pass)==0){
        printf("\n\tEnter the amount to Withdraw:");
        scanf("%d",&n);
        if(n<vk.bal){
            vk.bal-=n;
            recordTransaction("Withdraw",n);
        }
        else
            printf("\n\tNot enough balance");
    }
    return 0;
}
int Enquire()
{
    system("cls");
    printf("\t\t *********************************\n");
    printf("\t\t\t Enquiry\n");
    printf("\t\t *********************************\n");
    printf("\tYour Balance:%d",vk.bal);
    return 0;
}

void Transac(){
    system("cls");
    printf("\t\t *********************************\n");
    printf("\t\t\tTransaction History\n");
    printf("\t\t *********************************\n");
    FILE *file;
    char text[100];
    file=fopen("C:\vinay\codeblocks\TransactionHistory.txt","a");
    if(tranCount==0){
        printf("No trasactions fountd");
    }
    else{
        for(int i=0;i<tranCount;i++){
            fprintf(file,"%s:$%d\n",history[i].type,history[i].amount);
            printf("%s:$%d\n",history[i].type,history[i].amount);
        }
        printf("%d",vk.bal);
    }
}
int ChangePin(){

    system("cls");
    printf("\t\t *********************************\n");
    printf("\t\t\tUpdate Pin\n");
    printf("\t\t *********************************\n");
    printf("\n\tEnter your Password: ");
    char pin[200];
    int i=0;
    char ch,np;
    while((ch=getch())!='\r'&& i<6){
          putch('*');
          pin[i++]=ch;
    }
    pin[i]='\0';
    int j=0;
    if(strcmp(pin,vk.pass)==0){
        printf("\n\tEnter your new password");
        while((np=getch())!='\r' && j<6){
            putch(np);
            vk.pass[j++]=np;
        }
    }
    printf("\n\t%s",vk.pass);

    return 0;
}
void main(){
    printf("\n\n\t\t *********************************\n");
    printf("\t\t\tWelcome to ATM\n");
    printf("\t\t *********************************\n\n");
    int sum=0;printf("\n\tEnter your Password: ");
    char pin[200];
    int i=0;
    char ch;
    while((ch=getch())!='\r'&& i<6){
          putch('*');
          pin[i++]=ch;
    }
    pin[i]='\0';
    if(strcmp(pin,vk.pass)==0){
        printf("\n\tAuthentication Success!....");
        while(1){

            printf("\n\t >Deposit");
            printf("\n\t >Withdraw");
            printf("\n\t >Enquire");
            printf("\n\t >Transaction History");
            printf("\n\t >Pin Change\n\t >Exit");
            printf("\n\t Enter your choice:");
            int choice;
            scanf("%d",&choice);
            switch(choice){
                case 1:

                    sum=Deposit();
                    break;
                case 2:
                    Withdraw();
                    break;
                case 3:
                    Enquire();
                    break;
                case 4:
                    Transac();
                    break;
                case 5:
                    ChangePin();
                    break;
                case 6:
                    return;
                default:
                    printf("Enter valid choice...");
            }
        }
    }
}
