#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

#define FOR(i, l, r)  for (int(i) = int(l); int(i) <= int(r); ++i)
#define FORD(i, r, l) for (int(i) = int(r); int(i) >= int(l); --i)
#define hashmap unordered_map
#define hashset unordered_set
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itr iterator
#define rtr reverse_iterator

enum enum_t {White, Black, Gray};
typedef double          db;
typedef long long       ll;     typedef unsigned long long  ull;
typedef pair<int, int>  pi;     typedef pair<ll, ll>    pll;
typedef map<int, int>   mi;     typedef map<ll, ll>     mll;
typedef set<int>        si;     typedef vector<si>      vsi;
typedef set<ll>         sll;    typedef vector<sll>     vsll;
typedef set<pi>         spi;    typedef vector<spi>     vspi;
typedef set<pll>        spll;   typedef vector<spll>    vspll;
typedef vector<enum_t> ve;     typedef vector<ve>      vme;
typedef vector<string>  vs;     typedef vector<vs>      vms;
typedef vector<bool>    vb;     typedef vector<vb>      vmb;
typedef vector<char>    vc;     typedef vector<vc>      vmc;
typedef vector<int>     vi;     typedef vector<vi>      vmi;    
typedef vector<ll>      vll;    typedef vector<vll>     vmll;
typedef vector<pi>      vpi;    typedef vector<vpi>     vmpi;
typedef vector<pll>     vpll;   typedef vector<vpll>    vmpll;

inline int readInt()       {char c;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));bool sign=(c=='-');if(sign)c=getchar();int n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';return(!sign)?n:-n;}
inline ll readLong()       {char c;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));bool sign=(c=='-');if(sign)c=getchar();ll  n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';return(!sign)?n:-n;}
inline void getInt(int& n) {char c;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));bool sign=(c=='-');if(sign)c=getchar();    n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';      if(sign)n=-n;}
inline void getLong(ll& n) {char c;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));bool sign=(c=='-');if(sign)c=getchar();    n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';      if(sign)n=-n;}
inline string readString() {char c;while(c=getchar(),c==' '||c=='\n'||c=='\t');string s({c});while(c=getchar(),c!=EOF&&c!=' '&&c!='\n'&&c!='\t')s+=c;return s;}
char bufWrite[20];
template<typename T>inline void writeInt(T x)               {if(x<0)putchar('-'),x=-x;char*bufPos=bufWrite;do{*bufPos++=x%10+'0';}while(x/=10);do{putchar(*--bufPos);}while(bufPos>bufWrite);}
template<typename T>inline void printInt(T x, char c = EOF) {if(x<0)putchar('-'),x=-x;char*bufPos=bufWrite;do{*bufPos++=x%10+'0';}while(x/=10);do{putchar(*--bufPos);}while(bufPos>bufWrite);if(c!=EOF)putchar(c);}
template<typename T>inline T gcd(T a,T b){while(b!=0)swap(b,a%=b);return a;}
template<typename T>inline T lcm(T a,T b){return a/gcd(a,b)*b;}
template<typename T>inline tuple<T,T,T>extgcd(T a,T b){if(!a)return mt(b,0,1);T g,x,y;tie(g,x,y)=extgcd(b%a,a);return mt(g,y-(b/a)*x,x);}
template <class T> T    bitGet    (T  x, int bit)           { return T(1) & (x >> (bit - 1)); }
template <class T> void bitSet    (T &x, int bit)           { x |=  (T(1) << (bit - 1)); }
template <class T> void bitReset  (T &x, int bit)           { x &= ~(T(1) << (bit - 1)); }
template <class T> void bitFlip   (T &x, int bit)           { x ^=  (T(1) << (bit - 1)); }
template <class T> void bitMake   (T &x, int bit, bool val) { x ^=  (T(1) << (bit - 1)) & (-val ^ x); }
/// ======================================================================
/// ======================================================================
// const db oo = 0.1 / 0; /// inf
const ll LINF = (1LL << 60); /// 1e18
const int INF = (1 << 30); /// 1e9
const int LIM = (1 << 24); /// 1e7
const int MOD = 1e9 + 7;
const int BASE = 1e4;
const int DIGIT = 4;


/// ======================================================================

vi v;
int n, k;
vector<vmi> f(2);
vi x(10);
int magic(int i = 0, int val = 0, bool ok = false)
{
    if (i >= n) return val == 0;
    int &res = f[ok][i][val];
    if (res != -1) return res;
    else res = 0;

    int lim = ok ? 9 : v[i];
    for (int j = 0; j <= lim; ++j)
        res = (res + magic(i + 1, (val + j) % k, ok || (j < v[i]))) % MOD;

    return res;
}

int main()
{
    string s = readString();
    n = s.size();
    k = readInt();

    v.resize(n);
    for (int i = 0; i < n; ++i)
        v[i] = s[i] - '0';

    f.assign(2, vmi(n, vi(k, -1)));
    cout << (magic() - 1 + MOD) % MOD;
    return 0;
}