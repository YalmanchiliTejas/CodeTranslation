#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	ll A[50];
	rep(i, N) cin >> A[i];

	ll kaisuu = 0;
	while (*max_element(A, A + N) > 2 * N) {
		rep(i, N) {
			if (A[i] > 2 * N) {
				ll kari = (A[i] - 2 * N) / N + 1;
				A[i] -= kari * (N + 1);
				rep(ii, N) A[ii] += kari;
				kaisuu += kari;
			}
		}
	}

	while (*max_element(A, A + N) >= N) {
		*max_element(A, A + N) -= N + 1;
		rep(ii, N) A[ii] += 1;
		kaisuu++;
	}

	co(kaisuu);

	Would you please return 0;
}