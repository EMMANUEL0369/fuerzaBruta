#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void buscarLlave(char *argv[]){
    int op=0, num = 0;
    char hexa[33];
    for(int j=1; j<256; j++){
        for(int i=2; i<18; i++){
            num =(int)strtol(argv[i], NULL, 16);
            op=num^j;
            sprintf(&hexa[(i-2)*2],"%02x",op);
        }
        if(strstr(hexa,"4d5a")){
            printf("%d", j);
        }
    }
}

void descifrar(int key, char *argv[]){
    int op=0, num = 0;
    char hexa[2];
    for(int i=2; i<18; i++){
        num =(int)strtol(argv[i], NULL, 16);
        op=num^key;
        printf("%c",op);
    }
}

int main(int argc, char *argv[]){
    char *ptr;
    int key = strtol(argv[1], &ptr, 10);
    if(key==0){
        buscarLlave(argv);
    }else{
        descifrar(key,argv);
    }
    return 0;
}