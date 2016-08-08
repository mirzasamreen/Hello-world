#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
void main()
{
  clrscr();
  char *emessage,*dmessage;
  int i,j=0,k,key,temp,c,c1;
  clrscr();
  FILE *file,*file1;
  char message[10],buf[100],ch,ch1,buf1[10];

file=fopen("trans.txt","r");
while(fgets(message,10,file)!=NULL)
{
scanf("%c",&message);
printf("plain text is");
for(i=0;message[i]!=NULL;i++)
printf("%c",message[i]);
}
fclose(file);
 printf("\nEnter the key\n");
  scanf("%d",&key);
  key=key%26;
   do
   {
   printf("0.encryption 1.decryption 2.exit\n");
   scanf("%d",&c);
  switch(c)
  {

  case 0:


  for(i=0;message[i]!=NULL;i++)
  message[i]=tolower(message[i]);

  for(i=0;message[i]!=NULL;i++)
  {
  //printf("%c ",message[i]);
    if(message[i]==' ')
    emessage[j++]=message[i];

    else
	{

       if(message[i]>=48 && message[i]<=57)//for numbers
       {
	temp=message[i]+key;
	 if(temp>57)
	 emessage[j++]=48+(temp-58);
	 else
	 emessage[j++]=temp;
       }
       else
	   {
	if(message[i]>=97 && message[i]<=123)       //for alphabets
	  {
	   temp=message[i]+key;
	   if(temp>122)
	     emessage[j++]=97+(temp-123);
	   else
	     emessage[j++]=temp;

	   }
	 else
	      emessage[j++]=message[i];
	}
	 fputc(emessage[j],file1);
	      // printf("%c ",emessage[j]);
    }
  /*  file1=fopen("print.txt","w+");
   i=0;
     while(emessage[j]!=NULL)
     {
     ch=emessage[j];
     j++;
       fputc(ch,file1);
       }   */
  }

  emessage[j]='\0';
  printf("\n\n\nCipher text is\n\n");
   file1=fopen("print.txt","w+");
 { for(i=0;emessage[i]!=NULL;i++)
{  printf("%c",emessage[i]);
   ch=emessage[i];
  putc(ch,file1);
}
  }

//  fclose(file1);

/*   file1=fopen("print.txt","w+");
 {// printf("\n\n\nCipher text is\n\n");
  for(i=0;emessage[i]!=NULL;i++)
//  printf("%c",emessage[i]);

  ch=emessage[i];
  fputc(ch,file1);
 }*/
//  fclose(file1);
   file1=fopen("print.txt","r");
   while(fgets(buf,100,file1)!=NULL)
   printf("%s",buf);
   printf("\n");
  fclose(file1);
break;
 case 1:

   for(i=0,j=0;emessage[i]!=NULL;i++)
   {

      if(emessage[i]==' ')
     dmessage[j++]=emessage[i];
      else
     {
     if(emessage[i]>=48 && emessage[i]<=57)
	{
	 temp=emessage[i]-key;
	 if(temp<48)
	 dmessage[j++]=58-(48-temp);
	 else
	 dmessage[j++]=temp;
	}
      else
	 {
	if(emessage[i]>=97 && emessage[i]<=123)
	  {
	   temp=emessage[i]-key;
	   if(temp<97)
	   dmessage[j++]=123-(97-temp);
	   else
	   dmessage[j++]=temp;
	  }
	 else
	  dmessage[j++]=emessage[i];
	 }
     }
   }
   dmessage[j]='\0';
  printf("\n\n\nPlain text is\n\n");
     file1=fopen("pri.txt","w+");
  for(i=0;dmessage[i]!=NULL;i++)
 {
 { printf("%c",dmessage[i]);
   ch1=dmessage[i];
  putc(ch1,file1);
} }
    file1=fopen("pri.txt","r");
   while(fgets(buf1,10,file1)!=NULL)
   printf("%s",buf1);
   printf("\n");
   fclose(file1);
  break;
   case 2: exit(0);
  }
  printf("do you want to cont...(1/0)\n");
  scanf("%d",&c1);
  }while(c1!=0);
  getch();

}