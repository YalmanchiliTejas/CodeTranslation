#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> TUP;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define mp(a,b) make_pair(a,b)
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

int main(){
	ll N; cin>>N;
    vector<ll> h(N);
  rep(i,N) cin>>h[i];
  ll ma=0,cnt=0;
  rep(i,N){
  	if(ma<=h[i]){
    	cnt++;
    }
    ma=max(ma,h[i]);
  }
  cout<<cnt;
}