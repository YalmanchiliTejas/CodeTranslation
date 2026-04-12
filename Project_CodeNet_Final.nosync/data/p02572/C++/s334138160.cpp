#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define IOS ios::sync_with_stdio(false)
typedef long long ll;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
ll sum[maxn], arr[maxn];
void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		sum[i] = (sum[i - 1]+ arr[i]);
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = (ans+ arr[i] * ((sum[n] - sum[i]) % mod) % mod) % mod;
	}
	cout << ans << endl;
}
int main() {
	IOS;
	solve(); 
	return 0;
}
