#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "iomanip"
#include "cmath"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<pair<long long int, long long int>>v(N);
	L = INT_MAX;
	for (int i = 0; i < N; i++) {
		cin >> M >> K;
		L = min(M, L);
		R = max(R, M);
		L = min(K, L);
		R = max(R, K);
		if (M < K) {
			v[i] = { M,K };
		}
		else {
			v[i] = { K,M };
		}
	}
	long long int ans = LLONG_MAX;
	long long int lmin = INT_MAX;
	long long int lmax = 0;
	long long int rmax = 0;
	long long int rmin = INT_MAX;
	for (int i = 0; i < N; i++) {
		lmin = min(lmin, v[i].first);
		lmax = max(lmax, v[i].first);
		rmin = min(rmin, v[i].second);
		rmax = max(rmax, v[i].second);
	}
	ans = min(ans, (lmax - lmin)*(rmax - rmin));
	sort(v.begin(), v.end());
	long long int emin = INT_MAX;
	long long int emax = 0;
	ans = min(ans, (R - L)*(v[N - 1].first - v[0].first));
	for (int i = 0; i < N-1; i++) {
		emin = min(emin, v[i].second);
		emax = max(emax, v[i].second);
		ans = min(ans, (max(emax, v[N - 1].first) - min(emin, v[i + 1].first))*(R - L));
	}
	emin = min(emin, v[N - 1].second);
	emax = max(emax, v[N - 1].second);
	ans = min(ans, (R - L)*(emax - emin));
	cout << ans << endl;
	return 0;
}