// - YDK - {{{
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <tuple>
#include <cmath>
#include <queue>
#include <regex>
#include <set>
#include <map>
using namespace std;
#define eb          emplace_back
#define emp         emplace
#define fi          first
#define se          second
#define debug(...)  fprintf(stderr, __VA_ARGS__ )
#define outl(x)     out < (x) < '\n'
#define outl2(x,y)  out < (x) < ' ' < (y) < '\n'
#define rep(i,n)    for(int i=0; i<(int)(n); ++i)
#define ALL(x)      x.begin(), x.end()
#define ODD(n)      ((n)&1)
#define EVEN(n)     (!ODD(n))
#define _NAMESPACE_YDK_ namespace ydk {
#define _END_NAMESPACE_ }
template<class A, class B>inline bool chmax(A &a, B b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, B b){return b<a ? a=b,1 : 0;}
template<class T>using MinHeap = priority_queue< T, vector<T>, greater<T> >;
using ll  = long long;
using pii = pair<int, int>;
inline bool inside(int x, int y, int W, int H) { return x>=0 && y>=0 && x<W && y<H; }
constexpr int       INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
struct Point: public pii {
    int &x = this->first,   &y = this->second;
    explicit Point(int x=0, int y=0): pii(x, y) {}
};
struct Writer
{
    static constexpr size_t BUFF_SIZE = 1 << 18;
    static char _buf[BUFF_SIZE];
    explicit Writer() { setvbuf(stdout, _buf, _IOFBF, sizeof(_buf)); }
    inline void    ln()         {putchar('\n');}
    inline Writer& operator() (int n)   {printf("%d", n);                return *this;}
    inline Writer& operator() (ll  n)   {printf("%lld", n);              return *this;}
    inline Writer& operator() (char c)  {printf("%c", c);                return *this;}
    inline Writer& operator() (double d){printf("%lf", d);               return *this;}
    inline Writer& operator() (const char* s){printf("%s", s);           return *this;}
    inline Writer& operator() (const string &s){printf("%s", s.c_str()); return *this;}
    inline Writer& operator() (bool f)  {printf("%s", f?"true":"false"); return *this;}
    inline Writer& operator() (void)  {putchar('\n'); return *this;}

    template<class InputIterator>
    inline Writer& operator() (InputIterator first, InputIterator last, const char *space=" ")
    {
        for(; first != last; ++first) {
            (*this)(*first);
            printf("%s", (first+1 == last)? "\n" : space);
        }
        return *this;
    }
};
char Writer::_buf[BUFF_SIZE];
template<class T> inline Writer& operator < (Writer &o, const T &v) { return o(v); }

struct Scanner
{
    char tmp[65536];
    inline Scanner& read(int &n)    {scanf("%d", &n);       return *this;}
    inline Scanner& read(ll  &n)    {scanf("%lld", &n);     return *this;}
    inline Scanner& read(char &c)   {scanf(" %c", &c);      return *this;}
    inline Scanner& read(double &d) {scanf("%lf", &d);      return *this;}
    inline Scanner& read(char *s)   {scanf("%s", s);        return *this;}
    inline Scanner& read(string &s) {scanf("%s",tmp); s=string(tmp); return*this;}
};
template<class T> inline Scanner& operator > (Scanner &in, T &v) { return in.read(v); }
template<class T> inline Scanner& operator , (Scanner &in, T &v) { return in.read(v); }
Writer  out;
Scanner in;
// }}}

_NAMESPACE_YDK_

constexpr int LIM = (int)1e5 * 3;

int n;
int a[LIM];
deque<int> dq;

signed main(void)
{
    bool rev = false;

    in> n;
    rep(i, n) {
        in> a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (rev) {
            dq.push_front(a[i]);
        }
        else {
            dq.push_back(a[i]);
        }
        rev = !rev;
    }

    if (rev) {
        while(dq.size()) {
            cout << dq.back() << (dq.size()==1? '\n' : ' ');
            dq.pop_back();
        }
    }
    else {
        while(dq.size()) {
            cout << dq.front() << (dq.size()==1? '\n' : ' ');
            dq.pop_front();
        }
    }
    return 0;
}

_END_NAMESPACE_

signed main(void) { return ydk::main(); }

//--------END--------

