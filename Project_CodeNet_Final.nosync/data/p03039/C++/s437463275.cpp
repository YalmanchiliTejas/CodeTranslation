#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;

ll kaijo[200010];

void init() {
	kaijo[0] = 1;
	for (ll i = 1;i < 200010;i++)kaijo[i] = (kaijo[i - 1] * i) % N;
}

ll inv(ll x) {
	ll res = 1;
	ll k = N - 2;
	ll y = x;
	while (k) {
		if (k & 1)res = (res*y) % N;
		y = (y%N*y%N) % N;
		k /= 2;
	}
	return res;
}

ll Comb(ll n, ll k) {
	//if (n < 0 || k < 0 || (n - k) < 0)return 0;
	ll b = kaijo[n];
	ll c = kaijo[n - k];
	ll d = kaijo[k];
	ll cd = (c*d) % N;
	return ((b%N)*(inv(cd)) % N) % N;
}

int main(void){
    init();
    ll n,m,k;
    cin>>n>>m>>k;
    ll sum1=0,sum2=0;
    for(ll d=1;d<=n-1;d++){
        sum1=(sum1+d*(n-d)*m*m%N)%N;
    }
    for(ll d=1;d<=m-1;d++){
        sum2=(sum2+d*(m-d)*n*n%N)%N;
    }
    cout<<(Comb(n*m-2,k-2)*((sum1+sum2+N)%N)%N+N)%N<<endl;
    return 0;
}