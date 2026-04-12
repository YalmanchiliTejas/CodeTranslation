#pragma warning(disable:4996)
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;

#define ALL(a) begin(a), end(a)
#define TPL template
#define TNM typename

using ll = long long;
using ull = unsigned long long;
using mint = boost::multiprecision::cpp_int; //int1024_t etc...
TPL<TNM T> using vec = vector<T>;
TPL<TNM T> using vec2 = vec<vec<T>>;
TPL<TNM T> using vec3 = vec<vec2<T>>;

TPL<TNM V, TNM H> void resize(vector<V>& _v, const H _h) { _v.resize(_h); }
TPL<TNM V, TNM H, TNM ... T> void resize(vector<V>& _v, const H& _h, const T& ... _t) { _v.resize(_h); for (auto& __v : _v) resize(__v, _t ...); }
TPL<TNM V, TNM T> TNM enable_if<!is_class<V>::value, void>::type fill(vector<V>& _v, const T &_t) { std::fill(ALL(_v), _t); }
TPL<TNM V, TNM T> TNM enable_if<is_class<V>::value, void>::type fill(vector<V>& _v, const T &_t) { for (auto &_e : _v) fill(_e, _t); }
TPL<TNM T> inline void UNIQUE(vector<T>& _v) { sort(ALL(_v)); _v.erase(unique(ALL(_v)), _v.end()); }
struct pre_ { pre_() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(6); } } pre__;

int main(void) {
	int N, K;
	string S;
	cin >> N >> S >> K;
	for (int i = 0; i < N; ++i) {
		if (S[i] != S[K - 1]) {
			S[i] = '*';
		}
	}
	cout << S << endl;
	return 0;
}