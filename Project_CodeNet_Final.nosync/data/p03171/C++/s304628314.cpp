/*
    if you can't see the repay
    Why not just work step by step
    rubbish is relaxed
    to ljq
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define lc (rt<<1)
#define rc (rt<<11)
#define mid ((l+r)>>1)

typedef pair<int,int> pll;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int _inf = 0xc0c0c0c0;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll _INF = 0xc0c0c0c0c0c0c0c0;
const ll mod =  (int)1e9+7;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll ksm(ll a,ll b,ll mod){int ans=1;while(b){if(b&1) ans=(ans*a)%mod;a=(a*a)%mod;b>>=1;}return ans;}
ll inv2(ll a,ll mod){return ksm(a,mod-2,mod);}
void exgcd(ll a,ll b,ll &x,ll &y,ll &d){if(!b) {d = a;x = 1;y=0;}else{exgcd(b,a%b,y,x,d);y-=x*(a/b);}}//printf("%lld*a + %lld*b = %lld\n", x, y, d);
const int MAX_N = 3005;
ll dp[MAX_N][MAX_N],arr[MAX_N];
int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;++i) scanf("%d",&arr[i]);
    for(int L = n;L>=1;--L)
    {
        for(int R = L;R<=n;++R)
        {
            dp[L][R] = max(arr[L]-dp[L+1][R],arr[R]-dp[L][R-1]);
        }
    }
    printf("%lld\n",dp[1][n]);
    //fclose(stdin);
    //fclose(stdout);
    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
