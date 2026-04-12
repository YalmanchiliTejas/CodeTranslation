#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<iomanip>
#include<utility>
using namespace std;
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define rg register
#define il inline
#define lch(x) ((x)<<1)
#define rch(x) ((x)<<1^1)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define rep0(i,n) for(register int i=0;i<(n);++i)
#define per0(i,n) for(register int i=(n)-1;i>=0;--i)
#define rep(i,st,ed) for(register int i=(st);i<=(ed);++i)
#define per(i,ed,st) for(register int i=(ed);i>=(st);--i)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double dbl;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> il T qmin(const T &a,const T &b){return a<b?a:b;}
template<typename T> il T qmax(const T &a,const T &b){return a>b?a:b;}
template<typename T> il void getmin(T &a,const T &b){if(a>b) a=b;}
template<typename T> il void getmax(T &a,const T &b){if(a<b) a=b;}
il void fileio(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int inf=(int)1e9+7;
const ll linf=(ll)1e17+7;
const int N=55;

ll a[N],sum,k;
int n;

il ll calc(ll mx){
	ll sum=0;
	rep(i,1,n){
		sum+=qmax(a[i]-mx,0ll)/(n+1);
	}
	return sum;
}

int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%lld",a+i);
		sum+=a[i];
	}
	if(sum>n*n){
		ll x=sum-n*(n-1);
		k+=x;
		rep(i,1,n) a[i]+=x;
		ll ul=-1,ur=50000000000000000;
		while(ur-ul>1){
			ll mid=ul+ur>>1;
			if(calc(mid)<=x) ur=mid;else ul=mid;
		}
		x-=calc(ur);
		rep(i,1,n) a[i]-=qmax(a[i]-ur,0ll)/(n+1)*(n+1);
		while(x--){
			ll mx=a[1];
			rep(i,1,n) getmax(mx,a[i]);
			rep(i,1,n) if(a[i]==mx){
				a[i]-=n+1;
				break;
			} 
		} 
	}
	while(true){
		ll mx=0;
		rep(i,1,n) getmax(mx,a[i]);
		if(mx<n) break;
		++k;
		rep(i,1,n){
			if(a[i]==mx) a[i]-=n,mx=-1;
			else ++a[i];
		}
	}
	printf("%lld\n",k); 
	return 0;
}
