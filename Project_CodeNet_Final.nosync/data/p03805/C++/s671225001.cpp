#include<cstdio>
#include<algorithm>
int main(){
    int n,m,g[9][9],p[8]={1,2,3,4,5,6,7,8},ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        int j,k;
        scanf("%d%d",&j,&k);
        g[j][k]=1;
        g[k][j]=1;
    }
    do{
        int i=0;
        while(i<=n-2){
            if(g[p[i]][p[i+1]]==0)break;
            i++;
        }
        if(i==n-1)ans++;
    }while(std::next_permutation(p+1,p+n));
    printf("%d",ans);
    return 0;
}