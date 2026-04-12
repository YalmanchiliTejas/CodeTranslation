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
#include<numeric>
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


int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n+1);
    rep(i,n){
        sum[i+1] = sum[i]+a[i];
        sum[i+1] %= MOD;
    }
    ll ans = 0;
    rep(i,n-1){
        ans += a[i]*(sum[n]-sum[i+1])%MOD;
        ans %= MOD;
        if(ans < 0) ans += MOD;
    }
    cout << ans << endl;
}

