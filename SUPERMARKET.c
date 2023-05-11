#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

int count=0;

void push(int n);
void display();
void pop();
void invoice();
void backup();
void load();
void sync();

struct database
{
    int sn;
    int id;
    char name[10];
    float mrp;
    float sp;
    int quantity;
    float discount;
};

struct invoice
{
    int sn;
    int q;
    int amount;
};

struct database db[100];
struct invoice bill[100];

int main()
{
int ch,n;
printf("SUPERMARKET DATABASE MANAGEMENT SYSTEM");
while(1)
{
printf("\n------------MENU------------\n1.ADD PRODUCTS\n2.REMOVE A PRODUCT\n3.DISPLAY PRODUCTS\n4.GENERATE AN INVOICE\n5.BACKUP DATA TO THE DATABASE\n6.LOAD DATA FROM THE DATABASE\n7.SYNCHRONIZE DATA WITH THE DATABASE\n8.TERMINATE SOFTWARE\n");
scanf("%d",&ch);
switch(ch)
{
case 1 : printf("how many products?\n");
         scanf("%d",&n);
         push(n);
         break;
case 2 : pop();
         break;
case 3 : display();
         break;
case 4 : invoice();
         break;
case 5 : backup();
         break;
case 6 : load();
         break;
case 7 : sync();
         break;
case 8 : exit(0);
default : printf("invalid choice\n");
         break;
}
}
}

void push(int n)
{
    printf("\nadding products");
    int i;
    int tcount=count;
    for(i=tcount;i<(tcount+n);i++)
    {
    db[i].sn=i+1;
    count+=1;
    printf("\nproduct %d",count);
    printf("\nenter product id:");
    scanf("%d",&db[i].id);
    printf("\nenter product name:");
    scanf("%s",db[i].name);
    printf("\nenter maximum retail price:");
    scanf("%f",&db[i].mrp);
    printf("\nenter discount:");
    scanf("%f",&db[i].discount);
    printf("\nenter quantity:");
    scanf("%d",&db[i].quantity);
    db[i].sp=db[i].mrp-(db[i].mrp*db[i].discount*0.01);
    }
}

void display()
{
    printf("\ndisplaying products");
    int i;
    for(i=0;i<count;i++)
    {
    printf("\nname\nsn\tid\tmrp\tsp\tdiscount\tquantity");
    printf("\n------------------------");
    printf("\n%s",db[i].name);
    printf("\n%d\t%d\t%f\t%f\t%f\t%d",db[i].sn,db[i].id,db[i].mrp,db[i].sp,db[i].discount,db[i].quantity);
    }    
}

void invoice()
{
    int total=0;
    int id;
    int i=0;
    int j=0;
    int c=0;
    int ch=1;
    char s[100],contact[10];
    FILE *fp;
    time_t clock;
    time(&clock);
    fp=fopen("invoice.txt","a+");
    printf("\ngenerating invoice");
    while(ch==1)
    {
    printf("product %d",i+1);
    printf("\nadd product by sn:");
    scanf("%d",&id);
    printf("\nenter quantity:");
    scanf("%d",&bill[i].q);
    printf("\nif you want to add more items press 1 else press any other key:");
    scanf("%d",&ch);
    bill[i].sn=id;
    i+=1;
    c+=1;
    }
    printf("enter customer's contact number");
    scanf("%s",contact);
    printf("\ninvoice generated");
    printf("\n\n\n\n\n");
    printf("THANK YOU FOR SHOPPING!");
    printf("\nCUSTOMER'S CONTACT NUMBER:%s",contact);
    printf("\nDATE/TIME:%s",ctime(&clock));
    printf("\n------------------------");
    printf("\nname\nsn\tid\tmrp\tsp\tquantity\tdiscount\tamount");
    printf("\n------------------------");
    printf("\nsn\tid\tname\tmrp\tsp\tquantity\tdiscount\tamount");
    sprintf(s,"%s","THANK YOU FOR SHOPPING!");
    fputs(s,fp);
    sprintf(s,"\nCUSTOMER'S CONTACT NUMBER:%s",contact);
    fputs(s,fp);
    sprintf(s,"\nDATE/TIME:%s",ctime(&clock));
    fputs(s,fp);
    sprintf(s,"%s","\n------------------------");
    fputs(s,fp);
    sprintf(s,"%s","\nname\nsn\tid\tmrp\tsp\tquantity\tdiscount\tamount");
    fputs(s,fp);
    sprintf(s,"%s","\n------------------------");
    fputs(s,fp);
    sprintf(s,"%s","\nsn\tid\tname\tmrp\tsp\tquantity\tdiscount\tamount");
    fputs(s,fp);
    sprintf(s,"%s","\n------------------------");
    fputs(s,fp);
    for(i=0;i<c;i++)
    {
    while((bill[i].sn!=db[j].sn)&&(j<count))
    {
    j+=1;
    }
    if(j<count)
    {
    bill[i].amount=(db[j].sp)*(bill[i].q);
    printf("\n%s",db[i].name);
    printf("\n%d\t%d\t%s\t%f\t%f%d\t%f\t%d",bill[i].sn,db[j].id,db[j].name,db[j].mrp,db[j].sp,bill[i].q,db[j].discount,bill[i].amount);
    sprintf(s,"\n%s",db[i].name);
    fputs(s,fp);
    sprintf(s,"\n%d\t%d\t%s\t%f\t%f%d\t%f\t%d",bill[i].sn,db[j].id,db[j].name,db[j].mrp,db[j].sp,bill[i].q,db[j].discount,bill[i].amount);
    fputs(s,fp);
    db[j].quantity-=bill[i].q;
    total+=bill[i].amount;
    }
    j=0;
    }
    printf("\n------------------------");
    printf("\nTOTAL AMOUNT: %d",total);
    sprintf(s,"%s","\n------------------------");
    fputs(s,fp);
    sprintf(s,"\nTOTAL AMOUNT: %d",total);
    fputs(s,fp);
    sprintf(s,"%s","\n\n\n\n\n");
    fputs(s,fp);
}

void backup()
{
    int i;
    char s[10];
    FILE *fp,*cp;
    cp=fopen("cache.txt","w");
    sprintf(s,"%d",count);
    fputs(s,cp);
    fp=fopen("database.txt","w");
    for(i=0;i<count;i++)
    {
    sprintf(s,"%d",db[i].sn);
    fputs(s,fp);
    fputs("\n",fp);
    sprintf(s,"%d",db[i].id);
    fputs(s,fp);
    fputs("\n",fp);
    sprintf(s,"%s",db[i].name);
    fputs(s,fp);
    fputs("\n",fp);
    sprintf(s,"%f",db[i].mrp);
    fputs(s,fp);
    fputs("\n",fp);
    sprintf(s,"%f",db[i].sp);
    fputs(s,fp);
    fputs("\n",fp);
    sprintf(s,"%d",db[i].quantity);
    fputs(s,fp);
    fputs("\n",fp);
    sprintf(s,"%f",db[i].discount);
    fputs(s,fp);
    fputs("\n",fp);
    }
    fclose(fp);
    printf("\nbacked up data to the database");
}

void load()
{
    int i=0;
    char s[15];
    FILE *fp,*cp;
    cp=fopen("cache.txt","r");
    fgets(s,15,cp);
    sscanf(s,"%d",&count);
    fp=fopen("database.txt","r");
    for(i=0;i<count;i++)
    {
    fgets(s,15,fp);
    sscanf(s,"%d",&db[i].sn);
    fgets(s,15,fp);
    sscanf(s,"%d",&db[i].id);
    fgets(s,15,fp);
    sscanf(s,"%s",db[i].name);
    fgets(s,15,fp);
    sscanf(s,"%f",&db[i].mrp);
    fgets(s,15,fp);
    sscanf(s,"%f",&db[i].sp);
    fgets(s,15,fp);
    sscanf(s,"%d",&db[i].quantity);
    fgets(s,15,fp);
    sscanf(s,"%f",&db[i].discount);
    }
    fclose(fp);
    printf("\nloading data from the database");
}

void sync()
{
    backup();
    load();
    printf("\ndata synchronized with the database");
}

void pop()
{
    int sn;
    printf("\nremoving product");
    printf("\nenter product by sn:");
    scanf("%d",&sn);
    int i=0;
    int j=1;
    int flag=0;
    char s[15];
    FILE *fp;
    int cur;
    fp=fopen("database.txt","r");
    for(i=0;i<count;i++)
    {
    if(sn==i+1)
    {
       fgets(s,15,fp);
       fgets(s,15,fp);
       fgets(s,15,fp);
       fgets(s,15,fp);
       fgets(s,15,fp);
       fgets(s,15,fp);
       fgets(s,15,fp);
       flag=1;
    }
    fgets(s,15,fp);
    db[i].sn=j;
    j+=1;
    fgets(s,15,fp);
    sscanf(s,"%d",&db[i].id);
    fgets(s,15,fp);
    sscanf(s,"%s",db[i].name);
    fgets(s,15,fp);
    sscanf(s,"%f",&db[i].mrp);
    fgets(s,15,fp);
    sscanf(s,"%f",&db[i].sp);
    fgets(s,15,fp);
    sscanf(s,"%d",&db[i].quantity);
    fgets(s,15,fp);
    sscanf(s,"%f",&db[i].discount);
    }
    if(flag==1)
    {
        db[count-1].sn=0;
        db[count-1].id=0;
        sscanf("NULL","%s",db[count-1].name);
        db[count-1].mrp=0;
        db[count-1].sp=0;
        db[count-1].quantity=0;
        db[count-1].discount=0;
    }
    fclose(fp);
}
