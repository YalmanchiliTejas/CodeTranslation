#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define sz(V) ((int)V.size())

vector<pii> S;
int x[200009], y[200009], K[200009], c;

void er(int i) {
	--K[S[i].second];
	if(!K[S[i].second]) --c;
}

void ad(int i) {
	++K[S[i].second];
	if(K[S[i].second] == 1) ++c;
}

int main() {
	int rn = 1e9, rx = -1e9, bn = 1e9, bx = -1e9;
	int N; scanf("%d",&N);
	for(int i=1; i<=N; i++) {
 		scanf("%d%d", &x[i], &y[i]);
 		if(x[i] > y[i]) swap(x[i], y[i]);
 		rn = min(rn, x[i]); rx = max(rx, x[i]);
 		bn = min(bn, y[i]); bx = max(bx, y[i]);
 		S.push_back({x[i], i});
 		S.push_back({y[i], i});
	}
	long long ans = 1LL * (rx - rn) * (bx - bn);
	sort(S.begin(), S.end());
	for(int i=0, j=0; i<sz(S); i++) {
		if(i) er(i-1);
		while(j < sz(S) && c < N) ad(j++);
		if(c == N) ans = min(ans, 1LL * (bx - rn) * (S[j-1].first - S[i].first));
	}
	printf("%lld", ans);
	return 0;
}