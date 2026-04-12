
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
//dp[i][j][2] is the score of each player when the remaining array is from index i to j
// dp[0][n-1]=0
//rep(i,1,n+1) cout max of dp[i][i-1][1]



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
