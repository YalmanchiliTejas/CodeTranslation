#include <stdio.h>

int main(){

    int n;
    int i;
    int h[20];
    int total = 0;
    int high=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&h[i]);
        if(high <= h[i]){
            high = h[i];
            total++;
        }
    }
    printf("\n");
    printf("%d",total);
}