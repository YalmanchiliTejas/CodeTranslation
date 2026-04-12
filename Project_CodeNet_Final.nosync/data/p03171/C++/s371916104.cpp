#include "bits/stdc++.h"
using namespace std; 
#define LIM 3002

#define M 1000000007
#define inf 99999999999999999LL	//long long inf
typedef long long ll;

#define sc(x) scanf("%d",&x);
#define sc2(x,y) scanf("%d%d",&x,&y);
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define scl(x) scanf("%lld",&x);
#define scl2(x,y) scanf("%lld%lld",&x,&y);
#define scl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z);

#define pb push_back
#define mp make_pair
#define fi first
#define se second 
ll power(ll x,ll y,ll z) {	ll ret = 1;	while(y > 0) {	if(y & 1) ret = (ret*x)%z;x = (x*x)%z;y >>= 1;}return ret;}


#define debug(x) cerr<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define debug4(x,y,z,a) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#a<<" :: "<<a<<"\n";


ll n, a[LIM];
ll dp[LIM][LIM][2];
ll solve(int l, int r, int chance) {
	if (l > r)
		return 0;
	ll &cache = dp[l][r][chance];
	if (cache != -1)	return cache;
	if (chance == 1) {
		return cache = max(a[l]+solve(l+1, r, chance^1), a[r]+solve(l, r-1, chance^1));
	} else {
		return cache = min(solve(l+1, r, chance^1), solve(l, r-1, chance^1));
	}
}

int main() {
	int i, j, t;
	memset(dp, -1, sizeof dp );
	scl(n);	
	ll sum = 0;
	for(i=1; i<=n; i++) {
		scl(a[i]);
		sum += a[i];
	}
	//debug2(solve(1, n, 0), sum);
	cout << 2LL*solve(1, n, 1) - sum << endl;
	return 0;
}


