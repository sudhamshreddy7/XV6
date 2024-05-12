#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include <unistd.h>

// uniq file1
// uniq -i file1
// uniq -d file1
// uniq -c file1 
int strCASEcmp(char a[1024],char b[1024],int size){
    int i=0;
    while(i<size){
        char f = a[i];
        char l = b[i];
        i++;
        if(f==l||f+('a'-'A')==l||f-('a'-'A')==l)
            continue;
        
        return 1;
    }
    return 0;
}
void uniqBase(int file){
    char a[1024],b[1024];
    int aPointer=0,bPointer=0;
    
    if(file<0)
    return;
    char x;
    int count =read(file,&x,1);
    for(int i=0;i<1024;i++){
        a[i]='\0';
        b[i]='\0';
    }
    while(count&&x!='\n'){
        a[aPointer++]=x;
        count=read(file,&x,1);
    }
    printf("%s\n",a);
    count=read(file,&x,sizeof(x));
    while(count){
        while(count&&x!='\n'){
            b[bPointer++]=(char)x;
           // printf("%c\n",x);
            count= read(file,&x,sizeof(x));
        }
        
        if(!strcmp(a,b)){//both are same
            for(int i=0;i<1024;i++){
                b[i]='\0';
            }
            bPointer=0;
        }
        else{
            printf("%s\n",b);
            for(int i=0;i<1024;i++){
                a[i]=b[i];
                b[i]='\0';
            }
            aPointer=0;
            bPointer=0;
        }
        count=read(file,&x,1);
    }
    return ;

}
void uniqD(int file){
    char a[1024],b[1024];
    int aPointer=0,bPointer=0;
    int num =1;
    if(!file)
    return;
    char x;
    int count =read(file,&x,1);
    for(int i=0;i<1024;i++){
        a[i]='\0';
        b[i]='\0';
    }
    while(count&&x!='\n'){
        a[aPointer++]=x;
        count=read(file,&x,1);
    }
    // printf("%s\n",a);
    count=read(file,&x,sizeof(x));
    while(count){
        while(count&&x!='\n'){
            b[bPointer++]=(char)x;
           // printf("%c\n",x);
            count= read(file,&x,sizeof(x));
        }
        
        if(!strcmp(a,b)){//both are same
            for(int i=0;i<1024;i++){
                b[i]='\0';
            }
            num++;
            bPointer=0;
        }
        else{
            if(num>1)
            printf("%s\n",a);
            for(int i=0;i<1024;i++){
                a[i]=b[i];
                b[i]='\0';
            }
            num=1;
            aPointer=0;
            bPointer=0;
        }
        count=read(file,&x,1);
    }
    if(num>1)
            printf("%s\n",a);
    return ;

    
}
void uniqC(int file){
        char a[1024],b[1024];
    int aPointer=0,bPointer=0;
    int num =1;
    if(!file)
    return;
    char x;
    int count =read(file,&x,1);
    for(int i=0;i<1024;i++){
        a[i]='\0';
        b[i]='\0';
    }
    while(count&&x!='\n'){
        a[aPointer++]=x;
        count=read(file,&x,1);
    }
    // printf("%s\n",a);
    count=read(file,&x,sizeof(x));
    while(count){
        while(count&&x!='\n'){
            b[bPointer++]=(char)x;
           // printf("%c\n",x);
            count= read(file,&x,sizeof(x));
        }
        
        if(!strcmp(a,b)){//both are same
            for(int i=0;i<1024;i++){
                b[i]='\0';
            }
            num++;
            bPointer=0;
        }
        else{
           
            printf("%d\t%s\n",num,a);
            for(int i=0;i<1024;i++){
                a[i]=b[i];
                b[i]='\0';
            }
            num=1;
            aPointer=0;
            bPointer=0;
        }
        count=read(file,&x,1);
    }
    
    printf("%d\t%s\n",num,a);
    return ;



    
    
    return;
}
void uniqI(int file){
    char a[1024],b[1024];
    int aPointer=0,bPointer=0;
   
    if(!file)
    return;
    char x;
    int count =read(file,&x,1);
    for(int i=0;i<1024;i++){
        a[i]='\0';
        b[i]='\0';
    }
    while(count&&x!='\n'){
        a[aPointer++]=x;
        count=read(file,&x,1);
    }
    printf("%s\n",a);
    count=read(file,&x,sizeof(x));
    while(count){
        while(count&&x!='\n'){
            b[bPointer++]=(char)x;
            count= read(file,&x,sizeof(x));
        }
       // printf("%s\t%s\t%d\n",a,b,strCASEcmp(a,b,aPointer));
        if(aPointer==bPointer&&!strCASEcmp(a,b,aPointer)){//both are same
            for(int i=0;i<1024;i++){
                b[i]='\0';
            }
            bPointer=0;
        }
        else{
            printf("%s\n",b);
            for(int i=0;i<1024;i++){
                a[i]=b[i];
                b[i]='\0';
            }
            aPointer=bPointer;
            bPointer=0;
        }
        count=read(file,&x,1);
    }
    return ;

    return;
}
int main(int argc,char *args[]){
    printf("Uniq command is getting executed in user mode.\n");
    if(argc==1){
        uniqBase(0);
        return 0;
    }
    if(argc==2){
       // printf("%s",args[1]);
        uniqBase(open(args[1],O_RDONLY));
        return 0;
    }
    switch (args[1][1])
    {
    case 'i':
        // printf("I\n");
        uniqI(open(args[2],O_RDONLY));
        break;
    case 'd':

        
        uniqD(open(args[2],O_RDONLY));
        break;
    case 'c':
    // printf("C\n");
        uniqC(open(args[2],O_RDONLY));
        break;
    
    default:
        break;
    }

    return 0;

}