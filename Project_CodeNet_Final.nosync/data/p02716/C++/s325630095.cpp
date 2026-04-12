#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

ll dp[200010][3];

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,200010)rep(j,3) dp[i][j] = -LINF;
    dp[1][0] = a[0];
    dp[2][1] = a[1];
    if(n >= 3) dp[3][2] = a[2];
    rep(i,n+1)rep(j,3){
        if(i-2 >= 1 && dp[i-2][j] != -LINF) dp[i][j] = max(dp[i][j],dp[i-2][j]+a[i-1]);
        if(j >= 1){
            if(i-3 >= 1 && dp[i-3][j-1] != -LINF) dp[i][j] = max(dp[i][j],dp[i-3][j-1]+a[i-1]);
        }
        if(j == 2){
            if(i-4 >= 1 && dp[i-4][j-2] != -LINF) dp[i][j] = max(dp[i][j],dp[i-4][j-2]+a[i-1]);
        }
    }
    ll ans = -LINF;
    if(n%2 == 0){
        ans = max({ans,dp[n-1][0],dp[n][1]});
    }
    else{
        ans = max({ans,dp[n-2][0],dp[n-1][1],dp[n][2]});
    }
    cout << ans << endl;
} 


