#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main(void){
int N,H[100],count = 1;
    
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%d",&H[i]);
    }
    
    for(int i = 1; i < N; i++){
        for(int j = 0; j <= i - 1; j++){
        
            if(H[i] < H[j]){
                break;
                
            }else if(j == i-1){
                count++;
            }
        }
    
        
    }
    
    printf("%d",count);
    return 0;
}
