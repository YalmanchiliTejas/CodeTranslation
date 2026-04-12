#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

const ll inf = 10000000001000000;
int n;
ll a[55];

int main() {
	ll sum=0;
	scanf("%d", &n);
	FOR(i,n) scanf("%lld", &a[i]);
	FOR(i,n) sum += a[i];
	for (ll k = sum - n*(n-1); k <= sum; k++) {
		if (k < 0) continue;
		bool ok=true;
		ll res=0;
		FOR(i,n) {
			ll mlo = (a[i]+k+1) / (n+1), mhi = (a[i]+k) / (n+1);
			if (mlo <= mhi) res += mlo;
			else ok=false;
		}
		if (ok && res==k) {
			printf("%lld\n", res);
			return 0;
		}
	}
	return 0;
}
