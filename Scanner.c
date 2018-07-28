#include<stdio.h>
#include<stdlib.h>
#define maxlong 80

   int  linelong=0;
   char buffer[maxlong];
   char ch;
   char filein[10];
   char fileout[10];



int main()
{  
   FILE *fin;
   FILE *fout;
  
   enum symbol
  {
      add,sub,mul,div
   };
   
   
   printf("Please enter your filein name:");
   scanf("%s",filein);
   printf("Please enter your fileout name:");
   scanf("%s",fileout);
   if((fin=fopen(filein,"r"))==NULL)
      {
        printf("Cannot open this file.");
        exit(0);
      }
    if((fout=fopen(fileout,"w"))==NULL)
    {
       printf("Cannot open this file.");
       exit(0);
    }
   while(!feof(fin))
   {
      fscanf(fin,"%c",&ch);
    // ch=fgetc(fin);
   switch(ch)
       {
          case '+':
             fprintf(fout,"add:  ");
             fputc(ch,fout);
             fprintf(fout,"\n");
             break;
          case '-':
             fprintf(fout,"sub:  ");
             fputc(ch,fout);
             fprintf(fout,"\n");
             break;
          case '*':
             fprintf(fout,"mul:  ");
             fputc(ch,fout);
             fprintf(fout,"\n");
             break;
          case '/':
             fprintf(fout,"div:  ");
             fputc(ch,fout);
             fprintf(fout,"\n");
             break;
          case '=':
             fprintf(fout,"assign:  ");
             fputc(ch,fout);
             fprintf(fout,"\n");
       }
        
      
     if(ch>='0'&&ch<='9')
        {  
           fprintf(fout,"num:  ");
           linelong=0;
           buffer[linelong]=ch;
           fputc(buffer[linelong],fout);
           fscanf(fin,"%c",&ch);
           while(ch>='0'&&ch<='9')
                {
                    linelong++;   
                    buffer[linelong]=ch;
                    fputc(buffer[linelong],fout);
                    fscanf(fin,"%c",&ch);
                 }
            fprintf(fout,"\n");
        }


      
       if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'||ch=='_')
        { 
           fprintf(fout,"id:  ");
           linelong=0;
           buffer[linelong]=ch;
           //fputc(buffer[linelong],fout);
           fscanf(fin,"%c",&ch);
           while(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'||ch=='_'||ch>='0'&&ch<='9')
                   {
                        linelong++;   
                        buffer[linelong]=ch;
                        fputc(buffer[linelong],fout);
                        fscanf(fin,"%c",&ch);
                        //if(strcmp(buffer[3],reservedTable[k])=0)
                    }
            fprintf(fout,"\n");
        }  
    }
   fclose(fin);
   fclose(fout);
   return 0;
  
}



