#include<iostream>
#include<iomanip>
#include<climits>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<string>
#include<cmath>
#include<complex>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#define FOR(i, a, b) for(int i = (a);i < (b);++i)
#define FORR(i, b, a) for (int i = (b) - 1;i >= 0;--i)
#define REP(i, n) for(int i = 0;i < (n);++i)
#define REPR(i, n) for(int i = (n) - 1;i >= 0;--i)
#define ITER(itr, v) for(auto itr = v.begin();itr != v.end();++itr)
#define SORT(v) sort(v.begin(), v.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

template<int p = 1000000007>
class Z {
	ll x;
public:
	Z(ll X) :x((X + p) % p) { ; }
	Z() :x(0) { ; }
	Z &operator=(ll y) {
		return *this = Z(y);
	}
	Z operator-() const {
		return Z(-x);
	}
	Z operator+(ll y) const {
		return Z(x + y);
	}
	Z &operator+=(ll y) {
		return *this = *this + y;
	}
	Z operator-(ll y) const {
		return Z(x - y);
	}
	Z &operator-=(ll y) {
		return *this = *this - y;
	}
	Z operator*(ll y) const {
		return Z(x * y);
	}
	Z &operator*=(ll y) {
		return *this = *this * y;
	}
	Z operator/(ll y) const {
		return *this * Z(y).pow(p - 2);
	}
	Z &operator/=(ll y) const {
		return *this = *this / y;
	}
	Z operator+(const Z &r) const {
		return *this + r.x;
	}
	Z &operator+=(const Z &r) {
		return *this += r.x;
	}
	Z operator-(const Z &r) const {
		return *this - r.x;
	}
	Z &operator-=(const Z &r) {
		return *this -= r.x;
	}
	Z operator*(const Z &r) const {
		return *this * r.x;
	}
	Z &operator*=(const Z &r) {
		return *this *= r.x;
	}
	Z operator/(const Z &r) const {
		return *this / r.x;
	}
	Z &operator/=(const Z &r) {
		return *this /= r.x;
	}
	Z pow(int i) {
		if (i == 0) return Z(1);
		if (i % 2) return *this * pow(i - 1);
		Z tmp = pow(i / 2);
		return tmp * tmp;
	}
	ll get() {
		return x;
	}
};

const int p = 998244353;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, S;
	cin >> N >> S;
	vector<int> A(N);
	REP(i, N) cin >> A[i];
	Z<p> res(0);
	vector<Z<p>> q(S + 1);
	REP(i, N) {
		q[0] += 1;
		vector<Z<p>> q2(S + 1);
		REP(j, S + 1) {
			q2[j] += q[j];
			if (j + A[i] <= S) q2[j + A[i]] += q[j];
		}
		q = q2;
		res += q[S];
	}
	cout << res.get() << endl;

	return 0;
}