#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int main(int argc, char const *argv[])
{
	int n; cin >> n;
	vector<int> h(n); rep(i, n) cin >> h[i];
	int max = 0;
	int ans = 0;
	rep(i, n) {
		if (max <= h[i]) {
			ans++;
			max = h[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}