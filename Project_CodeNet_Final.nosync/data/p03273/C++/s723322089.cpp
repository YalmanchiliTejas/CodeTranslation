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

//a,b x
int main(){
	ll H,W; cin>>H>>W;
	char s[101][101];
	rep(i,H){
		string tmp; cin>>tmp;
		rep(j,W){
			s[i][j]=tmp[j];
		}
	}
	vector<bool> row(H,true);
	ll cnt=0; 
	rep(i,H){
		rep(j,W){
			if(s[i][j]=='.') cnt++;
		}
		if(cnt==W) row[i]=false;
		cnt=0;
	}
	vector<bool> col(W,true);
	rep(i,W){
		rep(j,H){
			if(s[j][i]=='.') cnt++;
		}
		if(cnt==H) col[i]=false;
		cnt=0;
	}
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(row[i] && col[j]) cout<<s[i][j];
		}
		if(row[i]) cout<<endl;
	}
}