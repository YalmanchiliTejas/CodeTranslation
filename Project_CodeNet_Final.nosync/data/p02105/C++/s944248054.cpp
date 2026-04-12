#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<utility>
#include<set>
#include<map>
#include<stack>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define stop char nyaa;cin>>nyaa;

int n; ll a, b;
void solve() {
	vector<LP> v[5];
	rep(i, 5)v[i].push_back({ 0,0 });
	cin >> n >> a >> b;
	vector<LP> le, ri;
	rep(i, n) {
		int t; cin >> t; t--;
		ll x, y; cin >> x >> y;
		v[t].push_back({ x,y });
	}
	rep(i, v[0].size()) {
		rep(j, v[1].size()) {
			LP nex = { 0,0 };
			nex.first = v[0][i].first + v[1][j].first;
			nex.second = v[0][i].second + v[1][j].second;
			le.push_back(nex);
		}
	}
	rep(i, v[2].size()) {
		rep(j, v[3].size()) {
			rep(k, v[4].size()) {
				LP nex = { 0,0 };
				nex.first = v[2][i].first + v[3][j].first + v[4][k].first;
				nex.second = v[2][i].second + v[3][j].second + v[4][k].second;
				ri.push_back(nex);
			}
		}
	}
	sort(le.begin(), le.end());
	sort(ri.begin(), ri.end());
	ll x = le[0].first;
	multiset<ll> st;
	//[l,r)
	int l = (int)ri.size(), r = ri.size();
	rep(i, ri.size()) {
		ll sum = ri[i].first + le[0].first;
		if (sum >= a && sum <= b) {
			st.insert(ri[i].second);
		}
		if (ri[i].first >= a - le[0].first) {
			l = min(l, i);
		}
		if (ri[i].first > b - le[0].first) {
			r = min(r, i);
		}
	}
	{
		ll cl = a - le[0].second, cr = b - le[0].second;
		if (st.count(cl)) {
			cout << "Yes" << endl; return;
		}
		st.insert(cl);
		auto itr = st.find(cl);
		itr++;
		if (itr != st.end()) {
			ll z = *itr;
			if (z <= cr) {
				cout << "Yes" << endl; return;
			}
		}
		st.erase(st.find(cl));
	}
	rep1(i, (int)le.size()-1) {
		while (l > 0 && le[i].first + ri[l-1].first >= a) {
			l--;
			st.insert(ri[l].second);
		}
		while (r > 0 && le[i].first + ri[r-1].first > b) {
			r--;
			st.erase(st.find(ri[r].second));
		}
		ll cl = a - le[i].second, cr = b - le[i].second;
		if (st.count(cl)) {
			cout << "Yes" << endl; return;
		}
		st.insert(cl); 
		auto itr = st.find(cl);
		itr++;
		if (itr != st.end()) {
			ll z = *itr;
			if (z <= cr) {
				cout << "Yes" << endl; return;
			}
		}
		st.erase(st.find(cl));
	}
	cout << "No" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(6);
	solve();
	//stop
		return 0;
}
