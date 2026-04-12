#include <iostream>
#include <vector>
using namespace std;

const int Mod = 1000000007;
class mll {
public:
	long long x;
	mll(long long x = 0) : x((x% Mod + Mod) % Mod) {};
	void operator - () {
		x = (-x % Mod + Mod) % Mod;
	}
	void operator += (const mll& a) {
		if ((x += a.x) >= Mod) x -= Mod;
	}
	void operator ++ () {
		*this += 1;
	}
	void operator ++(int) {
		operator++();
	}
	void operator -= (const mll& a) {
		if ((x += Mod - a.x) >= Mod) x -= Mod;
	}
	void operator *= (const mll& a) {
		(x *= a.x) %= Mod;
	}
	void operator /= (const mll& a) {
		mll b = a.inv();
		(x *= b.x) %= Mod;
	}
	mll operator + (const mll& a) const {
		mll ans = *this;
		ans += a;
		return ans;
	}
	mll operator * (const mll& a) const {
		mll ans = *this;
		ans *= a;
		return ans;
	}
	mll inv() const {
		long long a = x, b = Mod, u = 1, v = 0;
		while (b) {
			long long t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		u %= Mod;
		if (u < 0) u += Mod;
		a = u;
		return mll(a);
	}

};
int main() {
	int N;
	cin >> N;
	vector<long long>A(N);
	mll sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	mll ans = sum * sum;
	for (int i = 0; i < N; i++) ans -= A[i] * A[i];
	ans /= 2;
	cout << ans.x << endl;

}
