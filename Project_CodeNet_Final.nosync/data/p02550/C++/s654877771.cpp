#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define PER(j,n,a) for (int j=n-1;j>=a;j--)
#define REP(i,a,n) for (int i=a;i<n;i++)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define show(x) cout<<(x)<<endl
#define UM unordered_map
#define PB push_back
#define V vector
#define EPS 1e-8
typedef unsigned long ul;
typedef long long ll;
typedef string str;
/*FIN*/

int main() {
	FAST;
	ll x,m;
	ll n;
	cin>>n>>x>>m;
	V<ll> u(m,-1), a(m);
	ll p,sz = 0,ans = 0;
	while(n>0 and u[x]==-1) {
		ans += x;
		u[x] = sz;
		a[sz] = x;
		sz++, n--;
		p = x;
		x = (x*x)%m;
	}
	if(n>0) {
		if(p==x)
			ans += n * x;
		else {
			ll csum = 0;
			ll cl = u[p] - u[x] + 1;
			REP(i,u[x],u[p]+1) csum += a[i];
			ans += (n/cl)*csum;
			n %= cl;
			REP(i,u[x],u[x]+n) ans += a[i];
		}
	}
	show(ans);
	return 0;
}

