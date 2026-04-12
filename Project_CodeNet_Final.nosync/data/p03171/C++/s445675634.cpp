
#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
 
using namespace std;
#define rep(i,a,b) for (ll i = a; i < b; i++)
#define rrep(i,a,b) for (ll i = a; i >= b; i--)
#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
 
using namespace std;
#define rep(i,a,b) for (ll i = a; i < b; i++)
#define rrep(i,a,b) for (ll i = a; i >= b; i--)
#define l(s) s.length()
#define sort(v) sort(v.begin(), v.end());
#define scan(v,n) rep(i,0,n) {ll k; cin >> k; v.pb(k);}
#define print(v,n) {rep(i,0,n) cout << v[i] << " "; cout << endl;}
#define printstr(s,n) {rep(i,0,n) cout << s[i]; cout << endl;}
#define rev(a) reverse(a.begin(), a.end());
#define pb push_back
typedef long long ll;
typedef long double lld;
typedef vector<pair<ll,ll>> vpi;
typedef vector<ll> vi;
 
const ll mxN=3e3;
const ll N=1e9+7;
 
ll dp[mxN+1][mxN+1];

//deque
//assume that we start the game with the array from index l to r. 
// then, dp[l][r] is the max possible difference bw the scores of the player who goes first and the one who goes second
//obviously, for a single element array, the diff is the element itself
// we want dp[0][l-1]
// why reverse loop for variable l and forward loop for r though? BECAUSE THE DP EXPRESSION USES L+1 AND R-1
//TO DETERMINE DP[L][R],
// SO NATURALLY YOU NEED INFO ABOUT L+1 BEFORE L AND INFO ABOUT R-1 BEFORE R!!!


  int main() {
      int T=1;// cin >> T;
      while(T--){
          ll n; cin >> n;
          vi v; scan(v,n);
          rep(i,0,n) dp[i][i]=v[i];
          rrep(l,n-2,0) {
              rep(r,l+1,n) {
                  dp[l][r]=(v[l]-dp[l+1][r]>v[r]-dp[l][r-1]?v[l]-dp[l+1][r]:v[r]-dp[l][r-1]);
              }
          }
          cout << dp[0][n-1];
      } 
	 return 0;
}
