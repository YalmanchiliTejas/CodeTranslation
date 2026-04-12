#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define size(a) int((a).size())
#define present(c, x) (c.find(x) != c.end()) 
#define printVerdict(verdict) cout << (verdict ? "YES": "NO") << '\n'
#define printDecimal(d) printf("%.9f\n", d)
#define inrange(val, start, end) (val >= start && val <= end)
 
const int mod = 1e9 + 7; 
 
template <class T1, class T2, class T3> 
void printTuple(tuple<T1, T2, T3> t) { cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n'; }
template <class T1, class T2>
void printPair(pair<T1, T2> p) { cout << p.first << " " << p.second  << '\n'; }
template <class T>
void printArray(vector<T> arr) { for (int i = 0; i<size(arr); i++) {cout << arr[i] << " ";} cout << '\n'; } 

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	ll a[n];
	for (int i =0; i<n; i++) cin >> a[i];
	vector<ll> suff_sum(n,0);
	suff_sum[n-1] = a[n-1]%mod;
	for (int i =n-2; i>=0; i--) {
		suff_sum[i] = suff_sum[i+1] + (a[i]%mod);
		suff_sum[i] %= mod;
	}
	ll ret = 0;
	for (int i =0; i<n-1; i++) {
		ll curr = (a[i]%mod * suff_sum[i+1])%mod;
		ret = (ret + curr)%mod;
	}
	cout << ret << '\n';
}
