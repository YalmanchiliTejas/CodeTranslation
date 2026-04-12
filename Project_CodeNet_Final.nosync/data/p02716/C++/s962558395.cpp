#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define rep(i,a,b) for(int i = (a) ; i <= (b) ; i++)
#define per(i,a,b) for(int i = (a) ; i >= (b) ; i--)
#define mem(a) memset(a,0,sizeof(a))
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define fast_io ios::sync_with_stdio(false)

const int INF = 1e9;
const LL mod = 1e9 + 7;
const int maxn = 2e5 + 7;

LL dp[maxn];
LL a[maxn];
LL sum[maxn];

int main() {
    int n;
    while(~sd(n)) {
        rep(i,1,n) slld(a[i]);
        sum[1] = a[1];
        rep(i,1,n) {
            if(i & 1) sum[i] = sum[i-1] + a[i];
            else sum[i] = sum[i-1];
        }
        mem(dp);
        rep(i,2,n) {
            if(i & 1) dp[i] = max(dp[i-2] + a[i] , dp[i-1]);
            else dp[i] = max(dp[i-2] + a[i] , sum[i-1]);
        }
        plld(dp[n]);
    }
    return 0;
}
