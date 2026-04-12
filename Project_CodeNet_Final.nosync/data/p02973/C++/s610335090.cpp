#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9 + 7;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n), dp(n+2, INF);
	rep(i,n) cin >> a[i];
	for(int i = n-1; i >= 0; --i){
		int idx = lower_bound(dp.begin(), dp.end(), a[i]+1) - dp.begin();
		dp[idx] = a[i];
	}
	rep(i,n+1){
		if(dp[i] == INF){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
