#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=1000000000+5;
const int N=2e5+5;
const ll oo=1e18+5;
const ll mod=1e9+7;

void add_self(ll& a,ll b){
	a+=b;
	if(a>=mod) a-=mod;
}

void sub_self(ll& a,ll b){
	a-=b;
	if(a<0) a+=mod;
}

ll mult(ll a,ll b){
	return a*b%mod;
}

ll poww(ll a,ll b){
	ll r=1;
	while(b){
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	vector<ll> a(n);
	for(ll& x:a) cin>>x;
	ll sum1=0,sum2=0;
	for(int i=0;i<n;++i){
		add_self(sum1,a[i]);
		add_self(sum2,mult(a[i],a[i]));
	}
	ll ans=mult(sum1,sum1);
	sub_self(ans,sum2);
	cout<<mult(ans,poww(2,mod-2));
	return 0;
}
