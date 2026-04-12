//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y<=0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int h[105],g[105];
inline int add(int x,int y){
	return (x+y)%mod;
}
inline int mul(int x,int y){
	return x*y%mod;
}
inline int sub(int x,int y){
	return (x-y+mod)%mod; 
}
pair<int,int>operator*(pair<int,int>a,pair<int,int>b){
	a.first=mul(a.first,add(b.first,b.second));
	a.second=mul(a.second,b.second);
	return a;
}
pair<int,int>solve(int l,int r){
	int low=*min_element(h+l,h+r+1);
	int cnt=0;
	for(int i=l;i<=r;i++)h[i]-=low;
	for(int i=l;i<=r;i++)if(!h[i])cnt++;
	int L=l,R=l;h[r+1]=0;
	pair<int,int>ret(modpow(2,cnt),2);
	for(int i=l;i<=r+1;i++){
		R=i-1;
		if(h[i]==0){
			if(L<=R)ret=ret*solve(L,R);
			L=i+1;
		}
	}
	ret.first=sub(ret.first,ret.second);
	ret.second=mul(ret.second,modpow(2,low-1));
	ret.first=add(ret.first,ret.second);
	return ret;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i];
	cout<<solve(1,n).first<<endl;
	return 0;
}