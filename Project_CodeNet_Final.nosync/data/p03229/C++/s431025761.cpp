#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>

#define ll long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define FORR(i,a,b) for(int i=(a);i>=(b);--i)
#define REPR(i,n)   FORR(i,n,0)

using namespace std;

int main() {
	/*int A, B, K;
	cin >> A >> B >> K;
	REP(i, K) {
		if (i % 2 == 0) {
			if (A % 2 == 1) {
				A -= 1;
				A /= 2;
				B += A;
			}
			else {
				A /= 2;
				B += A;
			}
		}
		else {
			if (B % 2 == 1) {
				B -= 1;
				B /= 2;
				A += B;
			}
			else {
				B /= 2;
				A += B;
			}
		}
	}

	cout << A << " " << B << endl;
	*/

	int N;
	vector<ll> A;
	ll x;
	cin >> N;
	REP(i, N) {
		cin >> x;
		A.push_back(x);
	}
	sort(A.begin(), A.end());

	int r = N / 2, l = r - 1;
	ll ans = 0;
	if (N % 2 == 0) {
		FOR(i, r + 1, N) {
			ans += 2 * A[i];
		}
		REP(i, l) {
			ans += -2 * A[i];
		}
		ans += A[r];
		ans -= A[l];
	}
	else {
		FOR(i, r + 2, N) {
			ans += 2 * A[i];
		}
		REP(i, l) {
			ans += -2 * A[i];
		}
		ans += max(-2 * A[l] + A[r] + A[r + 1], 2 * A[r + 1] - A[r] - A[l]);
	}

	cout << ans << endl;

	return 0;
}