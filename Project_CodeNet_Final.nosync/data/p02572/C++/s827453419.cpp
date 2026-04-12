/* بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ */
//codeforces
#include <bits/stdc++.h>
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define mp make_pair
#define pb push_back
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
void parseArray(ll* A,ll n){ for ( ll K = 0; K < n; K++){ cin >> A[K]; } }
ll modInverse(ll a, ll b){ return 1<a ? b - modInverse(b%a, a)*b/a : 1; }
ll gcd(ll a, ll b){ return b?gcd(b, a % b):a; }
ll lcm(ll a, ll b){ return (a*b)/gcd(a, b); }
ld dist(ld x, ld y, ld a, ld b){ return sqrt((x-a)*(x-a) + (y-b)*(y-b)); }
void debug(ll* a, ll n) { for ( ll k = 0; k < n; k++ ){ cerr << a[k] << " ";} cout << "\n"; }
#define PI 3.14159265358979323846
#define FF first
#define SS second

const ll mod = 1000000007;
int main(){
	FASTIO;
	ll n; cin >> n;
	ll a[n]; parseArray(a, n);
	ll pref[n];
	pref[0] = a[0];
	for ( int k = 1; k < n; k++ )
		pref[k] = (pref[k - 1] + a[k]) % mod;
	ll ans = 0;
	for ( int k = 1; k < n; k++ ){
		ans += (pref[k - 1] * a[k]) % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}