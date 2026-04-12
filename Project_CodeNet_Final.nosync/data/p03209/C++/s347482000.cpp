#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

class Memo {
private:
	vector<ll> p;
	vector<ll> b;
	vector<ll> s;
public:
	Memo(ll N): p(N + 1), b(N + 1), s(N + 1) {
		p[0] = 1;
		b[0] = 0;
		s[0] = 1;

		for(int i = 1; i <= N; i++) {
			p[i] = p[i - 1] * 2 + 1;
			b[i] = b[i - 1] * 2 + 2;
			s[i] = p[i] + b[i];
		}
	}

	ll num(ll N, ll X) {
		if(N == 0) {
			return 1LL;
		}
		if(X == 0) {
			return 0LL;
		}
		if(X < s[N] / 2LL) {
			return num(N - 1LL, X - 1LL);
		}
		if(X == s[N] / 2LL) {
			return p[N - 1] + 1LL;
		}
		if(X < s[N] - 1LL) {
			return p[N - 1] + num(N - 1LL, X - s[N - 1] - 2LL) + 1LL;
		}

		return 2LL * p[N - 1] + 1LL;
	}
};

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

	ll N, X;
	cin >> N >> X;
	
	Memo memo(N);

	cout << memo.num(N, X - 1LL) << endl;
}