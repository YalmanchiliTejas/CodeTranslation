//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
template<int MOD>struct modint{
	int value=0;
	modint(int x=0){value=x;}
	inline int mypow(int x,int y){
		int a=x,ret=1;
		do{
			if(y&1)ret=(ll)ret*a%mod;
			a=(ll)a*a%mod;
		}while(y>>=1);
	}
	#define inv(x) mypow(x,MOD-2)
	modint operator+(modint<MOD> x){
		value=value+x.value;
		if(value>=MOD)value-=MOD;
		return *this;
	}
	modint operator+(int x){
		value=value+x;
		if(value>=MOD)value-=MOD;
		return *this;
	}
	modint operator-(modint<MOD> x){
		value-=x.value;
		if(value<0)value+=MOD;
		return *this;
	}
	modint operator-(int x){
		value-=x;
		if(value<0)value+=MOD;
		return value;
	}
	modint operator*(modint<MOD> x){
		value=(ll)value*x.value%mod;
		return *this;
	}
	modint operator*(int x){
		value=(ll)value*x%mod;
		return *this;
	}
	modint operator/(modint<MOD> x){
		value=(ll)value*inv(x.value)%mod;
		return *this;
	}
	modint operator/(int x){
		value=(ll)value*inv(x)%mod;
		return *this;
	}
	bool operator<(modint<MOD> x){
		return value<x.value;
	}
	bool operator==(modint<MOD> x){
		return value==x.value;
	}
	bool operator>(modint<MOD> x){
		return value>x.value;
	}
	bool operator<=(modint<MOD> x){
		return value<=x.value;
	}
	bool operator>=(modint<MOD> x){
		return value>=x.value;
	}
	bool operator<(int x){
		return value<x;
	}
	bool operator==(int x){
		return value==x;
	}
	bool operator>(int x){
		return value>x;
	}
	bool operator<=(int x){
		return value<=x;
	}
	bool operator>=(int x){
		return value>=x;
	}
};
bool operator<(int x,modint<mod>y){
	return x<y.value;
}
bool operator==(int x,modint<mod>y){
	return x==y.value;
}
bool operator>(int x,modint<mod>y){
	return x<y.value;
}
bool operator<=(int x,modint<mod>y){
	return x<=y.value;
}
bool operator>=(int x,modint<mod>y){
	return x>=y.value;
}
#define M modint<mod>
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y<=0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int h[105];
pair<M,M>operator*(pair<M,M>a,pair<M,M>b){
	a.first=a.first*(b.first+b.second);
	a.second=a.second*b.second;
	return a;
}
pair<M,M>solve(int l,int r){
	int low=*min_element(h+l,h+r+1);
	int cnt=0;
	for(int i=l;i<=r;i++)h[i]-=low;
	for(int i=l;i<=r;i++)if(!h[i])cnt++;
	int L=l,R=l;h[r+1]=0;
	pair<M,M>ret(M(modpow(2,cnt)),M(2));
	for(int i=l;i<=r+1;i++){
		R=i-1;
		if(h[i]==0){
			if(L<=R)ret=ret*solve(L,R);
			L=i+1;
		}
	}
	ret.first=ret.first-ret.second;
	ret.second=ret.second*modpow(2,low-1);
	ret.first=ret.first+ret.second;
	return ret;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i];
	cout<<solve(1,n).first.value<<endl;
	return 0;
}