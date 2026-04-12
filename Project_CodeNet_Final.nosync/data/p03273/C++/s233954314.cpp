#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cassert>
#include <numeric>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
typedef long long ll;
typedef double lf;
typedef long double llf;
typedef pair<int,int> pii;
typedef vector<int> vec;
#define fi first
#define se second
/* */
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define forEach(i, s) for(auto i=begin(s);i!=end(s);i++)
#define for_each_n(i, s, n) for(auto i=begin(s),_5=next(i,n);i!=_5;i++)
#define pb push_back
#define mp make_pair

/* special */
#define Mem(x) memset(x,0,sizeof(x))
#define GET_MACRO(_0,_1,_2,_3,_NAME,...) _NAME
/* */
#define rep(...)  GET_MACRO(_0,##__VA_ARGS__,rep3,rep2,rep1,rep0)(__VA_ARGS__)
	#define rep3(i,a,b) for(int i=(a);i<(b);++i)
	#define rep2(i,a) for(int i=0;i<(a);++i)
	#define rep1(a) rep2(_,a)
	#define rep0()	while(1)
#define callOnce if([]{static int i=-1;i++;return !i;}())


/* input */
namespace my{
	#define out(x) cout<<(x)<<endl
	inline int in(int &x) {return scanf("%d",&x);}
	inline int in(double &x) {return scanf("%lf",&x);}
	inline int in(ll &x) {return scanf("%lld",&x);}
	inline int in(int &x,int &y) {return scanf("%d %d",&x,&y);}
	inline int in(int &x,int &y,int &z) {return scanf("%d %d %d",&x,&y,&z);}
	inline int in(char s[]) {return scanf("%s",s);}
	inline int in(char &c) {return scanf("%c",&c);}
}

using namespace my;

/* debug */
#ifndef ONLINE_JUDGE
	#define D0()
	#define D1(x) {cout<<" ";cout.width(5);cout<<(x);}
	#define D2(x,y) {D1(x)D1(y)}
	#define D3(x,y,z) {D2(x,y)D1(z)}
	#define Dset(...) for(auto i : __VA_ARGS__ ) D1(i) //std::size()
	#define Darr1(x,fir) for(auto _7 = begin(x),_6=next(begin(x),fir);_7!=_6;++_7) D1(*_7)
	#define Darr2(x,fir,sec) for(auto _8=begin(x),_9=next(begin(x),fir);_8!=_9;++_8){ Darr1((*_8),sec)D()}
	#define D(...) {cout<<#__VA_ARGS__<<" ";GET_MACRO(_0,##__VA_ARGS__,D3,D2,D1,D0)(__VA_ARGS__);cout<<endl;}
	#define Da(...)  {cout<<#__VA_ARGS__;D()GET_MACRO(""##__VA_ARGS__,UNUSED,Darr2,Darr1,Dset)(__VA_ARGS__)D()}
#endif // ONLINE_JUDGE

// template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
#define pow2(X) (1<<(X))
#define gcd __gcd
#define lcm(a,b) ((a)/gcd(a,b)*(b))
ll mod=1e9+7;
inline ll powmod(ll a,ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const double pi=acos(-1.0);
const double eps=1e-11;
const int INF=0x3f3f3f3f;//0x3f
const int NINF=0xcfcfcfcf;//0xcf
const int maxn=1e9+10;
int n,t,T,x,H,W,p,y,v;
char a[110][110];
bool visH[110];
bool visW[110];
int main(){

	cin>>H>>W;
	rep(i,H)rep(j,W){
		cin>>(a[i][j]);
	}
	
	rep(i,H) {
		int flag=1;
		rep(j,W) {
			if(a[i][j]=='#') flag=0;
		}
		if(flag){
			visH[i]=1;
		}
	}

	rep(j,W) {
		int flag=1;
		rep(i,H) {
			if(a[i][j]=='#') flag=0;
		}
		if(flag){
			visW[j]=1;
		}
	}
	rep(i,H){
		if(visH[i]) continue;
		rep(j,W){
			if(visW[j]) continue;
			printf("%c",a[i][j]);
		}
		printf("\n");
		
	}

}
