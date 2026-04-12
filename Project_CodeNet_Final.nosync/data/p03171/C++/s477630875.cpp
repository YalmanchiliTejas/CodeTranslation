#include <bits/stdc++.h>
using namespace std;
// Macros for easier access
#define ll long long
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define test ll cases; cin>>cases; for(ll testCase = 1; testCase <= cases; testCase++)   //test cases
#define fill(name, val) memset(name, val, sizeof(name));
#define mop(a, op, b)    (a%mod op b%mod)%mod
#define error(x) fixed<<setprecision(x) //cout<<error(5)<<someDouble    -> example - 3.14159
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define get(a, n)    for(ll i = 0; i < n; i++)    cin>>a[i];
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug(x) cerr << #x << " : " << (x) << endl
// Constants
#define MX 100001
#define mod 1000000007LL
#define inf 1000000000000000000LL
void init(){
    boost;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

/*
    Author: 
                                                _/                      
       _/_/_/_/    _/_/    _/_/_/      _/_/    _/  _/    _/    _/_/_/   
          _/    _/_/_/_/  _/    _/  _/    _/  _/  _/    _/  _/_/        
       _/      _/        _/    _/  _/    _/  _/  _/    _/      _/_/     
    _/_/_/_/    _/_/_/  _/    _/    _/_/    _/    _/_/_/  _/_/_/        
                                                           
    National Institute of Technology, Rourkela (2018-2022, EE)
*/

ll n, a[MX];
ll dp[3001][3001];
ll solve(ll l, ll r, bool taro){
    if(l > r)   return 0;
    if(dp[l][r] != -1)  return dp[l][r];
    ll op1 = a[l] * (taro?1:-1) + solve(l+1, r, !taro);
    ll op2 = a[r] * (taro?1:-1) + solve(l, r-1, !taro);
    return dp[l][r] = taro?max(op1, op2):min(op1, op2);
}
int main(){
    cin>>n; get(a, n);
    fill(dp, -1);
    cout<<solve(0, n-1, 1);
    // ll dp[n+1][n+1];    fill(dp, 0);
    // for(ll l = 0; l < n; l++){
    //     for(ll r = 0; r < n; r++){
    //         if(l > r)  continue;
    //         bool taro = (r-l+1)&1 == n&1;
    //         if(l == r)  dp[l][r] = a[l] * (taro?1:-1);

    //     }
    // }
}