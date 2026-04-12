#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<climits>
#include<map>
#include<string>
#include<functional>
#include<iomanip>
#include<deque>
#include<random>
#include<set>
#include<bitset>
#include<cassert>

using namespace std;
typedef long long ll;
typedef double lldo;
#define mp make_pair
#define pub push_back
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define chmax(x,y) x = max(x,y)
ll gcd(ll a, ll b) { if (a % b == 0) { return b; } else  return gcd(b, a % b); }
ll lcm(ll a, ll b) { if (a == 0) { return b; }return a / gcd(a, b) * b; }
template<class T>ll LBI(vector<T>& ar, T in) { return lower_bound(ar.begin(), ar.end(), in) - ar.begin(); }
template<class T>ll UBI(vector<T>& ar, T in) { return upper_bound(ar.begin(), ar.end(), in) - ar.begin(); }

ll n;
const ll MOD = 1000000007;

int main() {
	cin >> n;
	vector<ll> a(n, 0);
	rep(i, n)cin >> a[i];
	vector<ll> sum(n, 0);
	sum[n - 1] = a[n - 1];
	for (int i = n - 1; i > 0; i--)sum[i - 1] = (sum[i] + a[i - 1]) % MOD;
	ll ans = 0;
	rep(i, n - 1)ans = (ans + (a[i] * sum[i + 1]) % MOD) % MOD;
	cout << ans << endl;
	return 0;
}