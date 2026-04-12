#include <stdio.h>

int main(){
    char input[100][101];
    int pass[100],i,j,h,w;
    
    scanf("%d %d",&h,&w);
    for(i = 0; i < h; i++){
        scanf("%s",input[i]);
    }
    for(i = 0; i < w; i++){
        for(j = 0; j < h; j++){
            if(input[j][i] != '.')
                break;
        }
        pass[i] = (j == h);        
    }
    for(i = 0; i < h; i++){
        for(j = 0; j < w; j++){
            if(input[i][j] != '.')
                break;     
        }
        if(j == w) continue;
        
        for(j = 0; j < w; j++){
            if(pass[j]) continue;
            printf("%c",input[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}