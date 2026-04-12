#include <stdio.h>
int main(void){
    
    int h,w;
    scanf("%d %d",&h,&w);
    
    char moji[101][101];
    int i,j;
    for(i=0; i<h; ++i){
        scanf("%s",moji[i]);
    }
    
    
    int x[101],y[101];
    
    for(i=0; i<h; ++i){
        for(j=0; j<w; ++j){
            
            if(moji[i][j] == '.'){
                
                x[i]++;
                y[j]++;
            }
            
        }
    }
    
    
     for(i=0; i<h; ++i){
        for(j=0; j<w; ++j){
           if(x[i] != w && y[j] != h) printf("%c",moji[i][j]);
        }
        if(x[i] != w) printf("\n");
    }
    
    /*
    for(i=0; i<h; ++i){
        for(j=1; j<=w; ++j){
            if(j%w == 0)printf("%c\n",moji[i][j-1]);
            else printf("%c",moji[i][j-1]);
        }
    }
    */
   
   
    return 0;
}
