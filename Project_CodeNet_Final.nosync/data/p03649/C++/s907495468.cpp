#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

ll a[55];

int main(void){
	int n,i,j;
	ll ans = 0ll,tmp,mx;
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> a[i];
	}
	while(true){
		tmp = 0ll; mx=-INFLL;
		for(i=0; i<n; ++i){
			tmp += a[i]/n;
		}
		ans += tmp;
		for(i=0; i<n; ++i){
			a[i] -= (a[i]/n)*(n+1);
			a[i] += tmp;
			mx = max(mx,a[i]);
		}
		cout << endl;
		if(mx<n){
			cout << ans << endl;
			break;
		}
	}
	return 0;
}
