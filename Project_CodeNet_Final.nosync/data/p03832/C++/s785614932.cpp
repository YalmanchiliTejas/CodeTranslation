#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 1010
ll MOD = 1e9+7;

ll memo[MAXN][MAXN];
ll N,a,b,c,d;
ll F[MAXN];
ll Finv[MAXN];
ll I[MAXN];

ll exp(ll a, ll p){
	if (p==0)return 1;
	ll t = exp(a,p/2);
	t = t*t%MOD;
	if(p%2)t=t*a%MOD;
	return t;
}

ll inv(ll x){
	return exp(x,1e9+5);
}

ll C(ll T, ll a){
	assert(a <= T);
	return ((F[T]*Finv[a])%MOD)*Finv[T-a]%MOD;
}

ll ask(ll left, ll A){
	if (memo[left][A] != -1)return memo[left][A];
	if (left == 0)return memo[left][A] = 1;
	if (A == b+1)return memo[left][A] = 0;
	if (left < A)return memo[left][A] = 0;

	ll ans = 0;
	ll mult = 1;
	ll nl = left;

	for (int e=1;e<c;++e){
		if (nl < A)break;
		mult = (((mult * C(nl,A))%MOD) * I[e])%MOD;
		nl -= A;
	}

	for (int e=c;e<=d;++e){
		if (nl<A)break;
		mult = (((mult * C(nl,A))%MOD) * I[e])%MOD;
		nl -= A;
		// cout<<"Mult "<<left<<' '<<A<<' '<<mult<<'\n';
		ans = (ans + ask(nl, A+1)*mult) %MOD;
	}

	ans = (ans+ask(left,A+1))%MOD;
	// cout<<"Ask "<<left<<' '<<A<<' '<<ans<<'\n';
	return memo[left][A] = ans;
}

int main(){
	cin>>N>>a>>b>>c>>d;
	F[0] = 1;
	for (int i=1;i<=N;++i)F[i] = (F[i-1]*i)%MOD;
	for (int i=0;i<=N;++i)Finv[i] = (inv(F[i]))%MOD;
	for (int i=0;i<=N;++i)I[i] = inv(i);
	memset(memo,-1,sizeof(memo));
	cout<<ask(N,a);
}