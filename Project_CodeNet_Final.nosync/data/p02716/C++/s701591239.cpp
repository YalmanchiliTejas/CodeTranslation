#include "bits/stdc++.h"
#define hhh cerr<<"hhh"<<endl
#define see(x) cerr<<(#x)<<'='<<(x)<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
inline int read() {int x=0,f=1;char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}

const int maxn = 3e5+7;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

int n;
int a[maxn];
ll dp[maxn][10][2];

int main() {
    n=read();
    for(int i=1; i<=n; ++i) a[i]=read();
    memset(dp,-inf,sizeof(dp));
    dp[0][5][0]=0;
    for(int i=1; i<=n; ++i) {
        for(int j=0; j<10; ++j) {
            if(j+1<10) {
                dp[i][j+1][1]=max(dp[i][j+1][1],dp[i-1][j][0]+a[i]);
            }
            if(j) {
                dp[i][j-1][0]=max({dp[i][j-1][0],dp[i-1][j][0],dp[i-1][j][1]});
            }
        }
    }
    cout<<max(dp[n][5-(n&1)][0],dp[n][5-(n&1)][1])<<endl;
}