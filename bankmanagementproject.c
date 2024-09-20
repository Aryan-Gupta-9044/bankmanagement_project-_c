#include <stdio.h>
int n,s,amt,ind,choice,accno[5],balance[1000],pin[40];
    char name[20][20],address[40][40];
void display(int n,int k);
void sdisplay(int n,int k,int s);
void withdraw(int s, int n, int amt,int k);
int search(int s, int number);
void deposit(int s,int n, int amt,int k);
int main() {
    printf("Number of customer records you want to enter? : ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("\nYour Account no is: %d\n",i+1);
        accno[i]=i+1;
        printf("Enter name : ");
        scanf("%s",&name[i]);
        printf("Enter Address : ");
        scanf("%s",&address[i]);
        printf("Enter pin : ");
        scanf("%d",&pin[i]);
        balance[i]=0;
        printf("\nYour Account balance is: %d\n",balance[i]);
         }
    do
    {
        int k=0;
        printf("__________________________________\n");
        printf("\n\t\tBanking System Menu :\n");
        printf("__________________________________\n");
        printf("Press 1 to display all records.\n");
        printf("Press 2 to search a record.\n");
        printf("Press 3 to deposit amount.\n");
        printf("Press 4 to withdraw amount.\n");
        printf("Press 0 to exit\n");
        printf("\nEnter choice(0-4) : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                display(n,k=0);
                break;
            case 2:
                printf("\n\nEnter account number to search : ");
                scanf("%d", &s);
                sdisplay(n,search(s,n),s);
                break;
            case 3:
                printf("\n\nEnter account number : ");
                scanf("%d", &s);
                printf("\n\nEnter amount to deposit : ");
                scanf("%d", &amt);
                k=s-1;
                deposit(s,n,amt,k);
                break;
            case 4:
                printf("\n\nEnter account number : ");
                scanf("%d", &s);
                printf("\n\nEnter amount to withdraw : ");
                scanf("%d", &amt);
                k=s-1;
                withdraw(s,n,amt,k);
            case 0:
                printf("Thanks for visit");        
        }
    }
    while (choice != 0);
    return 0;
}
void display(int n,int k){
        for(int j=0;j<n;j++){
            printf("\n\t\tDetails of Customer %d\n",j+1);
            printf("\tAcc No : %d\n",accno[j]);
            printf("\tName : %s\n",name[j]);
            printf("\tAddress : %s\n",address[j]);
            printf("\tBalance : %d\n\n",balance[j]);
        }
}
void sdisplay(int n,int k,int s){
    if(k==-1)
        printf("\n\n\tRecord not found\n");
    else{
        printf("\n\t\tDetails of Customer %d\n",k+1);
        printf("\tAcc No : %d\t\n",accno[k]);
        printf("\tName : %s\t\n",name[k]);
        printf("\tAddress : %s\t\n",address[k]);
        //printf("%d\n",pin[j]);
        printf("\tBalance : %d\t\n\n",balance[k]);
    }
}
int search(int s,int n)
{
    for (int i = 0; i < n; i++)
    {
        if (accno[i] == s)
        return i;
    }
    return  - 1;
}
void deposit(int s,int n, int amt,int k)
{
    
    int i = search(s,n);
    if (i ==  - 1)
        printf("Record not found\n4");
    else
    {
        int pi;
        printf("Enter your Pin");
        scanf("%d",&pi);
        if(pin[i]==pi){
        balance[i]+= amt;
        sdisplay(n,k,s);}
        else
        printf("Invalid Pin");
    }
}
void withdraw(int s, int n, int amt,int k)
{
    int i = search(s,n);
    int pi;
    
    if (i ==  - 1)
        printf("Record not found\n");
    else if (balance[i] < amt)
        printf("Insufficient balance\n");
    else
    {
        printf("Enter your Pin");
        scanf("%d",&pi);
        if(pin[i]==pi){
        balance[i] -= amt;
        sdisplay(n,k,s);}
        else
        printf("Invalid Pin");
    }
}
