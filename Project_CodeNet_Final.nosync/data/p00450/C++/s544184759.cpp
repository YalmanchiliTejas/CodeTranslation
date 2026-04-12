#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<cmath>
#define int long long
#define mod 1000000007
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
using namespace std;
int n;
signed main() {
	while (cin >> n, n) {
		stack<pair<short, int>>st;
		for0(i, n) {
			short t; cin >> t;
			if (i % 2 == 0) { if (st.size() == 0 || st.top().first != t)st.push(make_pair(t, i)); }
			else if (st.top().first != t) { st.pop(); if (st.size() == 0)st.push(make_pair(t, (int)0)); }
		}
		int ans = 0;
		while (st.size()) {
			if (st.top().first == 0)ans += n - st.top().second;
			n = st.top().second;
			st.pop();
		}
		cout << ans << endl;
	}
}
