#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n;
int ans[200010];

int main() {
	cin >> n;
	vector<pii> vec(n);

	rep(i, n) {
		int x;
		cin >> x;
		vec[i] = mp(x, i);
	}

	sort(ALL(vec));

	rep(i, n) {
		if (i < n/2) {
			ans[vec[i].se] = vec[n/2].fi;
		} else {
			ans[vec[i].se] = vec[n/2-1].fi;
		}
	}

	rep(i, n) {
		printf("%d\n", ans[i]);
	}

	return 0;
}