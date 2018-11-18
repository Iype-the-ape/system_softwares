#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void crd();
void crsd();
void del();
void create();
void print();



struct node
{
   char dn[20];
   char d[20][20];
   struct node* link[20];
   int nu;
   int du;
}*r,*pa,*n;

int m=0,I;
void create1(struct node *);
struct node* search(char [],char s1[]);
struct node* searchs(char [],char s1[]);

main()
{
    int i,j,n,ch;
    char s[20],s1[20];
    struct node*t;
    r=(struct node *)malloc(sizeof(struct node));
    pa=r;
    if(r==NULL)
    {
      printf("\n root not created");
      return 0;
    }
    
    printf("\n root created");
    
   do
   {
     printf("\n Menu \n 1.create a directory \n 2.create subdirectory \n 3.create files \n 4.delete \n 5.search for file in directory \n 6.search for file in subdirectory\n 7.display \n 8.exit \n enter the choice  ");
     scanf("%d",&ch);
     if(ch==8)
        break;
     switch(ch)
     {
         case 1:crd();
               break;
         case 2:crsd();
               break;
         case 3:create();
               break;
         case 4:del();
               break;            
         case 5:printf("\n enter the directory name and filename");
                scanf("%s",s);
                scanf("%s",s1);
                t=search(s,s1);
                if(t==NULL)
                   printf("\n directory doesnt exist");
          	 break;
         case 6:printf("\n enter the sub directory name and filename");
                scanf("%s",s);
                scanf("%s",s1);
                t=searchs(s,s1);
                if(t==NULL)
                   printf("\n directory doesnt exist");
                break;       
         case 7:print();
               break;      
              
                                    
     }
     
   }while(1);
     
}

void crd()
{
       struct node* n=(struct node *)malloc(sizeof(struct node));
       n->du=n->nu=0;
       if(n==NULL)
          {
             printf("\n directory not created");
             return;
          }
       printf("\n enter the directory name ");
       scanf("%s",n->dn);
       r->link[m++]=n;
              
}

void crsd()
{
       int l; 
       char s[25];
       struct node *t,*n; 
       n=(struct node *)malloc(sizeof(struct node));
       n->du=n->nu=0;
       if(n==NULL)
          {
             printf("\n directory not created");
             return;
          }
       printf("\n enter the directory name for which we need to create a subdirectory ");
       scanf("%s",s);
       t=search(s,"NULL");
       if(t==NULL)
       {
          printf("\n directory doesnt exist");
          return;
       }     
     
       printf("\n enter the name of the subdirectory ");
       scanf("%s",n->dn);
       
       l=t->du;
       t->link[l]=n;
       ++t->du;
     
}

void create()
{
       int i,ch;
       char s[20];
       struct node *t,*n;
       printf("\n enter 0 to create files in directory / 1 to create files in sub directory ");
       scanf("%d",&ch);
       if(ch==0)
       {
       printf("\n enter the directory name ");
       scanf("%s",s);
       t=search(s,"NULL");
       if(t==NULL)
       {
          printf("\n directory doesnt exist");
          return;
       }       
       create1(t);
      
       printf("\n created files  in %s directory ",t->dn);
       }
       
       if(ch==1)
       {
          printf("\n enter the subdirectory name ");
          scanf("%s",s);
          t=searchs(s,"NULL");
          if(t==NULL)
          {
            printf("\n directory doesnt exist");
            return;
          }       
          create1(t);
      
          printf("\n created files  in %s directory ",t->dn);
       }
    
    print();   
}

void create1(struct node *n)
{
   char s[25];
   int j,l;
   printf("\n enter the number of files ");
   scanf("%d",&l);
   
   for(j=0;j<l;++j)
   {
     printf("\n enter the filenames ");
     scanf("%s",n->d[(n->nu)+j]);
   }
           
   n->nu+=l;        
}

void del()
{
   char s[25],s1[25],s2[23];
   int i,j,fl=0,k,ch;
   struct node *t,*p,*n;
   printf("\n Deletion \n 0.directory \n 1.file of directory\n 2.file of subdirectory\n 3.subdirectory \n 4.root");
   scanf("%d",&ch);
   if(ch==0)
   {
   printf("\n enter the directory to be deleted ");
   scanf("%s",s);
   p=search(s,"NULL");
   if(p==NULL)
       {
          printf("\n directory doesnt exist");
          return;
       }     
           
           --m;
           printf("\n %s has been deleted",s);
           for(j=0;j<p->du;++j)
               free(p->link[j]);
           free(p);
           for(j=I;j<m;++j)
               pa->link[j]=pa->link[j+1];
             
           
           print();        
           
    }  
   else if(ch==1)
   {
     printf("\n enter directory name and filename ");
     scanf("%s",s);
     scanf("%s",s1);
     n=search(s,"NULL");
     if(n==NULL)
      {
         printf("\n directory not found");
         return;
      }
     for(j=0;j<n->nu;++j)
          
       if(strcmp(s1,n->d[j])==0)
             {
               fl=1;
               --n->nu;
               printf("\n %s has been deleted",s1);
               for(k=j;k<n->nu;++k)
                  strcpy(n->d[k],n->d[k+1]);
               print();
               break; 
             }         
           
             
    if(fl==0)
     printf("\n File Not found");
           
   }  
   
   else if(ch==4)
   { 
      printf("root deleted");
      for(i=0;i<m;++i)
       {
         n=r->link[i];
         for(j=0;j<n->du;++j)
           free(n->link[j]);
         free(n);
       }
      free(r);   
      r=NULL;
   }
   else if(ch==2)
   {
     printf("\n enter sub directory name and filename ");
     scanf("%s",s);
     scanf("%s",s1);
     n=searchs(s,"NULL");
     if(n==NULL)
      {
         printf("\n directory not found");
         return;
      }
     for(j=0;j<n->nu;++j)
          
       if(strcmp(s1,n->d[j])==0)
             {
               fl=1;
               --n->nu;
               printf("\n %s has been deleted",s1);
               for(k=j;k<n->nu;++k)
                  strcpy(n->d[k],n->d[k+1]);
               print();
               break; 
             }         
           
             
    if(fl==0)
     printf("\n File Not found");
   
   }
   else if(ch==3)
   {
   printf("\n enter the sub directory to be deleted");
   scanf("%s",s);
   p=searchs(s,"NULL");
   if(p==NULL)
       {
          printf("\n directory doesnt exist");
          return;
       }     
           
           --pa->du;
           printf("\n %s has been deleted",s);
          
           free(p);
           for(j=I;j<pa->du;++j)
               pa->link[j]=pa->link[j+1];
             
           
           print();        
          
    }  
   
           
}

           
void print()
{ 
    int i,j,k; 
    struct node* n; 
    if(r==NULL)
    {
       printf("\n root deleted");
       return;
    }
    printf("\n root");   
    for(i=0;i<m;++i)
    {
      n=r->link[i];
      printf("\n directory is: %s \n files are:",n->dn);
      for(j=0;j<n->nu;++j)
        printf("\n %s",n->d[j]);
      if(n->du==0)
         continue;  
      
      for(j=0;j<n->du;++j)
        {
          printf("\n    subdirectories of %s :",n->dn);
          printf("\t%s\n  files are:",n->link[j]->dn);
           for(k=0;k<n->link[j]->nu;++k)
               printf("\n\t\t%s",n->link[j]->d[k]);
        }       
    }    
       
}

struct node * search(char s[],char s1[])
{
    
     int i,fl=0,j;
     struct node*n; 
     for(i=0;i<m;++i)
     {
      fl=0; 
      n=r->link[i];
      if(strcmp(s,n->dn)==0)
        {
          if(strcmp(s1,"NULL")==0)
           {
             pa=r;
             I=i;
             return n;
           }
          for(j=0;j<n->nu;++j)
          
            if(strcmp(s1,n->d[j])==0)
             {
               fl=1;
             
               printf("Found");
               print();
               return n; 
                
             }         
           
          break;   
        } 
    }      
   if(i==m) 
      return NULL;     
   else if(fl==0)
     printf("\n File Not found");
}

struct node * searchs(char s[],char s1[])
{
    
     int i,fl=0,j,k;
     struct node* n; 
     for(i=0;i<m;++i)
     {
       fl=0; 
       n=r->link[i];
       for(k=0;k<n->du;++k)
         
        if(strcmp(s,n->link[k]->dn)==0)
         {
          if(strcmp(s1,"NULL")==0)
           {
             pa=n;
             I=k;
             return n->link[k];
           }
          for(j=0;j<n->link[k]->nu;++j)
          
            if(strcmp(s1,n->link[k]->d[j])==0)
             {
               fl=1;
             
               printf("Found");
               print();
               return n; 
                
             }         
           
          break;   
        } 
   
   }       
   if(i==m) 
      return NULL;     
   else if(fl==0)
     printf("\n File Not found");
}


