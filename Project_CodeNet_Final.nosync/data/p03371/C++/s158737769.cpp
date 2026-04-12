#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
ll dp[55][55][5000];

signed main(){
	//cout << fixed << setprecision(10);
	ll a,b,c,x,y; cin>>a>>b>>c>>x>>y;
	ll ans=MOD;
	chmin(ans,max(x,y)*c*2);
	chmin(ans,a*x+b*y);
	if(x<=y){
		chmin(ans,2*c*x+b*(y-x));
	}
	else{
		chmin(ans,2*c*y+a*(x-y));
	}
	cout << ans << endl;
	 
	return 0;
}