#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
template<typename T, typename U> 
static inline void amin(T &x, U y){
	if(x>y)
		x = y;
}
template<typename T, typename U> 
static inline void amax(T &x, U y){
	if(x<y)
		x = y;
}
#define rep(i,n) for(int i = 0; i < n; ++i)
#define REP(i,k,n) for(int i = k; i <= n; ++i)
#define REPR(i,k,n) for(int i = k; i >= n; --i)

int inf = 2e9;
ll INF = 2e18;
const int mod = 1e9+7;

int main(){
	int n;
	cin >> n;
	int a[n];
	rep(i,n){
		cin >> a[i];
	}
	vvi dp(n,vi(n,0));
	REPR(l,n-1,0){
		REP(r,l,n-1){
			if(l==r){
				dp[l][r] = a[l];
			}else{
				dp[l][r] = max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}