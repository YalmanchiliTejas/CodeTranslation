#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#define fir first
#define sec second
using namespace std;
typedef long long ll;
const int maxn = 3e3+7;
const ll mod = 998244353;


int n,s;
int a[maxn];
ll dp[maxn][maxn];


int main() {
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=s;j++) {
            if(j<a[i]) dp[i][j] = dp[i-1][j]%mod;
            else if(j == a[i]) dp[i][j] = (dp[i-1][j] + i)%mod;
            else dp[i][j] = (dp[i-1][j-a[i]] + dp[i-1][j])%mod;
        }
        ans += dp[i][s];
        ans %= mod;
    }
    printf("%lld\n",ans);
    return 0;
}