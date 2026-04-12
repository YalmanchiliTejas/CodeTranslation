//written by NewbieChd
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

const int BUF = 1000000;
char buf[BUF], *p1, *p2;
inline char getChar() { return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, BUF, stdin), p1 == p2) ? EOF : *p1++; }
inline int read() {
    register int f = 0;
    bool b = 1;
    char c;
    while (!isdigit(c = getChar()))
        if (c == 45)
            b = 0;
    do
        f = f * 10 + (c ^ 48);
    while (isdigit(c = getChar()));
    return b ? f : ~f + 1;
}

const int maxN = 100003;
int s[maxN];

int main() {
    int n = read(), i, l, r;
    long long ans = 0, sum;
    for (i = 0; i < n; ++i)
        s[i] = read();
    for (i = 1; i < n; ++i) {
        l = 0, r = n - 1, sum = 0;
        while (r > i && (l < r || r % i))
            ans = max(ans, sum += s[l] + s[r]), l += i, r -= i;
    }
    printf("%lld\n", ans);
    return 0;
}
