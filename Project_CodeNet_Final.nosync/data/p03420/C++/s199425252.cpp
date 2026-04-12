// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll N,K;
vector<ll>dv[maxn];
ll sum[maxn];

void add(ll ind,ll x){
	while(ind<maxn){
		sum[ind]+=x;
		ind+= (ind & -ind);
	}
}
ll ask(ll ind){
	ll sm=0;
	while(ind>0){
		sm+=sum[ind];
		ind-= (ind & -ind);
	}
	return sm;
}

int main(){
	for(ll i=1;i<maxn;i++)
		for(ll j=i;j<maxn;j+=i)
			dv[j].PB(i);
	cin>>N>>K;
	ll ans=0;
	FORD(i,N-1,K){
		REP(j,sz(dv[N-i]))
			add(dv[N-i][j],1);
		ans+=N-i+ask(N)-ask(i);
	}
	if(K==0)
		ans-=N;
	cout<<ans;
}