#include <stdio.h>
int main(){
    int n,a[100][100],x,y,now;
    while(1){
        scanf("%d",&n);
        if(n==0)return 0;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=0;
        x=n/2+1;
        y=n/2;
        now=1;
        while(now<=n*n){
            if(a[x][y]!=0){
                x++;
                y--;
            }
            x=(x+n)%n;
            y=(y+n)%n;
            //printf("%d %d\n",x,y);
            a[x][y]=now;
            x++;
            y++;
            x=(x+n)%n;
            y=(y+n)%n;
            now++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)printf("%4d",a[i][j]);
            printf("\n");
        }
    }
}