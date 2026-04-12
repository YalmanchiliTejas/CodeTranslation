//#pragma GCC optimize("trapv")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using ld = long double;
const int maxn = 5005, mod = 998244353;
ll dp[104][4][2];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int k;
	cin >> s >> k;
	reverse(all(s));
	dp[0][0][0] = 1;
	for(int i = 0; i < s.size(); i++) {
		for(int cnt = 0; cnt <= 3; cnt++) {
			for(int k = 0; k < 2; k++) {
			for(int d = 0; d < 10; d++) {
				if(d>0&&cnt==3) break;
				dp[i+1][cnt+(d>0)][d==(s[i]-'0')?k:d>(s[i]-'0')]+=dp[i][cnt][k];
			}
			}
		}
	}
	cout << dp[s.size()][k][0];
}
