#include <iostream>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <list>
#include <vector>
#include <cfloat>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <cstring>
#include <stack>
#include <deque>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <iterator>
#include <cmath>
#include <bitset>
#ifdef _MSC_VER
#include <hash_map>
#include <hash_set>
using namespace stdext;
#define unordered_map hash_map
#define unordered_set hash_set
#else
#include <unordered_map>
#include <unordered_set>
#include <regex>
#include <tuple>
#endif
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define FI first
#define SE second
#define sz(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define RSORT(x) sort(x.rbegin(),x.rend())
#define SUM(x) accumulate(ALL(x),0)
#define REVERSE(x) reverse(ALL(x))
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORR(i,a,b) for(int i=(a);i>=(b);--i)
#define readchar(c) char c;scanf("%c",&c);
#define readint(i) int i;scanf("%d",&i);
#define read2int(i,j) int i,j;scanf("%d%d",&i,&j);
#define read3int(i,j,k) int i,j,k;scanf("%d%d%d",&i,&j,&k);
#define read4int(i,j,k,l) int i,j,k,l;scanf("%d%d%d%d",&i,&j,&k,&l);
#define printchar(c) printf("%c\n",c);
#define printint(i) printf("%d\n",i);
#define print2int(i,j) printf("%d %d\n",i,j);
#define print3int(i,j,k) printf("%d %d %d\n",i,j,k);
#define print4int(i,j,k,l) printf("%d %d %d %d\n",i,j,k,l);
#define vec vector
#define ins insert
#define u_m unordered_map
#define u_s unordered_set
#define CONTAINS(m,x) (m.find(x)!=m.end())
#define FORI(i,v) for(int i=0;i<(sz(v));++i)
#define FORE(x,v) for(auto x : v)
#define endl "\n"
#define CASE(i) printf("Case #%d: ",i);
#define pf printf
#define nl pf(endl)
#define SEED srand(time(NULL))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
typedef pair<ll,ll> PLL;
typedef vector<pair<ll,ll> > VPLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef set<int> SI;
typedef set<ll> SL;
typedef unordered_set<int> USI;
typedef unordered_set<ll> USL;
/************* define end  *************/
void println(VI x){REP(i,sz(x)) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void scanln(VI& x, int sz){x.resize(sz); REP(i,sz) scanf("%d",&x[i]);}
template<class T> void read(T *x,int l,int r){FOR(i,l,r) read(x[i]);}
void println(int *x,int l,int r){FOR(i,l,r) printf("%d%c",x[i]," \n"[i==r]);}
ll myrand(ll mod) { return ((ll)rand() << 32^(ll)rand() << 16^rand()) % mod; }
#ifdef cf
#define readlong(i) ll i;scanf("%I64d",&i);
#define read2long(i,j) ll i,j;scanf("%I64d%I64d",&i,&j);
#define read3long(i,j,k) ll i,j,k;scanf("%I64d%I64d%I64d",&i,&j,&k);
#define printlong(i) printf("%I64d\n",i);
#define print2long(i,j) printf("%I64d %I64d\n",i,j);
#define print3long(i,j,k) printf("%I64d %I64d %I64d\n",i,j,k);
void println(VL x){REP(i,sz(x)) printf("%I64d%c",x[i]," \n"[i==sz(x)-1]);}
void scanln(VL& x, int sz){x.resize(sz); REP(i,sz) scanf("%I64d",&x[i]);}
void println(ll *x,int l,int r){FOR(i,l,r) printf("%I64d%c",x[i]," \n"[i==r]);}
#else
#define readlong(i) ll i;scanf("%lld",&i);
#define read2long(i,j) ll i,j;scanf("%lld%lld",&i,&j);
#define read3long(i,j,k) ll i,j,k;scanf("%lld%lld%lld",&i,&j,&k);
#define printlong(i) printf("%lld\n",i);
#define print2long(i,j) printf("%lld %lld\n",i,j);
#define print3long(i,j,k) printf("%lld %lld %lld\n",i,j,k);
void println(VL x){REP(i,sz(x)) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void scanln(VL& x, int sz){x.resize(sz); REP(i,sz) scanf("%lld",&x[i]);}
void println(ll *x,int l,int r){FOR(i,l,r) printf("%lld%c",x[i]," \n"[i==r]);}
#endif
void printum(const unordered_map<int,int>& um){for(const auto& it : um){cout<<"Key:"<<it.FI<<endl;cout<<"Value:"<<it.SE<<endl;}}
#define MIN(x) *min_element(ALL(x))
#define MAX(x) *max_element(ALL(x))
#define pdelim printf("==========")
#define QPOP(x) x.front();x.pop()
#define TOYES(x) printf(x?"YES\n":"NO\n")
#define que queue
#define stk stack
#define EB(x,y) PB(MP(x,y))
// kuaidu example: codeforces/practice/1316_C.cc
inline int kuaidu() { int k = 0; char f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())k=k*10+c-'0';return k*f;}

int main(int argc, char* argv[]) {
  /* Do not use for codejam. */
  /* ios_base::sync_with_stdio(false); cin.tie(NULL); */
  string s;cin>>s;
  bool has_A = false, has_B = false;
  for (char c : s) {
    if (c == 'A') has_A = true;
    else has_B = true;
  }
  if (has_A && has_B) printf("Yes\n");
  else printf("No\n");
  return 0;
}

