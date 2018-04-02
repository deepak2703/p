#include<stdio.h>
#include<ctype.h>
void first(char);
void addToResult(char);
int numOfProductions,m;
char a[10][10],result[20];
void main( )
{
int i;
char choice;
printf("How many number of productions?:");
scanf("%d",&numOfProductions);
for(i=0;i<numOfProductions;i++)
//read production string eg:E=E+T
{
printf("Enter productions Number %d:",i+1);
scanf("%s",a[i]);
}
do
{
result[0]='\0';
m=0;
char c;
printf("\nFind the FIRST of:");scanf("%c",&c);
scanf("%c",&c);
first(c);
//Compute FIRST; Get Answer in 'result' array
printf("\nFIRST(%c)={",c);
for(i=0;result[i]!='\0';i++)
printf("%c",result[i]);
//Display result
printf("}\n");
printf("press 'y' to continue:");
scanf("%c",&choice);
scanf("%c",&choice);
}
while(choice=='y'||choice=='Y');
}


void first(char c)
{
int k;
if(!(isupper(c)))
//f[m++]=c;
addToResult(c);
for(k=0;k<numOfProductions;k++)
{
if(a[k][0]==c)
{
if(islower(a[k][2]))
//f[m++]=a[k][2];
addToResult(a[k][2]);
else
first(a[k][2]);
}
}
}

void addToResult(char c)
{
int i;
for( i=0;i<=m;i++)
if(result[i]==c)
return;
result[m++]=c;
}
