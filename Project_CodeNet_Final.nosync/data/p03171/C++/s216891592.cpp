#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
typedef pair<ll,ll> pr;
typedef vector<ll> vc;
typedef unordered_map<ll,ll> umap;
#define pb emplace_back
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define reps(i,v) for(ll i=0;i<v.size();i++)
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
const ll mod = 1e9+7;

int main(){
	ll n, a[3005], dp[3005][3005]={0};
	cin >> n;
	rep(i,0,n-1) cin >> a[i];
	rep(i,1,n){
		rep(j,0,n-i){
			if(i == 1){
				if(n%2 == 0) dp[j][j] = -a[j];
				else dp[j][j] = a[j];
			} else {
				if((n-i)%2 == 0) dp[j][j+i-1] = max(dp[j+1][j+i-1]+a[j], dp[j][j+i-2]+a[j+i-1]);
				else dp[j][j+i-1] = min(dp[j+1][j+i-1]-a[j], dp[j][j+i-2]-a[j+i-1]);
			}
		}
	}
	cout << dp[0][n-1] << endl;
    return 0;
}
