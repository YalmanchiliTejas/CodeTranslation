/*************************************************
 *************************************************
 *************************************************
 *** _________________  |            |  |     /***
 ***         |          |            |  |    / ***
 ***         |          |            |  |   /  ***
 ***         |          |            |  |  /   ***
 ***         |          |            |  | /    ***
 ***         |          |____________|  |/  en ***
 ***         |          |            |  |\     ***
 ***         |          |            |  | \    ***
 *** _____   |          |            |  |  \   ***
 ***   |     |          |            |  |   \  ***
 ***   \     /          |            |  |    \ ***
 ***    \___/           |            |  |     \***
 *************************************************
 *************Written by: JiangHaoKai*************
 *************************************************/

//#include <bits/stdc++.h>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
//#include <windows.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef float fl;
typedef double ld;
typedef pair<int,int> pii;
#define ui(n) ((unsigned int)(n))
#define ll(n) ((long long)(n))
#define ull(n) ((unsigned long long)(n))
#define fl(n) ((float)(n))
#define ld(n) ((double)(n))
#define char(n) ((char)(n))
#define Bool(n) ((bool)(n))
#define fixpoint(n) fixed<<setprecision(n)
const int INF=1e9+7;
const ll LINF=1e18;
#define PI 3.1415926535897932384626433832795028841971
#define MP make_pair
#define MT make_tuple
#define All(a) (a).begin(),(a).end()
#define pall(a) (a).rbegin(),(a).rend()
#define mod 1000000007
#define sz(a) ((int)(a).size())
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repa(i,a,n) for(int i=a;i<n;i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,n,step) for(int i=a;i<n;i+=step)
#define repv(itr,v) for(__typeof((v).begin()) itr=(v).begin();itr!=(v).end();itr++)
#define repV(i,v) for(auto i:v)
#define repE(i,v) for(auto &i:v)
#define MS(x,y) memset(x,y,sizeof(x))
#define sqr(x) ((x)*(x))
#define filein(x) freopen(x,"r",stdin)
#define fileout(x) freopen(x,"w",stdout)
#define fileout2(filename,name) ofstream name(filename,ios::out)
#define filein2(filename,name) ifstream name(filename,ios::in)
#define file(filename,name) fstream name(filename,ios::in|ios::out)
#define Pause system("pause")
#define Cls system("cls")
#define fs first
#define sc second
#define PC(x) putchar(x)
#define GC(x) x=getchar()
#define Endl PC('\n')

inline int READ()
{
    int X=0,w=0;char ch=0;while(!isdigit(ch)){w|=ch=='-';ch=getchar();}while(isdigit(ch))X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	return w?-X:X;
}
inline void WRITE(int x){if(x<0)putchar('-'),x=-x;if(x>9)WRITE(x/10);putchar(x%10+'0');}
inline void WRITEend(int x){WRITE(x);exit(0);}

inline ll powmod(ll a,ll b){ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline ll gcdll(ll a,ll b){return b?gcdll(b,a%b):a;}
inline string itoa(ll a){string res="";while(a>0)res+=(a%10+'0'),a/=10;reverse(All(res));return res==""?"0":res;}
inline ll atoi(string s){ll res=0;repV(i,s)res=res*10+i-'0';return res;}
const int dx[]={0,1,0,-1,1,-1,-1,1};
const int dy[]={1,0,-1,0,-1,-1,1,1};
/**************************************************************Begin***************************************************************/
struct sets
{
	int par[100010],num[100010];
	
	inline void INIT(int n)
	{
		rep(i,n) par[i]=i,num[i]=1;
	}
	
	inline int FIND(int x)
	{
		return x==par[x]?x:par[x]=FIND(par[x]);
	}
	
	inline bool unite(int x,int y)
	{
		x=FIND(x);
		y=FIND(y);
		if(x==y) return 0;
		
		if(num[x]>num[y]) swap(x,y);
		num[y]+=num[x];
		par[x]=y;
		return 1;
	}
}s;

int n=READ(),ans;
vector<pair<int,int> > x,y;
vector<pair<int,pair<int,int> > > v;

int main()
{
	s.INIT(n);
	rep(i,n)
	{
		int a=READ(),b=READ();
		x.push_back(MP(a,i));
		y.push_back(MP(b,i));
	}
	
	sort(All(x));
	sort(All(y));
	rep1(i,n-1)
		v.push_back(MP(x[i].fs-x[i-1].fs,MP(x[i].sc,x[i-1].sc))),
		v.push_back(MP(y[i].fs-y[i-1].fs,MP(y[i].sc,y[i-1].sc)));
	
	sort(All(v));
	rep(i,v.size()) if(s.unite(v[i].sc.fs,v[i].sc.sc)) ans+=v[i].fs;
	
	WRITE(ans);

	return 0;
}
/***************************************************************End****************************************************************/
