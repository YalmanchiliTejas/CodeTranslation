#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll MOD=1e9+7;

ll tim(ll a,ll b){
	return (a*b)%MOD;
}
ll adm(ll a,ll b){
	return (a+b)%MOD;
}

ll extgcd(ll a,ll b,ll& x, ll& y){
	ll d=a;
	if(b!=0){
		d = extgcd(b, a%b, y, x);
		y -= (a/b) * x;
	}
	else{
		x = 1; y = 0;
	}
	return d;
}
ll mod_inv(ll a,ll m){
	ll x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}


int main(){
	ll N,M,K;
	cin>>N>>M>>K;
	
	ll ans1=0;
	ll ans2=0;
	rep1(i,M-1){
		ans1=adm(ans1,tim(i,M-i));
	}
	ans1=tim(ans1,N);
	ans1=tim(ans1,N);
	
	rep1(i,N-1){
		ans2=adm(ans2,tim(i,N-i));
	}
	ans2=tim(ans2,M);
	ans2=tim(ans2,M);
	ll ans=adm(ans1,ans2);
	
	ll ans3=1;
	ll a=N*M-2;
	ll b=K-2;
//  	cout<<a<<" "<<b<<endl;
	rep(i,b){
		ans3=tim(ans3,a-i);
		ans3=tim(ans3,mod_inv(i+1,MOD));
//      	cout<<ans3<<endl;
	}
	ans=tim(ans,ans3);
//	cout<<ans1<<endl;
//	cout<<ans2<<endl;
//  cout<<ans3<<endl;
	cout<<ans<<endl;
}