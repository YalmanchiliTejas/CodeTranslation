// #pragma GCC optimize(2)
// #pragma G++ optimize(2)
// #pragma comment(linker,"/STACK:102400000,102400000")

//#include <bits/stdc++.h>
#include <map>
#include <set>
#include <list>
#include <array>
#include <cfenv>
#include <cmath>
#include <ctime>
#include <deque>
#include <mutex>
#include <queue>
#include <ratio>
#include <regex>
#include <stack>
#include <tuple>
#include <atomic>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <chrono>
#include <cstdio>
#include <cwchar>
#include <future>
#include <limits>
#include <locale>
#include <memory>
#include <random>
#include <string>
#include <thread>
#include <vector>
#include <cassert>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <cwctype>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <ccomplex>
#include <cstdbool>
#include <iostream>
#include <typeinfo>
#include <valarray>
#include <algorithm>
#include <cinttypes>
#include <cstdalign>
#include <stdexcept>
#include <typeindex>
#include <functional>
#include <forward_list>
#include <system_error>
#include <unordered_map>
#include <unordered_set>
#include <scoped_allocator>
#include <condition_variable>
//#include <conio.h>
//#include <windows.h>
using namespace std;

typedef long long LL;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef float fl;
typedef double ld;
typedef long double LD;
typedef pair<int,int> pii;
#if (WIN32) || (WIN64) || (__WIN32) || (__WIN64) || (_WIN32) || (_WIN64) || (WINDOWS)
#define lld "%I64d"
#define llu "%I64u"
#else
#define lld "%lld"
#define llu "%llu"
#endif
#define ui(n) ((unsigned int)(n))
#define LL(n) ((long long)(n))
#define ull(n) ((unsigned long long)(n))
#define fl(n) ((float)(n))
#define ld(n) ((double)(n))
#define LD(n) ((long double)(n))
#define char(n) ((char)(n))
#define Bool(n) ((bool)(n))
#define fixpoint(n) fixed<<setprecision(n)

const int INF=1061109567;
const LL LINF=4557430888798830399;
const ld eps=1e-15;
#define MOD (1000000007)
#define PI (3.1415926535897932384626433832795028841971)

/*
#define MB_LEN_MAX 5
#define SHRT_MIN (-32768)
#define SHRT_MAX 32767
#define USHRT_MAX 0xffffU
#define INT_MIN (-2147483647 - 1)
#define INT_MAX 2147483647
#define UINT_MAX 0xffffffffU
#define LONG_MIN (-2147483647L - 1)
#define LONG_MAX 2147483647L
#define ULONG_MAX 0xffffffffUL
#define LLONG_MAX 9223372036854775807ll
#define LLONG_MIN (-9223372036854775807ll - 1)
#define ULLONG_MAX 0xffffffffffffffffull
*/

#define MP make_pair
#define MT make_tuple
#define All(a) (a).begin(),(a).end()
#define pall(a) (a).rbegin(),(a).rend()
#define log2(x) log(x)/log(2)
#define Log(x,y) log(x)/log(y)
#define sz(a) ((int)(a).size())
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define rep1(i,n) for(int i=1;i<=((int)(n));i++)
#define repa(i,a,n) for(int i=((int)(a));i<((int)(n));i++)
#define repa1(i,a,n) for(int i=((int)(a));i<=((int)(n));i++)
#define repd(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define repd1(i,n) for(int i=((int)(n));i>=1;i--)
#define repda(i,n,a) for(int i=((int)(n));i>((int)(a));i--)
#define repda1(i,n,a) for(int i=((int)(n));i>=((int)(a));i--)
#define FOR(i,a,n,step) for(int i=((int)(a));i<((int)(n));i+=((int)(step)))
#define repv(itr,v) for(__typeof((v).begin()) itr=(v).begin();itr!=(v).end();itr++)
#define repV(i,v) for(auto i:v)
#define repE(i,v) for(auto &i:v)
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x) MS(x,0)
#define MINF(x) MS(x,63)
#define MCP(x,y) memcpy(x,y,sizeof(y))
#define sqr(x) ((x)*(x))
#define UN(v) sort(All(v)),v.erase(unique(All(v)),v.end())
#define filein(x) freopen(x,"r",stdin)
#define fileout(x) freopen(x,"w",stdout)
#define fileio(x)\
	freopen(x".in","r",stdin);\
	freopen(x".out","w",stdout)
#define filein2(filename,name) ifstream name(filename,ios::in)
#define fileout2(filename,name) ofstream name(filename,ios::out)
#define file(filename,name) fstream name(filename,ios::in|ios::out)
#define Pause system("pause")
#define Cls system("cls")
#define fs first
#define sc second
#define PC(x) putchar(x)
#define GC(x) x=getchar()
#define Endl PC('\n')
#define SF scanf
#define PF printf

inline int Read()
{
    int X=0,w=0;char ch=0;while(!isdigit(ch)){w|=ch=='-';ch=getchar();}while(isdigit(ch))X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	return w?-X:X;
}
inline void Write(int x){if(x<0)putchar('-'),x=-x;if(x>9)Write(x/10);putchar(x%10+'0');}

inline LL powmod(LL a,LL b){LL RES=1;a%=MOD;assert(b>=0);for(;b;b>>=1){if(b&1)RES=RES*a%MOD;a=a*a%MOD;}return RES%MOD;}
inline LL gcdll(LL a,LL b){return b?gcdll(b,a%b):a;}
const int dx[]={0,1,0,-1,1,-1,-1,1};
const int dy[]={1,0,-1,0,-1,-1,1,1};
/************************************************************Begin************************************************************/
const int maxn=55;

int N;
LL x,len[maxn],patty[maxn],ans;

inline void dfs(int n)
{
	if(x==len[n])
	{
		ans+=patty[n];
		return;
	}
	else 
	{
		if(x==0) return;

		x--;

		if(x>len[n-1])
		{
			ans+=patty[n-1]+1;
			x-=len[n-1]+1;

			dfs(n-1);
		}
		else
		{
			dfs(n-1);
		}
	}
}

int main()
{
	len[0]=patty[0]=1;
	rep1(i,50)
	{
		len[i]=len[i-1]*2+3;
		patty[i]=patty[i-1]*2+1;
	}

	SF("%d%lld",&N,&x);

	dfs(N);

	PF("%lld",ans);

	return 0;
}
/*************************************************************End**************************************************************/