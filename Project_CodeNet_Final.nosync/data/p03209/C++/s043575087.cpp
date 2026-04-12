#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)
typedef pair<int, int> P;
typedef pair<int, P> E;
#define MOD (1000000007ll)
#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	b += MOD;
	a += b;
	a %= MOD;
}

ll p[55]={1ll},s[55]={1ll};

int main(void){
	int n,i;
	ll x,ans=0ll,t;
	cin >> n >> x;
	for(i=0; i<n; ++i){
		p[i+1] = 2*p[i]+1;
		s[i+1] = 2*s[i]+3;
	}
	while(n){
		t = (1+s[n])/2;
		if(x==1ll){
			break;
		}else if(x==s[n]){
			ans += p[n];
			break;
		}else if(x<t){
			--x;
		}else{
			ans += p[n-1];
			ans += 1;
			x -= t;
			if(!x){
				break;
			}
		}
		--n;
	}
	if(n==0ll && x==1ll){
		++ans;
	}
	cout << ans << endl;
	return 0;
}

