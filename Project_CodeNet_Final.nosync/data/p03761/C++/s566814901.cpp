#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

array<int, 26> ans;

array<int, 26> f(string s) {
	array<int, 26> rt;
	rt.fill(0);
	for (char c : s) rt[c - 'a']++;
	return rt;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ans.fill(0x3f3f3f3f);
	int n; read(n);
	rep(i, 0, n) {
		string s; read(s);
		array<int, 26> r = f(s);
		rep(j, 0, 26) chmin(ans[j], r[j]);
	}
	//rep(i, 0, 26) printf("%c: %d\n", 'a'+i, ans[i]);
	rep(i, 0, 26) rep(j, 0, ans[i]) cout << char('a' + i);
	cout << endl;
}
