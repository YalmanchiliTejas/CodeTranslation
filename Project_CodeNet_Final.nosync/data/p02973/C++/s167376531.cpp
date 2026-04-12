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

set<ll> st;
map<ll, int> cnt;

int main(void){
	int n,i,ans=0;
	ll a,v;
	cin >> n;
	st.insert(INFLL);
	for(i=0; i<n; ++i){
		cin >> a;
		v = *st.upper_bound(-a);
		if(v==INFLL){
			++ans;
		}else{
			--cnt[-v];
			if(!cnt[-v]){
				st.erase(v);
			}
		}
		st.insert(-a);
		++cnt[a];
	}
	cout << ans << endl;
	return 0;
}
