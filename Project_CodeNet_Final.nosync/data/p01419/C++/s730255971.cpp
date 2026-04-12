#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<bitset>
#define LL long long

const int MAXN=57;
const int MAXM=10007;
const long long LLINF=9000000000000000000;
const int INF=2000000000;//careful because of floyed and so on
const int MOD=1000000007;
double eps=0.00000001;

using namespace std;

struct Point{
    int x,y;
};

const int u[4]={0,0,1,-1};
const int w[4]={1,-1,0,0};

int n,m,q;
char s[MAXN][MAXN];
vector<int> t[MAXN][MAXN];
int on[MAXN][MAXN];
int off[MAXN][MAXN];
int cost[MAXN][MAXN];
int x[MAXM],y[MAXM];
bool vis[MAXN][MAXN];
int d[MAXN][MAXN];

void work(int bx,int by,int ex,int ey){
    queue<Point>Q;
    memset(vis,0,sizeof(vis));
    Q.push((Point){bx,by});
    d[bx][by]=t[bx][by][t[bx][by].size()-1];
    vis[bx][by]=1;
    while (!Q.empty()){
            Point now=Q.front();
            Q.pop();
            for (int i=0;i<4;i++){
                    int x=now.x+u[i];
                    int y=now.y+w[i];
                    if (x<=0 || y<=0 || x>n || y>m || s[x][y]=='#' || vis[x][y]) continue;
                    vis[x][y]=1;
                    d[x][y]=d[now.x][now.y]+1;
                    Q.push((Point){x,y});
            }
    }
    Q.push((Point){ex,ey});
    while (!Q.empty()){
            Point now=Q.front();
            if (now.x==bx && now.y==by) break;
            t[now.x][now.y].push_back(d[now.x][now.y]);
            Q.pop();
            for (int i=0;i<4;i++){
                    int x=now.x+u[i];
                    int y=now.y+w[i];
                    if (x<=0 || y<=0 || x>n || y>m || s[x][y]=='#' || d[x][y]!=d[now.x][now.y]-1) continue;
                    Q.push((Point){x,y});
            }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=n;i++){
            scanf("%s",s[i]+1);
    }
    for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                    scanf("%d",&cost[i][j]);
            }
    }
    for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                    scanf("%d",&on[i][j]);
            }
    }
    for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                    scanf("%d",&off[i][j]);
            }
    }
    for (int i=1;i<=q;i++){
            scanf("%d%d",&x[i],&y[i]);
            x[i]++;
            y[i]++;
    }
    t[x[1]][y[1]].push_back(0);
    for (int i=2;i<=q;i++){
            work(x[i-1],y[i-1],x[i],y[i]);
    }
    int ans=0;
    for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                    if (t[i][j].size()>=1){
                            ans=ans+on[i][j]+off[i][j];
                    }
                    for (int k=1;k<(int)t[i][j].size();k++){
                            ans+=min(on[i][j]+off[i][j],(t[i][j][k]-t[i][j][k-1])*cost[i][j]);
                    }
            }
    }
    printf("%d\n",ans);
    return 0;
}