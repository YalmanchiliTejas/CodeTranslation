#include<stdio.h>
#include<algorithm>
using namespace std;
struct point{
    int x, y;
    bool operator<(const point &p)const{
        return x!=p.x?x<p.x:y<p.y;
    }
}w[110];
char p[10][10];
int n, m, cnt;
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%s",p[i]+1);
        for(j=1;j<=m;j++){
            if(p[i][j]=='#'){
                w[cnt].x=i,w[cnt].y=j,cnt++;
            }
        }
    }
    sort(w,w+cnt);
    for(i=0;i<cnt-1;i++){
        if(w[i].y > w[i+1].y){
            printf("Impossible\n");
            return 0;
        }
    }
    printf("Possible\n");
    return 0;
}
