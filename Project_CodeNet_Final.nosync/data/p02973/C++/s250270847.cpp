#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fsp(x) fixed << setprecision(x)
#define xout cerr
const ll inf = LLONG_MAX;
const long double pi = acosl(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//const ll p = 1e9 + 7;
	//const ll p = 998244353;

	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	multiset<ll> st;
	st.insert(-a[0]);
	for (ll i = 1; i < n; i++) {
		auto itr = st.upper_bound(-a[i]);
		if (itr == st.end()) st.insert(-a[i]);
		else {
			st.erase(itr);
			st.insert(-a[i]);
		}
	}
	cout << st.size() << endl;
}
