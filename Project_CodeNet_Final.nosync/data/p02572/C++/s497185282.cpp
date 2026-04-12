#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pi pair<int, int>
#define F first
#define S second
#define PB push_back
#define EPB emplace_back
#define MP make_pair
#define deb(x) cerr << #x << ":" << x << endl;
#define deba(x) cerr << #x << endl; for (auto a : x) cerr << a << " "; cerr << endl;
const int MOD = 1e9 + 7;
const double EPS = 0.01;

int main() {
	fastio();
	int n;
	cin >> n;
	ll a[n];
	ll suf[n];
	suf[n - 1] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll sum = 0;
	for (int i = n - 2; i >= 0; i--) {
		suf[i] = (suf[i + 1] % MOD + a[i + 1] % MOD) % MOD;
		sum = (sum % MOD + ((a[i] % MOD) * (suf[i] % MOD)) % MOD) % MOD;
	}
	cout << sum << '\n';




	return 0;
}
