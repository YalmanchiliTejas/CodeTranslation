#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>

using LL = long long;
using ULL = unsigned long long;
#ifdef __linux__
using LLL = __int128;
using ULLL = unsigned __int128;
#else
using LLL = long long;
using ULLL = unsigned long long;
#endif

namespace std {
    void swap(int& x, int& y) { x ^= y ^= x ^= y; }
    void swap(LL& x, LL& y) { x ^= y ^= x ^= y; }
};  // namespace std

#ifdef LX_LOCAL
class Time {
public:
    clock_t begin;
    long duration;
    static clock_t currentTime() { return clock(); }
    Time() {
        begin = currentTime();
        duration = 0;
    }
    ~Time() {
        auto end = currentTime();
        auto d = end - begin;
        duration += d;
        double t = duration / 1000.0;
        if (t >= 60000)
            fprintf(stderr, "Time used = %.2lfmin\n", t / 60000.0);
        else if (t >= 1000)
            fprintf(stderr, "Time used = %.2lfs\n", t / 1000.0);
        else
            fprintf(stderr, "Time used = %.0lfms\n", t);
    }
} timeout;
#endif

using std::swap;
#if __cplusplus >= 201402L
template <typename T, typename P>
auto max(const T& x, const P& y) { return x < y ? y : x; }
template <typename T, typename P>
auto min(const T& x, const P& y) { return x < y ? x : y; }
template <typename T, typename... Args>
auto max(const T& x, const Args&... args) { return max(x, max(args...)); }
template <typename T, typename... Args>
auto min(const T& x, const Args&... args) { return min(x, min(args...)); }
#else
template <typename T, typename P>
auto max(const T& x, const P& y) -> decltype(x < y ? y : x) { return x < y ? y : x; }
template <typename T, typename P>
auto min(const T& x, const P& y) -> decltype(x < y ? x : y) { return x < y ? x : y; }
template <typename T, typename... Args>
auto max(const T& x, const Args&... args) -> decltype(max(x, max(args...))) { return max(x, max(args...)); }
template <typename T, typename... Args>
auto min(const T& x, const Args&... args) -> decltype(min(x, min(args...))) { return min(x, min(args...)); }
#endif
template <typename T>
T max(const T& x) { return x; }
template <typename T>
T min(const T& x) { return x; }

#define lc (o << 1)
#define rc (o << 1 | 1)
#define lowbit(x) ((x) & (-(x)))

class IO {
#define MY_DEBUG 0
#if !MY_DEBUG
    static const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
#endif
    long double eps = 1e-8L;
    LLL pow10 = 1000000;
    int precision;
    FILE *infile, *outfile;

public:
    IO(FILE* in = nullptr, FILE* out = nullptr) : precision(6), infile(in), outfile(out) {
#if !MY_DEBUG
        p1 = p2 = buf;
        pp = pbuf;
#endif
    }
#if !MY_DEBUG
    ~IO() { fwrite(pbuf, 1, pp - pbuf, outfile); }
#endif
    inline static bool blank(char ch);
    inline void flush();
    inline void input(const char* str);
    inline void output(const char* str);
    inline void input(FILE* f);
    inline void output(FILE* f);
    inline int getch();
    template <typename T, typename... Args>
    bool read(T& x, Args&... args);
    inline bool read();
    template <typename T>
    typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value || std::is_same<T, LLL>::value || std::is_same<T, ULLL>::value, bool>::type read(T& x);
    bool read(char& ch);
    bool read(char* s);
    bool readline(char* s);
    inline void putch(const char c);
    inline void putback(const char c);
    inline void setprecision(int n);
    template <typename T, typename... Args>
    void write(const T& x, const Args&... args);
    inline void write();
    template <typename T>
    typename std::enable_if<std::is_integral<T>::value || std::is_same<T, LLL>::value || std::is_same<T, ULLL>::value, void>::type write(T x);
    inline void write(char c);
    template <typename T>
    typename std::enable_if<std::is_floating_point<T>::value, void>::type write(T x);
    void write(bool x);
    void write(char* s);
    void write(const char* s);
    template <typename... Args>
    void writeln(Args... x) { write(x...), putch('\n'); }
} io(stdin, stdout), err(nullptr, stderr);
template <typename... Args>
inline void writeln(Args... x) { io.write(x...), io.putch('\n'); }
#define dbg(x) err.write(#x " = "), err.writeln(x)
// fast io
#include <cstring>
const int maxn = 200005;
const LL INF = -1ull / 2 - 2e9;

int A[maxn];
LL sum1[maxn], sum2[maxn];
LL d[maxn][2];
bool vis[maxn][2];
LL dp(int i, bool flag) {
    if (i <= 1)
        return -INF;
    if (vis[i][flag])
        return d[i][flag];
    vis[i][flag] = true;
    LL& ans = d[i][flag];
    if (i & 1) {
        if (i == 3 && flag)
            return ans = max(A[1], A[3]);
        if (flag) {
            return ans = max(dp(i - 2, 0), dp(i - 2, 1)) + A[i];
        }
        return ans = max(dp(i - 1, 1), dp(i - 1, 0));
    }
    if (i == 2)
        if (flag)
            return ans = A[2];
        else
            return ans = A[1];
    return ans = flag ? dp(i - 1, 0) + A[i] : sum1[i - 1];
}
int main() {
    int n;
    io.read(n);
    for (int i = 1; i <= n; i++)
        io.read(A[i]);
    for (int i = 1; i <= n; i++) {
        sum1[i] = sum1[i - 1];
        sum2[i] = sum2[i - 1];
        if (i & 1)
            sum1[i] += A[i];
        else
            sum2[i] += A[i];
    }
    writeln(max(dp(n, true), dp(n, false)));
    return 0;
}

#define isdigit(x) (x >= '0' && x <= '9')
inline bool IO::blank(char ch) { return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'; }
inline void IO::flush() {
#if MY_DEBUG
    fflush(outfile);
#else
    fwrite(pbuf, 1, pp - pbuf, outfile), pp = pbuf;
#endif
}
inline void IO::input(const char* str) {
    FILE* file = fopen(str, "rb");
    infile = file;
}
inline void IO::output(const char* str) {
    FILE* file = fopen(str, "wb");
    outfile = file;
}
inline void IO::input(FILE* f) { infile = f; }
inline void IO::output(FILE* f) { outfile = f; }
inline int IO::getch() {
#if MY_DEBUG
    return fgetc(infile);
#else
    return (p1 == p2 ? (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, infile)) : 0), (p1 == p2) ? EOF : *p1++;
#endif
}
inline void IO::putback(const char c) {
#if MY_DEBUG
    ungetc(c, infile);
#else
    *(--p1) = c;
#endif
}
template <typename T, typename... Args>
bool IO::read(T& x, Args&... args) { return read(x) && read(args...); }
inline bool IO::read() { return true; }
template <typename T>
typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value || std::is_same<T, LLL>::value || std::is_same<T, ULLL>::value, bool>::type IO::read(T& x) {
    double tmp = 1;
    bool sign = false;
    x = 0;
    int ch = getch();
    for (; !isdigit(ch) && ~ch; ch = getch())
        if (ch == '-')
            sign = true;
    if (!(~ch))
        return false;
    for (; isdigit(ch); ch = getch())
        x = x * 10 + (ch - '0');
    if (ch == '.')
        for (ch = getch(); isdigit(ch); ch = getch())
            tmp /= 10.0, x += tmp * (ch - '0');
    if (~ch)
        putback(ch);
    if (sign)
        x = ~x + 1;
    return true;
}
bool IO::read(char& ch) {
    for (ch = getch(); blank(ch) && ~ch; ch = getch())
        ;
    return ~ch;
}
bool IO::read(char* s) {
    int ch = getch();
    while (blank(ch))
        ch = getch();
    if (!(~ch))
        return false;
    while (!blank(ch) && ~ch)
        *s++ = ch, ch = getch();
    *s = 0;
    if (~ch)
        putback(ch);
    return true;
}
bool IO::readline(char* s) {
    int ch = getch();
    while (blank(ch) && ch != '\n')
        ch = getch();
    if (!(~ch))
        return false;
    while (ch != '\n' && ~ch)
        *s++ = ch, ch = getch();
    *s = 0;
    if (~ch)
        putback(ch);
    return true;
}
inline void IO::putch(const char c) {
#if MY_DEBUG
    fputc(c, outfile);
#else
    ((pp - pbuf == MAXSIZE) ? fwrite(pbuf, 1, MAXSIZE, outfile), pp = pbuf : 0), *pp++ = c;
#endif
}
inline void IO::setprecision(int n) {
    precision = n;
    eps = powl(10.0L, -precision - 2);
    pow10 = powl(10.0L, precision) + eps;
}
template <typename T, typename... Args>
void IO::write(const T& x, const Args&... args) {
    write(x);
    write(args...);
}
inline void IO::write() {}
template <typename T>
typename std::enable_if<std::is_integral<T>::value || std::is_same<T, LLL>::value || std::is_same<T, ULLL>::value, void>::type IO::write(T x) {
    if (x < 0)
        x = ~x + 1, putch('-');
    static T sta[100];
    int top = 0;
    do
        sta[top++] = x % 10, x /= 10;
    while (x);
    while (top)
        putch(sta[--top] + '0');
}
void IO::write(bool x) { putch(x ^ 48); }
inline void IO::write(char c) { putch(c); }
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value>::type IO::write(T x) {
    if (x == 0) {
        putch('0'), putch('.');
        for (int i = 1; i <= precision; i++)
            putch('0');
        return;
    }
    if (x < 0)
        putch('-'), x = -x;
    T res = (LLL)(x * pow10 + 0.5) / (pow10 * 1.0);
    LLL y = LLL(res * pow10 + eps) % pow10;
    write(LLL(res + eps));
    if (precision) {
        putch('.');
        static int sta[100], p = 0;
        for (; p < precision; y /= 10)
            sta[++p] = y % 10;
        for (int i = p; i >= 1; i--)
            putch(sta[i] ^ 48);
    }
}
void IO::write(char* s) {
    while (*s)
        putch(*s++);
}
void IO::write(const char* s) {
    while (*s)
        putch(*s++);
}
#undef isdigit