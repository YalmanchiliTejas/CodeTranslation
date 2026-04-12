#include <bits/stdc++.h>
using namespace std;
#define endl			"\n"
#define ll				long long
#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define vi				vector <int>
#define vl				vector <ll>
#define ii				pair <ll,ll>
#define vii				vector <ii>
#define ull				unsigned long long
const double PI = 2 * acos(0.0);
void run() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
}
bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	return a.second < b.second;
}
int main() {
	run();
	int n;
	cin >> n;
	multiset<ll> t;
	for(int i = 0; i < n; i++) {
		int a; cin >> a;
		auto it = t.lower_bound(a);
		if(it == t.begin()) {
			t.insert(a);
		}
		else {
			it--;
			t.erase(it);
			t.insert(a);
		}
	}
	cout << t.size() << endl;
}

