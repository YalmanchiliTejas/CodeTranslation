/*
СТРОИМ СТЕНУ РАБОТЯГИ!
█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█
█═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═█
█═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═█
█═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═█
█═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═█
█═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═█
█═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═█
█═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═█
█═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═╩═╦═█
█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
    
     
     
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
/** Interface */
     
inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
     
/** Read */
     
static const int buf_size = 4096;
     
inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len) {
        pos = 0, len = fread(buf, 1, buf_size, stdin);
    }
    if (pos == len) {
        return -1;
    }
    return buf[pos++];
}
     
inline int readChar() {
    int c = getChar();
    while (c <= 32) {
        c = getChar();
    }
    return c;
}
     
template <class T>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-')
        s = -1, c = getChar();
    while ('0' <= c && c <= '9')
        x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}
     
/** Write */
     
static int write_pos = 0;
static char write_buf[buf_size];
     
inline void writeChar( int x ) {
    if (write_pos == buf_size)
        fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}
     
template <class T> 
inline void writeInt( T x, char end ) {
    if (x < 0)
        writeChar('-'), x = -x;
     
    char s[24];
    int n = 0;
    while (x || !n)
        s[n++] = '0' + x % 10, x /= 10;
    while (n--)
        writeChar(s[n]);
    if (end)
        writeChar(end);
}
     
inline void writeWord( const char *s ) {     while (*s)
writeChar(*s++); }
     
struct Flusher {
    ~Flusher() {
        if (write_pos)
            fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;
   
   
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
#define y2 y2228
const int MAXN = 10005, Mod = 998244353;


inline int exp(int x, int y, const int Mod=::Mod) {
    int ans = 1;
    while (y) {
        if (y & 1) {
            ans = 1LL * ans * x % Mod;
        }
        x = 1LL * x * x % Mod;
        y >>= 1;
    }
    return ans;
}
 

namespace NTT {
    const int MAXM = 300005;
    int w[MAXM], a[MAXM], b[MAXM]; 
    inline void fft(int *x, int n) { 
        for (int i = 0, j = 0; i < n; i++) {
            if (i < j) {
                swap(x[i], x[j]);
            }
            for (int k = n >> 1; (j ^= k) < k; k >>= 1);
        }
        for (int i = 2; i <= n; i <<= 1) {
            int c = i >> 1, now = n / i;
            for (int j = 0; j < n; j += i) {
                for (int k = 0; k < c; k++) {
                    int t = 1LL * x[j + k +c] * w[now * k] % Mod;
                    x[j + k + c] = (x[j + k] - t) % Mod;
                    (x[j + k] += t) %= Mod;
                }
            }
        }
    }
    inline void mult(int *x, int *y, int n, int *res) {
        int ss = 1, wn;
        while (ss <= (n * 2)) {
            ss <<= 1;
        }
        for (int i = 0; i < ss; i++) {
            a[i] = b[i] = 0;
        }
        for (int i = 0; i <= n; i++) {
            a[i] = x[i], b[i] = y[i];
        }
        w[0] = 1; wn = exp(3, (Mod - 1) / ss);
        for(int i = 1; i <= ss; i++) {
            w[i] = 1LL * w[i - 1] * wn % Mod;
        }
        fft(a, ss);
        fft(b, ss);
        for (int i = 0; i < ss; i++) {
            a[i] = 1LL * a[i] * b[i] % Mod;
        }
        reverse(w + 1, w + ss);
        fft(a, ss);
        int inv = exp(ss, Mod - 2);
        for (int i = 0; i <= n; i++) {
            res[i] = (1LL * a[i] * inv % Mod + Mod) % Mod;
        }
    }
}
 
 
char a[MAXN], b[MAXN];
int n, m, K, dp[MAXN], fact[MAXN], ifact[MAXN];
 

int main() {
    n = 10001;
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % Mod;
    }
    for (int i = 0; i <= n; i++) {
        ifact[i] = exp(fact[i + 1], Mod - 2);
    }
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    int lens = strlen(a + 1);
    n = 0;
    for (int i = 1; i <= lens; i++) {
        if (a[i] == '1') {
            if (b[i] == '1') {
                m++; 
            } else {
                n++;
            }
        }
    }
    K = n + m;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int t = n;
    while (t) {
        if (t & 1) {
            NTT::mult(dp, ifact, m, dp);
        }
        NTT::mult(ifact, ifact, m, ifact);
        t >>= 1;
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = (ans + dp[i]) % Mod;
    }
    ans = (((1LL * ans * fact[n]) % Mod * fact[m]) % Mod * fact[K]) % Mod;
    cout << ans << '\n';
    return 0;
}
