#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#define clr(x,y) memset(x,y,sizeof(x))
using namespace std;

int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char g[60][60];
int x[1005],y[1005];
int a[60][60],b[60][60],c[60][60];
bool vis[60][60];
int n,m,k,i,j,T,ex,ey;
vector<int> vc[60][60];

bool dfs(int x,int y,int t){
    if(vis[x][y]) return false;
    vis[x][y]=true;
    if(x==ex&&y==ey){
        T=t;
        return true;
    }
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<0||xx>=n||yy<0||yy>=m||g[xx][yy]=='#') continue;
        if(dfs(xx,yy,t+1)){
            vc[x][y].push_back(t);
            return true;
        }
    }
    return false;
}
int main(){
//    freopen("in.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++) scanf("%s",g[i]);
    for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&b[i][j]);
    for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&a[i][j]);
    for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&c[i][j]);

    T=0;
    for(i=1;i<=k;i++){
        clr(vis,0);
        scanf("%d%d",&x[i],&y[i]);
        ex=x[i],ey=y[i];
        if(i==1) continue;
        dfs(x[i-1],y[i-1],T);
    }
    vc[x[k]][y[k]].push_back(T);
    int ans=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(vc[i][j].size()==0) continue;
            ans+=a[i][j]+c[i][j];
            for(k=0;k<vc[i][j].size()-1;k++){
                int t1=(vc[i][j][k+1]-vc[i][j][k])*b[i][j];
                int t2=a[i][j]+c[i][j];
                ans+=min(t1,t2);
            }
        }
    }
//    for(i=0;i<n;i++){
//        for(j=0;j<m;j++){
//            printf("%d ",vc[i][j].size());
//        }
//        puts("");
//    }
    printf("%d\n",ans);
    return 0;
}