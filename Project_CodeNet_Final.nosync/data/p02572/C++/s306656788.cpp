#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef complex <double> cp;
#define debug(a) cout<<#a<<":"<<a<<endl;
#define fr freopen("in.txt","r",stdin);
#define Fill(x,a) memset(x,a,sizeof(x))
#define cpy(a,b) memcpy(a,b,sizeof(a))
const double PI = acos(-1);
const ll INF=0x3f3f3f3f;
const ll N=1e6+7;
const ll mod=1e9+7;
ll maxn,minn;
ll T,n,m,q;
ll sum[N];
ll arr[N];

int main(){
	cin >> n;
	for(ll i = 1; i <= n; i ++ ){
		scanf("%lld", arr + i);
	}
	sum[n + 1] = 0;
	for(ll i = n; i >= 1; i -- ){
		sum[i] = (sum[i + 1] + arr[i] ) % mod;
	}
	ll ans = 0;
	for(ll i = 1; i <= n; i ++ ){
		ans = (ans + sum[i + 1] * arr[i] % mod ) % mod ;
	}
	cout << ans << endl;
	



	return 0;
}

