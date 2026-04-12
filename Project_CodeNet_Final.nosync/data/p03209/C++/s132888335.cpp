#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto& x:c){cout<<x<<' ';}cout<<endl;

using namespace std;
using ll = long long;

template<typename T=int>
T in(){T x; cin >> x; return (x);}

vector<ll> L,P;
ll f(ll l,ll x){
	if(l==0){
		return x<=0 ? 0LL : 1LL;
	}
	else if(x<=L[l-1]+1) return f(l-1,x-1);
	else return P[l-1]+1LL+f(l-1,x-2-L[l-1]);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N=in<ll>(),X=in<ll>();
	L.resize(N+1),P.resize(N+1);
	L[0]=1LL,P[0]=1LL;
	for(int i=1;i<N+1;i++){
		L[i] = 2*L[i-1]+3LL;
		P[i] = 2*P[i-1]+1LL;
	}

	ll c = f(N,X);

	cout << c << endl;
	return 0;
}
