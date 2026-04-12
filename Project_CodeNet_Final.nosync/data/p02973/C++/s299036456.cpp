#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define sz size()
#define pb(x) push_back(x) 
#define bg begin()
#define ed end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define mp(x,y) make_pair(x,y)
const ll MOD=1000000007;

ll maxx(ll x,ll y,ll z){
	return max(max(x,y),z);
}
ll minn(ll x,ll y,ll z){
	return min(min(x,y),z);
}
ll gcd(ll x,ll y){
	if(x%y==0) return y;
    else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
	return x*(y/gcd(x,y));
}
ll myceil(ll x,ll y){//yがいくつ集まったらx以上になるか
	if(x<=y) return 1;
	else if(x%y==0) return x/y;
	else return x/y+1;
}

//a,b x
int main(){
	ll N; cin>>N;
	vector<ll> A;
	ll first; cin>>first;
	A.pb(first);
	rep(RE,N-1){
		ll tmp; cin>>tmp;
		if(tmp<=A[A.sz-1]){//追加するしかない
			A.pb(tmp);
		}
		else if(tmp>A[0]) A[0]=tmp;
		else{//おきかえる(A[A.sz-1]<tmp<=A[0])
			ll l=0,r=A.sz-1;
			while(r-l>=1){
				ll i=(l+r)/2;
				if(A[i]>=tmp) l=i+1;
				else r=i;
			}
			A[l]=tmp;
		}
	}
	cout<<A.sz;
}