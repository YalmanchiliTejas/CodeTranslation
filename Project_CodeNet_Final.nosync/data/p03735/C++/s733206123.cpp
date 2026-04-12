#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

vector <pll> V;
ll S[202020];
ll n, l1, l2, r1, r2, cnt, ans;

int main()
{
	ll i, j, a, b;
	
	scanf("%lld", &n);
	
	l1 = l2 = 1e9; r1 = r2 = 0;
	
	for(i=1; i<=n; i++){
		scanf("%lld%lld", &a, &b);
		V.emplace_back(a, i);
		V.emplace_back(b, i);
		l1 = min(l1, min(a, b));
		l2 = min(l2, max(a, b));
		r1 = max(r1, min(a, b));
		r2 = max(r2, max(a, b));
	}
	
	ans = (r1 - l1) * (r2 - l2);
	
	sort(V.begin(), V.end());
	
	for(i=0, j=0; i<n+n; i++){
		for(; j<n+n && cnt<n; j++){
			S[V[j].second] ++;
			if(S[V[j].second] == 1) cnt ++;
		}
		
		if(cnt == n){
			ans = min(ans, (r2 - l1) * (V[j - 1].first - V[i].first));
		}
		
		S[V[i].second] --;
		if(S[V[i].second] == 0) cnt --;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}