#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define fi first
#define se second
#define pi pair<int, int>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define REP(i, a, n) for(int i = a; i < n; i++)
#define Y "YES"
#define N "NO"
using namespace std;

const ll mod = 1e9+7;
int n;
ll ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//freopen("in.txt", "r", stdin);
	
	cin >> n;
	ll a[n], sum[n];
	cin >> a[0];
	sum[0] = a[0];
	REP(i, 1, n) {
		cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	REP(i, 1, n)
		ans = (ans + ( (a[i] % mod) * (sum[i-1] % mod) ) % mod) % mod;
	
	cout << ans;
}