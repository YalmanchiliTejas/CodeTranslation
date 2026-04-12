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
int main(){
    cin>>n; for(ll i = 1; i <= n; i++)  cin>>a[i];
    ll dp[2][n+1];    fill(dp, 0);
    for(ll l = n; l > 0; l--){
        for(ll r = 1; r <= n; r++){
            if(l > r)   continue;
            bool taro = ((r-l+1)&1) == (n&1);
            ll op1 = a[l] * (taro?1:-1) + dp[(l+1)%2][r];
            ll op2 = a[r] * (taro?1:-1) + dp[l%2][r-1];
            dp[l%2][r] = taro ? max(op1, op2) : min(op1, op2);
        }
    }
    cout<<dp[1][n];
}