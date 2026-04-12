#include <iostream>
#include <vector>
using namespace std;

#include <vector>
#define debug(x) print(x, #x)
#define debug_1d(arr, len) print(arr, len, #arr)
#define debug_2d(arr, row, col) print((decltype(&arr[0][0]))arr, row, col, sizeof(*arr)/sizeof(**arr), #arr)
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a1,a2,a3,x,...) x
#define deb(...) CHOOSE((__VA_ARGS__,debug_2d,debug_1d,debug,~))(__VA_ARGS__)
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
	return os << '(' << p.first << ',' << p.second << ')';
}
template<typename T> void print(T x, string tag="") {
	if (tag.empty()) cout << x << endl;
	else cout << tag << ": " << x << endl;
}
template<typename T> void print(T *ar, int len, string tag="") {
	if (!tag.empty()) cout << tag << ": ";
	for (int i = 0; i < len; ++i) cout << ar[i] << ' ';
		cout << endl;
}
template<typename T> void print(T *ar, int row, int col, int C, string tag="") {
	if (!tag.empty()) cout << tag << ": " << endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << ar[i*C + j] << ' ';
		}
		cout << endl;
	}
}
template<typename T> void print(vector<T> v, string tag="") {
	if (!tag.empty()) cout << tag << ": ";
	for (T e : v) cout << e << ' ';
	cout << endl;
}
template<typename T> void print(vector<vector<T>> v, string tag="") {
	if (!tag.empty()) cout << tag << ": " << endl;
	for (auto ev : v) {
		for (auto e : ev) cout << e << ' ';
		cout << endl;
	}
}

int main() {
	long long n, m, x;
	cin >> n >> x >> m;
	int a = 1, t = 1;
	struct P {
		bool b;
		int idx;
	};
	vector<P> v(m);
	v[x] = {true, 0};
	for (long long i = 1, y = x; i <= m+3; i++) {
		y = y * y % m;
		if (v[y].b == true) {
			a = v[y].idx;
			t = i;
			break;
		} else v[y].b = true, v[y].idx = i;
	}
	long long s = 0;
	for (long long i = 0, y = x; i < m+3; i++) {
		if (i >= a && i < t) s += y;
		y = y * y % m;
	}
	long long ans = 0;
	for (int i = 0; i < a && i < n; i++) {
		ans += x;
		x = x * x % m;
		n--;
	}
	ans += s * (n / (t-a));
	for (long long i = (n/(t-a))*(t-a); i < n; i++) {
		ans = (ans + x);
		x = x*x % m;
	}
	cout << ans << endl;
	return 0;
}