/**
 * @Author:      H S-J
 * @DateTime:    2017-11-11 20:07:37
 * @Description: 
 */
#include <bits/stdc++.h>
using namespace std;
#define MST(a, b) memset(a, b, sizeof(a));
#define CLR(a) MST(a, 0);
#define DBG(x) cout << '#' << " = " << (x) << endl;
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())
#define lson(x) (x) << 1
#define rson(x) (x) << 1|1
#define pb push_back
#define rep(x, y, z) for (int x = y; x < z; ++x)
#define ech(x, y, z) for (auto x = z.begin(), y = z.end(); x != y; ++x)
#define lowbit(x) (x & (-x))
#define opr operator
#define _st first
#define _nd second
#define prior_q1(x) priority_queue<x>
#define prior_q2(x) priority_queue<x, vector<x>, greater<x> >
typedef long long LL;
typedef stringstream strstm;
struct FastIO {
    static const int S = 1310720;
    int wpos;
    char wbuf[S];
    FastIO() : wpos(0) {}
    inline int xchar() {
        static char buf[S];
        static int len = 0, pos = 0;
        if (pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if (pos == len) return -1;
        return buf[pos ++];
    }
    inline int xuint() {
        int c = xchar(), x = 0;
        while (c <= 32) c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x;
    }
    inline int xint() {
        int s = 1, c = xchar(), x = 0;
        while (c <= 32) c = xchar();
        if (c == '-') s = -1, c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x * s;
    }
    inline LL xlongint() {
        LL s = 1, c = xchar(), x = 0;
        while (c <= 32) c = xchar();
        if (c == '-') s = -1, c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x * s;
    }
    inline void xstring(char *s) {
        int c = xchar();
        while (c <= 32) c = xchar();
        for (; c> 32; c = xchar()) * s++ = c;
        *s = 0;
    }
    inline void wchar(int x) {
        if (wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos ++] = x;
    }
    inline void wint(LL x) {
        if (x < 0) wchar('-'), x = -x;
        char s[24];
        int n = 0;
        while (x || !n) s[n ++] = '0' + x % 10, x /= 10;
        while (n--) wchar(s[n]);
    }
    inline void wstring(const char *s) {
        while (*s) wchar(*s++);
    }
    ~FastIO() {
        if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;
int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(0);cin.tie(0);
	int X, Y, Z;
    cin >> X >> Y >> Z;
	cout << floor((X-Z)/(Y+Z)) << endl;
	return 0;
}