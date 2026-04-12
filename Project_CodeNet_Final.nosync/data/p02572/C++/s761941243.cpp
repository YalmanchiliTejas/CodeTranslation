#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = (1e9 + 7) * 2;

int n;
ll a[200010];
ll sum, ans;

int main() {
	fast;

	cin >> n;

	for(int i=1; i<=n; i++) {
		cin >> a[i];
		sum += a[i];
		sum %= Mod;

		ans += Mod - a[i] * a[i] % Mod;
		ans %= Mod;
	}

	ans += sum * sum % Mod;
	ans %= Mod;

	cout << ans / 2;
}