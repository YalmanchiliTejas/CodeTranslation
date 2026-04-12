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
	a += b;
	if(a>=MOD){
		a -= MOD;
	}
}

int main(void){
	int i,j,n,ans=0,h[123];
	bool flag;
	cin >> n;
	for(i=0; i<n; ++i){
		cin >> h[i];
		flag = true;
		for(j=0; j<i; ++j){
			if(h[j]>h[i]){
				flag = false;
				break;
			}
		}
		if(flag){
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
