#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll dp1[51], dp2[51];

ll solve(int n, ll x){
	if(x == 1) return (n == 0 ? 1 : 0);
	if(1 < x && x <= 1+dp1[n-1]) return solve(n-1, x-1);
	if(x == 2 + dp1[n-1]) return dp2[n-1] + 1;
	if(2 + dp1[n-1] < x && x <= 2 + 2*dp1[n-1]) return dp2[n-1]+1+solve(n-1, x-2-dp1[n-1]);
	if(x == 3+2*dp1[n-1]) return 2*dp2[n-1] + 1;
	return 0;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	ll x;
	cin >> n >> x;
	dp1[0] = dp2[0] = 1;
	rep(i,50){
		dp1[i+1] = 3 + 2 * dp1[i];
		dp2[i+1] = 1 + 2 * dp2[i];
	}
	cout << solve(n, x) << endl;
	return 0;
}