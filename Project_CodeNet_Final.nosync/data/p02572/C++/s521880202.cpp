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
	vl A(N), Asum(N + 1, 0);
	rep(i, N) {
		cin >> A[i];
		Asum[i + 1] = Asum[i] + A[i];
		Asum[i + 1] %= mod;
	}
	ll ans = 0;
	rep(i, N) {
		ll anstmp = Asum[i] * A[i];
		ans += anstmp;
		ans %= mod;
	}


	cout << ans << endl;
	return 0;
}