#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i=a; i<=b; i++)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, x;
vector<ll> a;
ll dp[3001][3001][2];

ll calc(int l, int r, int t){
	if(dp[l][r][t]!=-1) return dp[l][r][t];
	if(l==r) return dp[l][r][t]=(t?a[l]:-a[l]);

	if(t){
		if(a[l]+(dp[l+1][r][0]=calc(l+1, r, 0))>a[r]+(dp[l][r-1][0]=calc(l, r-1, 0))){
			return dp[l][r][t]=a[l]+dp[l+1][r][0];
		}
		else return dp[l][r][t]=a[r]+dp[l][r-1][0];
	}
	else{
		if(-a[l]+(dp[l+1][r][1]=calc(l+1, r, 1))<-a[r]+(dp[l][r-1][1]=calc(l, r-1, 1))){
			return dp[l][r][t]=-a[l]+dp[l+1][r][1];
		}
		else return dp[l][r][t]=-a[r]+dp[l][r-1][1];
	}
}

int main(){
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout);
  cin.sync_with_stdio(0); cin.tie();
  cin.exceptions(cin.failbit);

  cin >> n;
  rep(i, 1, n){
  	cin >> x;
  	a.pb(x);
  }
  rep(i, 0, n-1){
  	rep(j, i, n-1){
  		dp[i][j][0]=-1;
  		dp[i][j][1]=-1;
  	}
  }
  cout << calc(0, n-1, 1);
}