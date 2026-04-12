#include <bits/stdc++.h>
using namespace std;
long long dp[3005][3005][3];
vector<long long> V;
long long f(int lo, int hi, int e){
	if(lo>hi) return 0;
	if(dp[lo][hi][e] != -1) return dp[lo][hi][e];
	int s = 0;
	if(!e) s = 1;
	return dp[lo][hi][e] = max(V[lo] - f(lo + 1, hi, s) , V[hi] - f(lo, hi - 1, s));
}
int main() {
	int n;
	long long a, s = 0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a;
		V.push_back(a);
		s+=a;
	}
	memset(dp, -1, sizeof(dp));
	cout << f(0, n-1, 1);
	return 0;
}