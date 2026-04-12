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

TPL<TNM V, TNM H> void resize(vector<V>& v, const H h) { v.resize(h); }
TPL<TNM V, TNM H, TNM ... T> inline void resize(vector<V>& v, const H& h, const T ... t) { v.resize(h); for (auto& _v : v) resize(_v, t ...); }
TPL<TNM V, TNM T> void fill(V& x, const T& val) { x = val; }
TPL<TNM V, TNM T> inline void fill(vector<V>& vec, const T& val) { for (auto& v : vec) fill(v, val); }
TPL<TNM T> inline void UNIQUE(vector<T>& vec) { sort(ALL(vec)); vec.erase(unique(ALL(vec)), vec.end()); }

class YukiIO {
	char* buff;
	string format;
public:
	YukiIO(int s_, int pre_) { buff = new char[s_]; format = "%." + to_string(pre_) + "lf"; }
	~YukiIO() { delete buff; }
	//--------------input---------------
	inline void scan(int &i_) { scanf("%d", &i_); }
	inline void scan(long long &l_) { scanf("%lld", &l_); }
	inline void scan(double &d_) { scanf("%lf", &d_); }
	inline void scan(float &f) { scanf("%f", &f); }
	inline void scan(char &c_) { scanf("%*c%c", &c_); }
	inline void scan(char* s_) { scanf("%s", s_); }
	inline void scan(string &s_) { scanf("%s", buff); s_ = string(buff); }
	template <typename HEAD, typename ...TAIL>inline void scan(HEAD& head, TAIL& ...tails) {
		scan(head);
		scan(tails...);
	}
	template <typename T> inline void scan(vector<T>& v) {
		for (int i = 0; i < v.size(); ++i) scan(v[i]);
	}
	template <typename ...ARGS> inline void scan(const string &format, ARGS& ... args) {
		scan(buff);
		sscanf(buff, format.data(), &args...);
	}
	//--------------outut---------------
	inline void print(int &i_) { printf("%d", i_); }
	inline void print(long long &l_) { printf("%lld", l_); }
	inline void print(double &d_) { printf(format.data(), d_); }
	inline void print(float &f) { printf("%f", f); }
	inline void print(char &c_) { printf("%c", c_); }
	inline void print(char* s_) { printf("%s", s_); }
	inline void print(string &s_) { printf("%s", s_.data()); }
	inline void print(const char* s_) { printf("%s", s_); }
	template <typename T> inline void print(vector<T>& v) {
		print(v[0]);
		for (int i = 1; i < v.size(); ++i) {
			putchar(' '); print(v[i]);
		}
	}
	inline void println() { puts(""); }
	template <typename T> inline void println(T x) { print(x); puts(""); }
	template <typename T> inline void println(vector<T>& v) { for (int i = 0; i < v.size(); ++i) println(v[i]); }
	template <typename ...ARGS> inline void print(const string &format, ARGS& ... args) {
		printf(format.data(), args...);
	}
	template <typename ...ARGS> inline void println(const string &format, ARGS& ... args) {
		printf(format.data(), args...); puts("");
	}
	template <typename HEAD, typename ...TAIL>inline void print(HEAD& head, TAIL& ...tails) {
		print(head);
		print(tails...);
	}
	template <typename ...ARGS>inline void println(ARGS& ... args) {
		print(args...);
		puts("");
	}
};

YukiIO io{ 114514, 12 };

int main(void) {
	int N, M;
	io.scan(N, M);
	vec2<int> g;
	resize(g, N, N);
	fill(g, 0);

	for (int i = 0; i < M; ++i) {
		int a, b;
		io.scan(a, b);
		--a; --b;
		g[a][b] = 1;
		g[b][a] = 1;
	}

	vec<int> path(N);
	for (int i = 0; i < N; ++i) {
		path[i] = i;
	}
	int ans = 0;
	do {
		if (path[0] != 0)continue;
		bool f = true;
		for (int i = 0; i < N - 1; ++i) {
			int s = path[i];
			int t = path[i + 1];
			if (!g[s][t])f = false;
		}
		if (f)++ans;

	} while (next_permutation(path.begin(), path.end()));

	io.println(ans);

	return 0;
}