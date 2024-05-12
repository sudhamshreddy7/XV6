#include <unistd.h>
#include<stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
int line=14;
int file =0;
void clearData(char* a,int size){
    for(int i=0;i<size;i++){
        a[i]='\0';
    }
}
void printData(){
    int size =1;

    int k =size-1;
    int n =0;
    int x =0;
    char buffer[1024];
    int bP=0;
    while(n<line){
    k = read(file,&x,1);
    
    while(k&&(char)x!='\n'){
        buffer[bP++]=(char)x;
        k = read(file,&x,1);
    }
    printf("%s\n",buffer);
    // clearData(&buffer,1024*sizeof(char));
    for(int i=0;i<bP;i++){
        buffer[i]='\0';
    }
    if(k==0)
    {
        return ;
    }
    bP=0;
    n++;
    }

}
int main(int argc,char* args[]){
    printf("Head command execution under user mode\n");
    if(argc==1){//head
        printData();
        return 0;
    }
    if(argc==2){//head file
        printf("===>%s<===\n",args[1]);
        file = open(args[1],O_RDONLY);
        printData();
        return 0;
    }
    if(strcmp("-n",args[1])==0){//head -n
        line = atoi(args[2]);
    }
    else{//head file file
        int i=1;
        while(i<argc){
            printf("===>%s<===\n",args[i]);
            file = open(args[1],O_RDONLY);
            //  printf("%d\n",file);
            printData();
            i++;
        }
        return 0;
    }
    if(argc==3){
        printData();
        return 0;
    }
    int i=3;
    while(i<argc){

            printf("===>%s<===\n",args[i]);
            file = open(args[i],O_RDONLY);
            // printf("%d\n",file);
            printData();
            i++;
        }
        return 0;


}