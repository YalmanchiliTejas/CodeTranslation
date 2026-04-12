#include "bits/stdc++.h"
#define hhh cerr<<"hhh"<<endl
#define see(x) cerr<<(#x)<<'='<<(x)<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
inline int read() {int x=0,f=1;char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}

const int maxn = 3e3+7;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int n, s;
ll a[maxn], dp[maxn];

int main() {
    n=read(), s=read();
    for(int i=1; i<=n; ++i) a[i]=read();
    ll res=0;
    for(int i=1; i<=n; ++i) {
        for(int j=s; j>=a[i]; --j) {
            if(j==a[i]) dp[j]=(dp[j]+i)%mod;
            else dp[j]=(dp[j]+dp[j-a[i]])%mod;
        }
        res=(res+dp[s])%mod;
    }
    cout<<res<<endl;
}