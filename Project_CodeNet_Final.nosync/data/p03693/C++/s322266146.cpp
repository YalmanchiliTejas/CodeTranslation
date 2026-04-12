#pragma warning(disable:4996)
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for (int i = 0; i<n; i++)
#define ALL(a) begin(a), end(a)
#define TPL template
#define TNM typename

using ll = long long;
using ull = unsigned long long;
TPL<TNM T> using vec = vector<T>;
TPL<TNM T> using vec2 = vec<vec<T>>;
TPL<TNM T> using vec3 = vec<vec2<T>>;
TPL<TNM T> using vec4 = vec<vec3<T>>;
TPL<TNM T> using vec5 = vec<vec4<T>>;

TPL<TNM K, TNM V> using umap = unordered_map<K, V>;
TPL<TNM K, TNM V> using uset = unordered_set<K, V>;

struct pre_ { pre_() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(6); } } pre__;

TPL<TNM V, TNM H> void resize(vector<V>& v, const H h) { v.resize(h); }
TPL<TNM V, TNM H, TNM ... T> void resize(vector<V>& v, const H& h, const T ... t) { v.resize(h); for (auto& _v : v) resize(_v, t ...); }
TPL<TNM V, TNM T> void fill(V& x, const T& val) { x = val; }
TPL<TNM V, TNM T> void fill(vector<V>& vec, const T& val) { for (auto& v : vec) fill(v, val); }

int main(void) {
	int r, g, b;
	cin >> r >> g >> b;
	if ((100 * r + 10 * g + b) % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}