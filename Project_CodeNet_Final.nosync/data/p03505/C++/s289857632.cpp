//written by libra9z
#ifndef __cplusplus
#error This does not a G++ program!! Please require it...
#endif
#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL_TIME
//#define FILE_JUDGE
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
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <valarray>
#include <utility>
#include <numeric>
#include <memory>
#include <functional>
#include <stdexcept>
#include <typeinfo>
#include <limits>
#include <complex>
#include <locale>
#include <new>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <immintrin.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll,int> plli;
typedef pair <int,pii> pipii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <pii> vpii;
typedef vector <vector<int> > mat;
#define rep(i,n) for (int i=0;i<(n);i++)
#define Rep(i,a,b) for (int i=(a);i<=(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rRep(i,a,b) for (int i=(a);i>=b;i--)
#define repit(it,a) for ((__typeof(a.begin())) it=a.begin();it!=a.end();it++)
#define repx(x,a) for (auto x:a)
#define mp make_pair()
#define X first
#define Y second
#define sqr(x) ((x) * (x))
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define reunique(v) v.erase(unique(v.begin(),v.end()))
#define prl cerr << "called: " << __LINE__ << endl
#define eaq(n,x) __typeof(x) n=x;
#define RET(p,x) return p<<x<<endl,0;
#define Debug(x) cerr<<#x<<" = "<<x<<endl
#define Debug22(x,y) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl
#define Debug2(x, y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<")\n"
#define Debug3(x,y,z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = ("<<x<<", "<<y<<", "<<z<<")\n"
#define Debug_arr(v,n) for(int i=0;i<n;++i) cerr<<#v<<"["<<i<<"]"<<" = "<<v[i]<<endl
#define FOPEN(x) string filename=#x;const string filein=filename+".in",fileout=filename+".out";\
freopen(filein.c_str(),"r",stdin);freopen(fileout.c_str(),"w",stdout)
template <typename T> void read(T &a) {cin>>a;}
template <typename T,typename... Args> void read(T& a,Args&... b){read(a);read(b...);}
template <typename T> void write(T a) {cout<<a<<' ';}
template <typename T,typename... Args> void write(T a,Args... b){write(a);write(b...);}
unsigned long long rdtsc()
{
	unsigned long long ret = 0;
	#ifdef __clang__
    return __builtin_readcyclecounter();
	#endif
	#ifndef _MSC_VER
    asm volatile("rdtsc" : "=A" (ret) : :);
	#endif
	return ret;
}
mt19937 mmtw(960172),mrand(random_device{}());
long long rnd(long long x,long long y)
{
	static uniform_int_distribution <long long> d;
	return d(mmtw)%(y-x+1)+x;
}
int rnd(int x)
{
	return mrand()%x;
}
const ll h1=999999937;
const ll h2=1000000009;
const int inf=2e9;
const ll mod=1000000007;
const int dx[]={1,0,-1,0,1,0,-1,0};
const int dy[]={0,1,0,-1,1,0,-1,0};
const double pi=3.141592653589793;
const bool multitests=false,alotoftests=false;
stringstream sinout;
long long n,a,b;
bool solve(int __test)
{
	cin>>n>>a>>b;
	long long c=a;
	if (c>=n) cout<<1;
	else if (a<=b) cout<<-1;
	else cout<<1LL+2LL*(((n-c)+(a-b-1))/(a-b));
	return false;
}
signed main()
{
	rdtsc();
	#ifdef FILE_JUDGE
	FOPEN(inoutput);
	#endif
	int __tests,__test=1;
	(multitests==true)?((alotoftests==false)?scanf("%d",&__tests):__tests=inf):__tests=1;
	for (;(alotoftests==true && multitests==true)?(!solve(__test)):(__test<=__tests);++__test)
	{
		if (!(multitests==true && alotoftests==true))
		{
			solve(__test);
		}
	}
	#ifdef LOCAL_TIME
	eprintf("\n\nSystem Time : %d ms",clock());
	#endif
	return 0;
}
