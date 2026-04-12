#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cassert>
#define InfL 1000000000
#define InfLL 1000000000000000000LL
#define mod 1000000007
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=(n-1);(i)>=(0);(i)--)
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<db> vd;

int main() {
	ll N;
	cin >> N;
	vl A(N);
	rep(i, N)
		cin >> A[i];
	ll ans = -InfLL;
	if (N % 2 == 0) {
		vl Asum(N + 2, 0);
		rep(i, N) {
			Asum[i + 2] = Asum[i] + A[i];
		}
		rep(i, N + 1) {
			if (i % 2 == 0)
				ans = max(ans, Asum[i] + Asum[N + 1] - Asum[i + 1]);
		}
	}
	else {
		vl Asum(N + 2, 0);
		rep(i, N) {
			Asum[i + 2] = Asum[i] + A[i];
		}
		vl ansL(N, 0);
		vl ansR(N, 0);
		rep(i, N) {
			if (i % 2 == 1)
				ansL[i] = Asum[i + 1] - Asum[i + 2];
		}
		rep(i, N) {
			if (i % 2 == 1) {
				ansR[i] -= Asum[N] - Asum[i];
				ansR[i] += (Asum[N + 1] - Asum[i + 1]);
			}
		}
		vl ansLmax(N + 2, 0);
		vl ansRmax(N + 2, 0);
		rep(i, N) {
			if (i % 2 == 1) {
				ansLmax[i + 2] = max(ansLmax[i], ansL[i]);
			}
		}
		rrep(i, N) {
			if (i % 2 == 1) {
				ansRmax[i] = max(ansRmax[i + 2], ansR[i]);
			}
		}
		rep(i, N + 1) {
			if (i % 2 == 1) {
				ll anstmp = Asum[N];
				anstmp += ansLmax[i];
				anstmp += ansRmax[i];
				ans = max(ans, anstmp);
			}
		}
	}
	cout << ans << endl;
	return 0;
}