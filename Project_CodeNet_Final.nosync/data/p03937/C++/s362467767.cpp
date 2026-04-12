#include<cstdio>

#define MAXN 8
int H,W;
char Map[MAXN+5][MAXN+5];

int main(){
    scanf("%d%d",&H,&W);
    for(int i=1;i<=H;i++)
        scanf("%s",Map[i]+1);
    for(int i=1;i<=H;i++)
        for(int j=1;j<=W;j++){
            if(Map[i][j]!='#')
                continue;
            if(Map[i][j-1]=='#'&&Map[i-1][j]=='#'){
                puts("Impossible");
                return 0;
            }
            if(i==H&&j==W)
                break;
            if((Map[i][j+1]=='#'&&Map[i+1][j]=='#')||(Map[i][j+1]!='#'&&Map[i+1][j]!='#')){
                puts("Impossible");
                return 0;
            }
        }
    puts("Possible");
}
