/*
 * if you are interested in the reference code here,
 * see https://github.com/georeth/OJLIBS for more information
 *
 * Solution Author : Georeth Chow <georeth2010@gmail.com>
 */
#include <cstdio>
#include <cmath>
#include <climits>      // INT_MIN LLONG_MIN
#include <cfloat>       // DBL_MIN DBL_MAX
#include <cstring>      // memset
#include <cstdlib>      // malloc
#include <cstdint>      // int64_t
#include <cinttypes>    // PRId64 SCNd64
#include <ctime>        // clock
#include <cassert>      // assert
#include <limits>       // numeric_limits
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <tuple>        // pair, tuple
#include <iostream>     // be careful.
#include <sstream>
#include <algorithm>
using namespace std;    // use as solution header. name polution is fine.
#ifdef LOCAL_JUDGE
#  define pr_debug(...) fprintf(stderr, __VA_ARGS__)
#  define pr_line() fprintf(stderr, "%s: %d\n", __FILE__, __LINE__)
#else
#  define pr_debug(...)
#  define pr_line()
#endif
template <typename T>
bool chmax(T &m, const T &v) { if (v > m) return m = v, true; return false; }
template <typename T>
bool chmin(T &m, const T &v) { if (v < m) return m = v, true; return false; }
template <typename T>
bool chinc(T &v1, T &v2) { if (v1 > v2) return swap(v1, v2), true; return false; }
template <typename T>
bool chdec(T &v1, T &v2) { if (v1 < v2) return swap(v1, v2), true; return false; }
#define ALL(x) begin(x), end(x)
#define FOR0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define FOR1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define FOR(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define FOD0(i,n) for(int i=(n)-1;~i;i--)
#define FOD1(i,n) for(int i=n;i;i--)
#define FOD(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define FORE(i,x)for(__typeof(x.end())i=x.begin();i!=x.end();++i)
typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<vector<int>> vvi;
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <iostream>
namespace fio {
static const char eof = '\xff';
#define LL long long
#define I inline
#define OP operator
#define RT return*this;
#define ALL_INT(mcr) mcr(int)mcr(long)mcr(LL)mcr(unsigned)mcr(unsigned long)mcr(unsigned LL)
#define ALL_FLT(mcr) mcr(float)mcr(double)mcr(long double)
#define S2D x=0;int c=P();while((c<'0'||c>'9')&&c!='-')c=P();bool h=false;if(c=='-')h=true,c=P()
#define R2D for(;c>='0'&&c<='9';c=P())x=x*10+c-'0'
#define R2F if(c=='.'){double u=0.1;for(c=P();c>='0'&&c<='9';c=P(),u*=0.1)x+=u*(c-'0');}
#define RD_INT(Int) I Fr&OP,(Int&x){S2D;R2D;if(h)x=-x;RT}
#define RD_FLT(Flt) I Fr&OP,(Flt&x){S2D;R2D;R2F;if(h)x=-x;RT}
struct Cg{I char OP()(){char c=(char)getchar();if(c == eof)valid=false;return c;};bool valid=true;};
struct Cp{I void OP()(int x){putchar(x);}};
struct Ce{I void OP()(int x){putc(x,stderr);}};
I bool IS(char x){return x==' '||x=='\r'||x=='\n'||x=='\t';}
template<class T>struct Fr{T P;ALL_INT(RD_INT)ALL_FLT(RD_FLT)I Fr&OP,(char&x){for(x=P();IS(x);)x=P();RT}
I Fr&OP,(char*s){for(*s=P();IS(*s)&&P.valid;)*s=P();for(;!IS(*s)&&P.valid;)*++s=P();*s=0;RT}
I Fr&OP,(string &s){s.clear();char c=P();for(;IS(c)&&P.valid;)c=P();for(;!IS(c)&&P.valid;)s.push_back(c),c=P();RT}
I OP bool() { return P.valid; }
};
#define W4D if(x){if(x<0)P('-'),x=-x;int p=0;while(x)B[p++]=x%10+'0',x/=10;while(p--)P(B[p]);}else P('0')
#define WR_INT(Int) I Fw&OP,(Int x){W4D;RT}
#define WR_FLT(Flt) I Fw&OP()(Flt g,int d){if(d){double t=0.5;for(int i=d;i--;)t*=0.1;if(g<0)P('-'),g=-g;g+=t;*this,(LL)(g);P('.');g-=floor(g);while(d--){g*=10;int i=(int)floor(g);P(i+'0');g-=i;}}else*this,(g>0?(LL)(g+0.5):(LL)(g-0.5));RT}
template<class T>struct Fw{T P;char B[32];ALL_INT(WR_INT)ALL_FLT(WR_FLT)I Fw&OP,(char x){P(x);RT}typedef char_traits<char>CT;typedef basic_ostream<char,CT>&OS;typedef basic_istream<char,CT>&IS;I Fw&OP,(OS&(*func)(OS)){if(func==static_cast<OS&(*)(OS)>(endl<char,CT>))P('\n');RT}I Fw&OP,(IS&(*func)(IS)){if(func==static_cast<IS&(*)(IS)>(ws<char,CT>))P(' ');RT}
I Fw&OP,(const char*s){for(;*s;++s)P(*s);RT}
I Fw&OP,(const string&s){(*this),s.c_str();RT}
template<class C>I Fw&all(const C &v, char sep=' ', char nl='\n'){auto it=v.begin();for(int i=0;i<(int)v.size();++i,++it){if(i&&sep)P(sep);(*this),*it;}if(nl)P(nl);RT}
template<class U>I Fw&print(U x){(*this),x;P('\n');RT}
template<class U,class...Us>I Fw&print(U x,Us...args){(*this),x;P(' ');print(args...);RT}
};
#undef LL
#undef I
#undef OP
#undef RT
#undef ALL_INT
#undef ALL_FLT
#undef S2D
#undef R2D
#undef R2F
#undef RD_INT
#undef RD_FLT
#undef W4D
#undef WR_INT
#undef WR_FLT
}
fio::Fr<fio::Cg>fin;
fio::Fw<fio::Cp>fout;
fio::Fw<fio::Ce>ferr;
/* =====  SOLUTION START  ===== */
constexpr int maxn = 100005;
int value[maxn]; // n -> An
int rev[maxn]; // An -> n
int main() {
    int64_t N; int X, M;
    fin, N, X, M;
    int64_t sum = 0;
    int cur = X;
    value[1] = cur;
    rev[cur] = 1;
    sum += cur;
    for (int i = 2; i <= N; ++i) {
        cur = (1LL * cur * cur) % M;
        value[i] = cur;
        if (rev[cur] == 0) {
            rev[cur] = i;
        } else {
            int len = i - rev[cur];
            int64_t loop_sum = 0;
            for (int j = rev[cur]; j < i; ++j)
                loop_sum += value[j];
            int64_t a = N - i + 1;
            int64_t q = a / len;
            int64_t r = a % len;
            pr_debug("len = %d q=%d r=%d loop_sum=%d\n", (int)len, (int)q, (int)r, (int)loop_sum);
            int64_t ans = sum + loop_sum * q;
            for (int j = 0; j < r; ++j)
                ans += value[rev[cur] + j];
            fout, ans, endl;
            return 0;
        }
        sum += cur;
    }
    fout, sum, '\n';
    return 0;
}
