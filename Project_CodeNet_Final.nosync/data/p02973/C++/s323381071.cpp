#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9+7;

void see(vector<int> &dp){
	rep(i,dp.size()) cout << dp[i] << " ";
	cout << endl;
}

int binary_search(vector<int> &dp, int thr){
	int head = 0, tail = dp.size()-1;
	while(tail - head > 1){
		int mid = (head + tail) / 2;
		if(dp[mid] < thr) tail = mid;
		else head = mid;
	}
	if(dp[head] < thr) return head;
	if(dp[tail] < thr) return tail;
	return -1;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	vector<int> dp;
	dp.push_back(a[0]);
	for(int i = 1; i < n; i++){
		int it = binary_search(dp, a[i]);
		if(it > -1) dp[it] = a[i];
		else dp.push_back(a[i]);
	}
	int ans = dp.size();
	cout << ans << endl;
	return 0;
}