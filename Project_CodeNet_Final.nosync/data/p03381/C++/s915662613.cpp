#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define FORR(I,A,B) for(ll I = (B-1); I >= (A); --I)
#define SORT(x) (sort(x.begin(),x.end()))
const ll INF=1e18+7;
const ll MOD=1e9+7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> x(n),y;
	FOR(i,0,n)cin>>x[i];
	y = x;
	SORT(x);
	ll a=x[n/2];
	ll b=x[n/2-1];
	FOR(i,0,n){
		if(y[i]<=b)cout<<a<<endl;
		else cout<<b<<endl;
	}
}
