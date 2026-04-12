#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>
#include <fstream>
#include <assert.h>

using namespace std;


#define LL long long
#define N 201000
#define M 10000100
#define MP make_pair
#define Pi acos(-1.0)
//#pragma comment(linker,"/S    TACK:1024000000,1024000000")
#define ls (rt << 1)
#define rs (ls | 1)
#define md ((ll+rr)/2)
#define lson ls,ll,md
#define rson rs,md+1,rr
#define mod 1000000007
#define inf 0x7fffffff
#define sqr(x) ((x)*(x))
#define eps 1e-6
#define ULL unsigned long long
LL powmod(LL a,LL b) {LL res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
#define F(x) ((x)/3+((x)%3 == 1 ? 0 : tb))
#define G(x) ((x)<tb ? (x)*3+1 : ((x) - tb)*3+2)
#define lowbit(x) ((x)&(-x))
#define fi first
#define se second
#define pii pair<int,int>
#define pil pair<int,LL>
#define pli pair<LL,int>
#define pb push_back
#define sf(n) scanf("%d", &n)
#define ss set<int>::iterator

int gcd(int x,int y){
    while(y){
        int t = x % y;
        x = y;
        y = t;
    }
    return x;
}

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

namespace FastIO {
#define BUF_SIZE 100000 //缓冲区大小可修改
    bool IOError = 0; //IOError == false 时表示处理到文件结尾
    inline char NextChar() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOError = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool Blank(char c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t';
    }
    
    inline void read(int &x){
        bool sign=0; char ch=NextChar(); x=0;
        for (;Blank(ch);ch=NextChar());
        if (IOError)return;
        if (ch=='-')sign=1,ch=NextChar();
        for (;ch>='0'&&ch<='9';ch=NextChar())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(long long &x){
        bool sign=0; char ch=NextChar(); x=0;
        for (;Blank(ch);ch=NextChar());
        if (IOError)return;
        if (ch=='-')sign=1,ch=NextChar();
        for (;ch>='0'&&ch<='9';ch=NextChar())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x){
        bool sign=0; char ch = NextChar(); x=0;
        for (;Blank(ch);ch = NextChar());
        if (IOError)return;
        if (ch=='-')sign=1,ch=NextChar();
        for (;ch>='0'&&ch<='9';ch=NextChar())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=NextChar();
            for (;ch>='0'&&ch<='9';ch=NextChar())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    inline void read(char *s){
        char ch=NextChar();
        for (;Blank(ch);ch=NextChar());
        if (IOError)return;
        for (;!Blank(ch)&&!IOError;ch=NextChar())*s++=ch;
        *s=0;
    }
    inline void read(char &c){
        for (c=NextChar();Blank(c);c=NextChar());
        if (IOError){c=-1;return;}
    }
}
using namespace FastIO;

const LL P = 998244353LL; //119*2^23+1
long long Mul(long long x, long long y) {
    return (x*y-(long long)(x/(long double)P*y+1e-3)*P+P)%P;
}

const int G = 3;

int wn[25];
int qpow (int a, int b, int p) {
    int res = 1;
    a %= p;
    while(b) {
        if(b & 1) res = (LL)res * a % p ;
        b >>= 1;
        a = (LL)a * a % p ;
    }
    return res;
}
void getwn ()
{
    for(int i = 1; i <= 23; ++i) {
        int t = 1 << i;
        wn[i] = qpow(G, (P - 1) / t, P);
    }
}
void change (int *y, int len) {
    int k;
    for(int i = 1, j = len/2; i < len-1; ++i) {
        if(i < j) swap(y[i], y[j]);
        k = len / 2;
        while(j >= k) {
            j -= k;
            k /= 2;
        }
        if(j < k) j+= k;
    }
}

void NTT (int *y, int len, int on) {
    change(y, len);
    int id = 0;
    for(int h = 2; h <= len; h <<= 1) {
        id++;
        for(int j = 0; j < len; j += h) {
            int w = 1;
            for(int k = j; k < j + h / 2; ++k) {
                int u = y[k];
                int t = (LL)y[k+h/2] * w % P ;
                y[k] = ( u + t ) ;
                if( y[k] >= P ) y[k] -= P;
                y[k+h/2] = ( u - t + P );
                if( y[k+h/2] >= P ) y[k+h/2] -= P;
                w = (LL)w * wn[id] % P;
            }
        }
    }
    if(on == -1) {
        for(int i  = 1; i < len /2; ++i)
            swap(y[i], y[len-i]);
        int inv = qpow( len, P-2, P );
        for(int i = 0; i < len; ++i)
            y[i] = (LL)y[i] * inv % P ;
    }
}

int fac[N], inv[N], A[N], B[N], C[N];
char s[N], t[N];

int main()
{
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1LL * fac[i - 1] * i % P;
    inv[N - 1] = qpow(fac[N - 1], P - 2, P);
    for(int i = N - 2; i >= 0; i--) inv[i] = 1LL * inv[i + 1] * (i + 1) % P;
    getwn();
    read(s);read(t);
    int n = strlen(s);
    int a = 0, b = 0;
    for(int i = 0; i < n; i++)
        if(s[i] == '1' && t[i] == '1') a++;
        else if(s[i] != t[i]) b++;
    b /= 2;
    int len = 1;
    while(len  < 2 * n) len <<= 1;
    for(int i = 0; i <= a; i++) A[i] = B[i] = inv[i + 1];
    C[0] = 1;
    n = b;
    while(n)
    {
        if(n & 1)
        {
            NTT(C, len, 1); NTT(A, len, 1);
            for(int i = 0; i < len; i++) C[i] = 1LL * C[i] * A[i] % P;
            NTT(C, len, -1); NTT(A, len, -1);
            for(int i = a + 1; i < len ; i++) C[i] = 0;
        }
        
        memset(B, 0, sizeof B);
        for(int i = 0; i <= a; i++) B[i] = A[i];
        NTT(A, len, 1); NTT(B, len, 1);
        for(int i = 0; i < len; i++) A[i] = 1LL * A[i] * B[i] % P;
        NTT(A, len, -1);
        for(int i = a + 1; i < len; i++) A[i] = 0;
        n >>= 1;
    }
    
    int ans = 0;
    for(int i = 0; i <= a; i++)
    {
        ans += C[i];
        if(ans >= P) ans -= P;
    }
    printf("%d\n",1LL * ans * fac[a] % P * fac[b] % P * fac[a + b] % P);
    return 0;
}