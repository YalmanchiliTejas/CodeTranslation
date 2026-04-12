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

vector<ll> pw2(51,1); vector<ll> pw10(19,1);
ll maxx(ll x,ll y,ll z){return max(max(x,y),z);}
ll minn(ll x,ll y,ll z){return min(min(x,y),z);}
ll gcd(ll x,ll y){if(x%y==0) return y;else return gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
ll myceil(ll x,ll y){if(x<=y) return 1;else if(x%y==0) return x/y;else return x/y+1;}

//a,b x
int main(){
	ll H,W; cin>>H>>W;
	ll cnt=0;
	rep(i,H){
		string tmp; cin>>tmp;
		rep(j,W){
			if(tmp[j]=='#') cnt++;
		}
	}	
	if(cnt==H+W-1) cout<<"Possible";
	else cout<<"Impossible";
}