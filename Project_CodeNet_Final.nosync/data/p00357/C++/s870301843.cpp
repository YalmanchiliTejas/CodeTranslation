#include "bits/stdc++.h"

using namespace std;
using uint = unsigned int;
using int64 = long long;
using i64 = int64;
using uint64 = unsigned long long;
using vint = vector<int>;
using vint64 = vector<int64>;
template<typename T>
using p_que = priority_queue<T>;
#define rep(i,N) for(int i=0;i<(int)(N);++i)
#define rep1(i,N) for(int i=1;i<=(int)(N);++i)
#define fs first
#define sc second
#define eb emplace_back
#define all(x) x.begin(),x.end()

template<typename T>
vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template<typename... Ts>
auto make_v(size_t a, Ts... ts) {
	return vector<decltype(make_v(ts...))>(a, make_v(ts...));
}

template<class T> ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "[";
	for (auto& e : v) os << e << ", ";
	return os << "]";
}

template<class T, class U> ostream& operator<<(ostream& os, const pair<T, U> p) {
	return os << "P(" << p.first << ", " << p.second << ")";
}

template<class T, class U> ostream& operator<<(ostream& os, const map<T, U>& mp) {
	os << "{";
	for (auto& e : mp) os << e << " ";
	return os << "}";
}

void Main();
signed main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	Main();
}

/* Cut from here! */

//#define int long long

int GCD(int a, int b) {
	return b ? GCD(b, a % b) : a;
}

using vec=vector<bool>;
using dvec=vector<vec>;

void Main() {
	int N; cin >> N;
	vector<int64> d(N);
	rep(i, N) cin >> d[i], d[i] /= 10;

	i64 now = d[0];
	for (int i = 1; i < N; ++i) {
		now--;
		if (now < 0) {
			cout << "no" << endl;
			return;
		}
		now = max(now, d[i]);
	}
	now = d[N - 1];
	for (int i = N - 1; i >= 0; --i) {
		now--;
		if (now < 0) {
			cout << "no" << endl;
			return;
		}
		now = max(now, d[i]);
	}

	cout << "yes" << endl;
}
