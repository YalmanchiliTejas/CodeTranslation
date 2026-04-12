#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,x,n) for(int i=x;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
#define MP(a,b) make_pair(a,b)
typedef long long LL;
typedef pair<int, int> PI;
typedef vector<int> VI;
const LL MOD = 1000000007LL;
LL a[50];
int main() {
	int N;
	cin >> N;
	LL sum = 0;
	rep(i, N) {
		cin >> a[i];
		sum += a[i];
	}
	LL X = sum - (N - 1)*N;
	LL ans = 0;
	if (X > 0) {
		LL l = -1, r = 1LL << 60; //(l,r]
		while (r - l > 1) {
			LL m = (l + r) / 2;
			LL cnt = 0;
			rep(i, N) cnt += max((a[i]+X - m) / (N + 1), 0LL);
			if (cnt <= X) {
				r = m;
			}
			else {
				l = m;
			}
		}
		rep(i, N) {
			ans += max((a[i]+X - r) / (N + 1), 0LL);
			a[i] -= max((a[i]+X - r) / (N + 1), 0LL)*(N + 1);
		}
		rep(i, N) {
			a[i] += ans;
		}
	}
	while (1) {
		LL max_pos = 0;
		rep(i, N) {
			if (a[i] > a[max_pos]) max_pos = i;
		}
		if (a[max_pos] <= N - 1) break;
		a[max_pos] -= N;
		rep(i, N) {
			if (i != max_pos) a[i]++;
		}
		ans++;
	}
	cout << ans << endl;
}