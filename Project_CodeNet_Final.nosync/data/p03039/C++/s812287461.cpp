#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
#define SIZE 1000000
ll kaijo[SIZE];
void init() {
	kaijo[0] = 1;
	for (ll i = 1;i < SIZE;i++)kaijo[i] = (kaijo[i - 1] * i) % N;
}

ll inv(ll x) {
	ll res = 1;
	ll k = N - 2;
	ll y = x%N;
	while (k) {
		if (k & 1)res = (res*y) % N;
		y = (y%N)*(y%N) % N;
		k /= 2;
	}
	return res;
}

ll Comb(ll n, ll k) {
	if (n < 0 || k < 0 || (n - k) < 0)return 0;
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
    ll ans = Comb(n*m-2,k-2)%N;
    ll tmp1 = 0;
    for(ll d=1;d<n;d++){
        ll x = (m*m)%N;
        x = (x*(n-d))%N;
        x =(x*d)%N;
        tmp1 =(tmp1+x)%N;
        tmp1 = (tmp1+N)%N;
    }
    ll tmp2 = 0;
    for(ll d=1;d<m;d++){
        ll y = (n*n)%N;
        y = (y*(m-d))%N;
        y =(y*d)%N;
        tmp2 =(tmp2+y)%N;
        tmp2 = (tmp2+N)%N;
    }
    ll tmp = (tmp1+tmp2)%N;
    ans = (ans*tmp)%N;
    cout<<(ans+N)%N<<endl;
    return 0;
}