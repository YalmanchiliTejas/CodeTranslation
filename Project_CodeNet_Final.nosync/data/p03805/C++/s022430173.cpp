#pragma comment(linker, "/STACK:102400000,102400000")
#include<algorithm>
#include<iostream>
#include<cstring>
#include<fstream>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define INF 0X3F3F3F3F
#define N 200010
#define M 2000100
#define LL long long
#define FF(i,a,b) for(int i=a;i<=b;++i)
#define RR(i,a,b) for(int i=a;i>=b;--i)
#define FJ(i,a,b) for(int i=a;i<b;++i)
#define SC(x) scanf("%d",&x)
#define SCC(x,y) scanf("%d%d",&x,&y)
#define SCCC(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define SS(x) scanf("%s",x)
#define PR(x) printf("%d\n",x)
#define CL(a,b) memset(a,b,sizeof(a))
#define FD T&q=fd[rt],&ql=fd[rt<<1],&qr=fd[rt<<1|1]
#define MID int mid=((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define zero(x) (((x)>0?(x):-(x))<EPS)
#define PB push_back
#define SZ size
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define MP make_pair
#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)
using namespace std;
const int MOD=1000000007;
const double PI=acos(-1.0);
const double EPS=1e-8;
inline int II(){int n=0,ch=getchar();bool t=0;if(ch==-1)return 0;
for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')t=1;
for(;ch>='0'&&ch<='9';n=n*10+ch-'0',ch=getchar());if(t)return -n;return n;}
inline void OO(int a){if(a<0){putchar('-');a=-a;}
if(a>=10)OO(a/10);putchar(a%10+'0');}
inline int sgn(double x){return(x>EPS)-(x<-EPS);}
struct edge{int v,nx;}E[M*2+N*2];int head[N],EN;
void init_edge(){EN=0;CL(head,-1);}
void add_edge(int u,int v){
    E[EN]=(edge){v,head[u]};head[u]=EN++;
    E[EN]=(edge){u,head[v]};head[v]=EN++;
}
int n,m;
int ans=0;
bool vis[11];
void go(int u,int tot){
    if(tot==n){
        ++ans;
        return ;
    }
    for(int k=head[u];~k;k=E[k].nx){
        int v=E[k].v;
        if(!vis[v]){
            vis[v]=1;
            go(v,tot+1);
            vis[v]=0;
        }
    }
    return ;
}
int main(){
    int a,b;
   // IN;
    SCC(n,m);
    init_edge();
    FF(i,1,m){
        SCC(a,b);
        add_edge(a,b);
     //   add_edge(b,a);
    }
    CL(vis,0);
    vis[1]=1;
    go(1,1);
    PR(ans);
    return 0;
}
