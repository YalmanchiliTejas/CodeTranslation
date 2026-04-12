/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
pair<int,int>solve(vector<int>h){
	if(!h.size())return make_pair(0,1);
	int low=*min_element(h.begin(),h.end());
	vector<int>split;
	for(int i=0;i<h.size();i++){
		h[i]-=low;if(!h[i])split.push_back(i);
	}
	pair<int,int>ret(modpow(2,split.size(),mod),2);
	split.insert(split.begin(),-1);split.push_back(h.size());
	for(int i=0;i+1<split.size();i++){
		vector<int>tmp(h.begin()+split[i]+1,h.begin()+split[i+1]);
		auto got=solve(tmp);
		ret.first=ret.first*(got.first+got.second)%mod;
		ret.second=ret.second*got.second%mod;
	}
	ret.first+=ret.second*(modpow(2,low-1,mod)-1)%mod;ret.first%=mod;
	ret.second=ret.second*modpow(2,low-1,mod)%mod;
	return ret;
}
vector<int>h;
signed main(){
	int n;cin>>n;h.resize(n);
	for(int i=0;i<h.size();i++)cin>>h[i];
	cout<<solve(h).first<<endl;
	return 0;
}