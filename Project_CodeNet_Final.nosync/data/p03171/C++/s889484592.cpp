#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll > v(3001);
int n;
ll dp[3001][3001];
ll answer(int start, int end){
	if(start == end) return v[start];
	if(start > end) return 0;
	if(dp[start][end] != -1) return dp[start][end];
	ll x = v[start] + min(answer(start+2, end), answer(start+1, end-1));
	ll y = v[end] + min(answer(start+1, end-1), answer(start, end-2));
	return dp[start][end] = max(x, y);
}

int main(){
	cin >> n;
	ll sum = 0;
	v.resize(n);
	for(auto &i : v) {cin >> i; sum += i;}
	memset(dp, -1, sizeof(dp));
	cout << 2*answer(0, n-1) - sum << endl;
	return 0;
}
