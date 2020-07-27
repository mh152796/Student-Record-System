#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 1000
typedef struct student
{
    char name[30];
    char ID[20];
    char e_mail[30];
    char phone_no[20];
} std;
std info[size];
int l=0;
void add()
{
    std st;
    printf("Enter Student Name: ");
    fflush(stdin);
    gets(st.name);
    printf("Enter Student ID: ");
    gets(st.ID);
    printf("Enter E-Mail: ");
    gets(st.e_mail);
    printf("Enter Phone Number: ");
    gets(st.phone_no);
    info[l]=st;
    l++;

}
void modify()
{
    int i,j,k=0;
    char ch[20];
    printf("Enter (Name/E-mail/Id/Phone Number): ");
    fflush(stdin);
    gets(ch);
    if((ch[0]>='a'&&ch[0]<='z')||(ch[0]>='A'&&ch[0]<='Z')||((ch[0]>='0'&&ch[0]<='9')))
    {
        for(i=0; i<l; i++)
        {
            if(strcmp(ch,info[i].name)==0||strcmp(ch,info[i].ID)==0||strcmp(ch,info[i].e_mail)==0||strcmp(ch,info[i].phone_no)==0)
            {
                printf("Enter Student Name: ");
                fflush(stdin);
                gets(info[i].name);
                printf("Enter Student ID: ");
                gets(info[i].ID);
                printf("Enter E-Mail: ");
                gets(info[i].e_mail);
                printf("Enter Phone Number: ");
                gets(info[i].phone_no);
                k=1;
                break;
            }
        }


        if(k==1)
        {
            printf("Information has Modified.\n",ch);
        }
        else
        {
            printf("The Information not found on the record.\n") ;
        }
    }
    else
    {
        printf("Invalid Imput!.\n");
    }
    char c;
    printf("Press 0 to clear screen And return main function: ");
    fflush(stdin);
    scanf("%c",&c);
    if(c=='0')
    {
        system("CLS");
    }
    else
    {
        return;
    }
}
void delet()
{
    int i,j,k=0;
    char ch[20];
    printf("Enter (Name/E-mail/Id/Phone Number): ");
    fflush(stdin);
    gets(ch);
    if((ch[0]>='a'&&ch[0]<='z')||(ch[0]>='A'&&ch[0]<='Z')||((ch[0]>='0'&&ch[0]<='9')))
    {
        for(i=0; i<l; i++)
        {
            if(strcmp(ch,info[i].name)==0||strcmp(ch,info[i].ID)==0||strcmp(ch,info[i].e_mail)==0||strcmp(ch,info[i].phone_no)==0)
            {
                for(j=i; j<l; j++)
                {
                    strcpy(info[j].name,info[j+1].name);
                    strcpy(info[j].ID,info[j+1].ID);
                    strcpy(info[j].e_mail,info[j+1].e_mail);
                    strcpy(info[j].phone_no,info[j+1].phone_no);

                }
                l--;
                k=1;
                break;
            }
        }


        if(k==1)
        {
            printf("Erased all of %s's information from the record.\n",ch);
        }
        else
        {
            printf("The Information not found on the record.\n") ;
        }
    }
    else
    {
        printf("Invalid Search!.\n");
    }
    char c;
    printf("Press 0 to clear screen And return main function: ");
    fflush(stdin);
    scanf("%c",&c);
    if(c=='0')
    {
        system("CLS");
    }
    else
    {
        return;
    }

}
void search()
{
    int i,j=0;
    char ch[20];
    printf("Enter (Name/E-mail/Id/Phone Number): ");
    fflush(stdin);
    gets(ch);

    if((ch[0]>='a'&&ch[0]<='z')||(ch[0]>='A'&&ch[0]<='Z')||((ch[0]>='0'&&ch[0]<='9')))
    {
        for(i=0; i<l; i++)
        {
            if(strcmp(ch,info[i].name)==0||strcmp(ch,info[i].ID)==0||strcmp(ch,info[i].e_mail)==0||strcmp(ch,info[i].phone_no)==0)
            {
                printf("%d Position Student Information:\n",i+1);
                printf("\tName:%s\n",info[i].name);
                printf("\tID:%s\n",info[i].ID);
                printf("\tE-Mail:%s\n",info[i].e_mail);
                printf("\tPhone Number%s\n",info[i].phone_no);
                printf("\n");
                j=1;
                break;
            }
        }
        if(j==0)
        {
            printf("The Search Information not found on the record.\n");
        }


    }
    else
    {
        printf("Invalid Search!.\n");
    }
    char c;
    printf("Press 0 to clear screen And return main function: ");
    fflush(stdin);
    scanf("%c",&c);
    if(c=='0')
    {
        system("CLS");
    }
    else
    {
        return;
    }
}
void display()
{
    int i;


    for(i=0; i<l; i++)
    {
        printf("%d.Student Information:\n",i+1);
        printf("\tName:%s\n",info[i].name);
        printf("\tId:%s\n",info[i].ID);
        printf("\tE-Mail:%s\n",info[i].e_mail);
        printf("\tPhone Number:%s\n",info[i].phone_no);
        printf("\n");
    }
    char c;
    printf("Press 0 to clear screen And return main function: ");
    fflush(stdin);
    scanf("%c",&c);
    if(c=='0')
    {
        system("CLS");
    }
    else
    {
        return;
    }

}
int main()
{
    char ch;
    while(1)
    {
        printf("\t\t\tEnter your choice:\n");
        printf("\t\t\tPress 1 for Insert Student Info.\n");
        printf("\t\t\tPress 2 for Display All Student Info.\n");
        printf("\t\t\tPress 3 for Search.\n");
        printf("\t\t\tPress 4 for Delete.\n");
        printf("\t\t\tPress 5 for Modify Information.\n");
        printf("\t\t\tPress c to clear screen.\n");
        printf("\t\t\tPress 0 for exit.\n");
        fflush(stdin);
        scanf("%c",&ch);
        switch(ch)
        {
        case '1':
            if(l==size)
            {
                printf("STORAGE FULL\n");
                break;
            }
            add();
            break;
        case '2':
            if(l==0)
            {
                printf("The Rocord List is Empty!\n");
                break;
            }
            display();
            break;
        case '3':
            if(l==0)
            {
                printf("The Rocord List is Empty!\n");
                break;
            }
            search();
            break;
        case '4':
            if(l==0)
            {
                printf("The Rocord List is Empty!\n");
                break;
            }
            delet();
            break;
        case '5':
            if(l==0)
            {
                printf("The Rocord List is Empty!\n");
                break;
            }
            modify();
            break;
        case 'c':
            system("CLS");
            break;
        case '0':
            exit(0);
        default:
            printf("Invalid Imput!. Please Try Again.\n");
            break;
        }


    }
}
