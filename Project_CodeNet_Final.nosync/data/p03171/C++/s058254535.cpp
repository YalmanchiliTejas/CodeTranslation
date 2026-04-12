#include <map>
#include <set>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
//#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
#define PB push_back
#define MP make_pair
#define INF 1073741824
#define inf 1152921504606846976
#define pi 3.14159265358979323846
//#pragma comment(linker,"/STACK:10240000,10240000")
//mt19937 rand_(time(0));
const int N=3e5+7,M=2e6;
const long long mod=1e9+7;
inline int read(){int ret=0;char ch=getchar();bool f=1;for(;!isdigit(ch);ch=getchar()) f^=!(ch^'-');for(;isdigit(ch);ch=getchar()) ret=(ret<<1)+(ret<<3)+ch-48;return f?ret:-ret;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll ksm(ll a,ll b,ll mod){int ans=1;while(b){if(b&1) ans=(ans*a)%mod;a=(a*a)%mod;b>>=1;}return ans;}
ll inv2(ll a,ll mod){return ksm(a,mod-2,mod);}//逆元
//int head[N],NEXT[M],ver[M],tot;void link(int u,int v){ver[++tot]=v;NEXT[tot]=head[u];head[u]=tot;}

int n;
ll dp[3100][3100][3];
ll a[3100];
void dfs(int x,int y){
    int tmp=n-y+x-1;
//    cout<<tmp<<' '<<x<<' '<<y<<endl;
    if(x==y) {
        if(tmp%2==0) dp[x][x][0]=a[x],dp[x][x][1]=0;
        else dp[x][x][1]=a[x],dp[x][x][0]=0;
        return ;
    }
    if(dp[x][y][1]!=-1&&dp[x][y][0]!=-1) return ;
    dfs(x+1,y);
    dfs(x,y-1);
    if(tmp%2==0){
        if(dp[x+1][y][0]+a[x]-dp[x+1][y][1]>dp[x][y-1][0]+a[y]-dp[x][y-1][1]){
            dp[x][y][0]=dp[x+1][y][0]+a[x];
            dp[x][y][1]=dp[x+1][y][1];
        }
        else {
            dp[x][y][0]=dp[x][y-1][0]+a[y];
            dp[x][y][1]=dp[x][y-1][1];
        }
    }
    else {
        if(dp[x+1][y][1]+a[x]-dp[x+1][y][0]>dp[x][y-1][1]+a[y]-dp[x][y-1][0]){
            dp[x][y][1]=dp[x+1][y][1]+a[x];
            dp[x][y][0]=dp[x+1][y][0];
        }
        else {
            dp[x][y][1]=dp[x][y-1][1]+a[y];
            dp[x][y][0]=dp[x][y-1][0];
        }
    }
}
int main(){
    //freopen("1.txt","r",stdin);
    //ios::sync_with_stdio(false);
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    dfs(1,n);
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++) cout<<dp[i][j][0]<<' '<<dp[i][j][1]<<endl;
//        cout<<endl;
//    }
    printf("%lld\n",dp[1][n][0]-dp[1][n][1]);
    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}


