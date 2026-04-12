#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	ll n; cin >> n; vector<ll> a(n);
	FOR (i, 0, n - 1) cin >> a[i];


	auto f = [&] (ll x) {
		ll alpha = n - 1 - x;
		ll req = 0;
		FOR (i, 0, n - 1) if (a[i] > alpha) req += (a[i] - alpha + n) / (n + 1);
		return req <= x;
	};

	ll st = 0, en = 1e18;

	// FOR (i, 0, 200) pr(i, f(i));

	while (st < en) {
		ll mid = (st + en) >> 1;
		bool can = false;
		FOR (i, 0, n) can |= f(mid + i);
		if (can) en = mid;
		else st = mid + 1;
	}

	FOR (i, 0, n) if (f(st + i)) {
		cout << st + i;
		return 0;
	}

	return 0;
}
