#include<bits/stdc++.h>
using namespace std;    
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
#define PI 3.1415926535897932384626433832795
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define trav(x,v) for (auto &x : v)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define pv(v) trav(x, v) cout << x << " "; cout << endl; // print vector/array
#define pvv(vv) trav(xx, vv){pv(xx);} // print 2-d vector/2-d array
#define pm(m) trav(x, m) cout << x.F << ":" << x.S << " "; cout << endl; //print map/lookup table

const int MOD = 1000000007;
ll dp[3005][3005];
ll solve(ll i, ll j, vector<ll> &v, bool flag){
    if(i==j) return flag?v[i]:0;
    if(dp[i][j] != 0)return dp[i][j];
    if(flag){
        dp[i][j]  = max(solve(i+1, j, v, !flag) + v[i], solve(i, j-1, v, !flag) + v[j]);
    }
    else{
        dp[i][j]  = min(solve(i+1, j, v, !flag) , solve(i, j-1, v, !flag));
    }
    return dp[i][j];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, 0, sizeof(dp));
    ll n;
    cin >> n;
    vector<ll> v(n);
    F0R(i, n) cin >> v[i];
    ll sum = 0, ret = solve(0, n-1, v, true); 
    F0R(i, n) sum += v[i];
    cout << 2*ret - sum;
    return 0;
}