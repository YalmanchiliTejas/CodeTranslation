#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=b-1; (ll)(a)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


ll dp[5000][5000], v[5000], n, flag[5000][5000];
ll calc(ll l, ll r){
    if(flag[l][r]) return dp[l][r];
    flag[l][r] = 1;
    if(l==r) return dp[l][r]=v[l];
    return dp[l][r] = max(v[l]-calc(l+1, r), v[r]-calc(l, r-1));
}
int main(){
    cin >> n;
    rep(i, n)   cin >> v[i+1];

    cout << calc(1, n) << endl;
}
