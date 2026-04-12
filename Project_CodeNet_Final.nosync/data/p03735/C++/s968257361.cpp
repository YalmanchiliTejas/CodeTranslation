#include "bits/stdc++.h"
using namespace std;
int l[200010], r[200010];

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &l[i], &r[i]);
		if(l[i] > r[i]) swap(l[i], r[i]);
	}
	int maxid = 0;
	int minid = 0;
	for(int i = 1; i <= n; i++) {
		if(maxid == 0 || r[maxid] < r[i]) maxid = i;
		if(minid == 0 || l[minid] > l[i]) minid = i;
	}
	int mn = INT_MAX;
	int mx = INT_MIN;
	for(int i = 1; i <= n; i++) {
		mn = min(mn, r[i]);
		mx = max(mx, l[i]);
	}
	long long ans = 1LL * (r[maxid] - mn) * (mx - l[minid]);
	if(maxid == minid) {
		printf("%lld\n", ans);
		exit(0);
	}

	typedef pair <int, int> pii;
	vector <pii> Q;


	mn = min(l[maxid], r[minid]);
	mx = max(l[maxid], r[minid]);
	int opt = INT_MAX;

	for(int i = 1; i <= n; i++) {
		if(i == maxid || i == minid) {
			continue;
		}
		Q.push_back(pii(r[i], l[i]));
	}
	sort(Q.begin(), Q.end());	
	for(int i = 0; i < n-2; i++) {
		swap(Q[i].second, Q[i].first);
	}
	int suffMin = INT_MAX;
	int suffMax = INT_MIN;

	for(int i = n-3; i >= 0; i--) {
		int Max = max(mx, Q[i].second);
		int Min = min(mn, Q[0].second);
		// for(int j = i + 1; j < n-2; j++) {
		//	Min = min(Min, Q[j].first);
		// 	Max = max(Max, Q[j].first);
		// }
		Max = max(Max, suffMax);
		Min = min(Min, suffMin);
		opt = min(opt, Max - Min);
		suffMin = min(suffMin, Q[i].first);
		suffMax = max(suffMax, Q[i].first);
	}
	ans = min(ans, 1LL * opt * (r[maxid] - l[minid]));
	printf("%lld\n", ans);
	return 0;
}