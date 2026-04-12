#include <bits/stdc++.h>
using namespace std;

#define pb(a) push_back(a)

typedef long long ll;
const ll inf = 1e9+7;
const int dsize = 1e5+5;
int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};
vector<ll> prime;

ll inv[dsize],fac[dsize];

inline ll GCD(ll a,ll b){ll c;while(b!=0){c=a%b;a=b;b=c;}return a;}
inline ll LCM(ll a,ll b){return a*b/GCD(a,b);}
inline ll POW(ll a,ll b){ll c=1;while(b>0){if(b&1){c=a*c%inf;}a=a*a%inf;b>>=1;}return c;}
inline void _nCr(){fac[0]=1;for(int i=1;i<dsize;i++){fac[i]=fac[i-1]*i%inf;}for(int i=0;i<dsize;i++){inv[i]=POW(fac[i],inf-2);}}
inline ll nCr(ll n,ll r){return (fac[n]*inv[r]%inf)*inv[n-r]%inf;}
inline void PRI(ll n){bool a[n+1];for(int i=0;i<n+1;i++){a[i]=1;}for(int i=2;i<n+1;i++){if(a[i]){prime.pb(i);ll b=i;while(b<=n){a[b]=0;b+=i;}}}}

int main() {
	int n,k;
	cin >> n >> k;
	ll ans = 0;
	for (int i = 1;i <= n;i++) {
		int p = n/i;
		ans += p * max(0,i-k);
		ans += max(0,n%i-k+1);
	}
	if (k == 0) ans -= n;
	cout << ans << endl;
}