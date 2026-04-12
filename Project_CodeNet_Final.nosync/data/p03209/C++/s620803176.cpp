#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
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

vector<ll> time2(53);//time2[x]=2^x

ll ans(ll N,ll X){
	if(N==0 && X==1) return 1;
	if(X==1) return 0;
	if(X==time2[N+2]-3) return time2[N+1]-1;
	if(X==time2[N+1]-1) return time2[N];

	if(X<time2[N+1]-1) return ans(N-1,X-1);
	//if(X<time2[N+2]-3) 
	return time2[N]+ans(N-1,X-time2[N+1]+1);
}
//a,b x
int main(){
	ll N,X; cin>>N>>X;

	time2[0]=1;
	rep1(i,52) time2[i]=time2[i-1]*2;

	cout<<ans(N,X);
}