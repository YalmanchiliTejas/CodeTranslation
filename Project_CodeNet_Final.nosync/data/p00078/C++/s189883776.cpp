#include <stdio.h>

int main(){
    int n;
    int mgcSq[15][15];
    int x,y;
    
    while(scanf("%d",&n)!=EOF){
        x = y = n/2;
        y++;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                mgcSq[j][i]=0;
            }
        }
 
        for (int i=1; i<=n*n; i++){
            mgcSq[x][y]=i;
            x = (x+1)%n;
            y = (y+1)%n;
            if (mgcSq[x][y]){
                x = (x+n-1)%n;
                y = (y+1)%n;
            }
        }
        
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                printf("%4d",mgcSq[j][i]);
            }
            printf("\n");
        }
    }
 
    return 0;
}