#include <chrono>
#include <cmath>
#include <cstdio>

using LL = long long;
#ifdef __linux__
using LLL = __int128;
#else
using LLL = long long;
#endif

#ifdef LX_LOCAL
class TimeOut {
public:
    std::chrono::_V2::steady_clock::rep begin;
    long duration;
    TimeOut()
    {
        begin = std::chrono::steady_clock::now().time_since_epoch().count();
        duration = 0;
    }
    ~TimeOut()
    {
        auto end = std::chrono::steady_clock::now().time_since_epoch().count();
        auto d = end - begin;
        duration += d;
        double t = duration / 1000.0 / 1000.0;
        if (t >= 60000)
            fprintf(stderr, "Time used = %.2lfmin\n", t / 60000.0);
        else if (t >= 1000)
            fprintf(stderr, "Time used = %.2lfs\n", t / 1000.0);
        else
            fprintf(stderr, "Time used = %.0lfms\n", t);
    }
} timeout;
#endif
class IO {
#define MY_DEBUG 0
#if !MY_DEBUG
    static const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
#endif
    int precision;
    FILE *infile, *outfile;

public:
    IO() : p1(buf), p2(buf), pp(pbuf), precision(6), infile(stdin), outfile(stdout)
    {
#if !MY_DEBUG
        p1 = p2 = buf;
        pp = pbuf;
#endif
        precision = 6;
        infile = stdin;
        outfile = stdout;
    }
    ~IO()
    {
#if !MY_DEBUG
        fwrite(pbuf, 1, pp - pbuf, outfile);
#endif
        fclose(infile);
        fclose(outfile);
    }
    inline bool blank(char ch) const;
    void flush();
    void input_from_file(const char* str);
    void output_from_file(const char* str);
    inline int getch();
    template <typename T, typename... Args>
    void read(T& x, Args&... args);
    void read();
    template <typename T>
    void read(T& x);
    void read(char& ch);
    void read(char* s);
    void readline(char* s);
    void putch(const char c);
    void setprecision(int n);
    template <typename T, typename... Args>
    void write(const T& x, const Args&... args);
    void write();
    template <typename T>
    void write(T x);
    void write(char c);
    void write(double x);
    void write(char* s);
    void write(const char* s);
} io;
#define writeln(...) io.write(__VA_ARGS__), io.putch('\n')
#define dbg(x) io.write(#x " = "), writeln(x)
// define fast io
const int maxn = 3005, MOD = 998244353;

int A[maxn], dp[maxn];
int main()
{
    int n, m;
    io.read(n, m);
    for (int i = 1; i <= n; i++)
        io.read(A[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j > A[i]; j--)
            dp[j] = (dp[j] + dp[j - A[i]]) % MOD;
        dp[A[i]] = (dp[A[i]] + i) % MOD;
        ans = (ans + 1LL * dp[m] * (n - i + 1) % MOD) % MOD;
        dp[m] = 0;
    }
    writeln(ans);
    return 0;
}

#define isdigit(x) (x >= '0' && x <= '9')
inline bool IO::blank(char ch) const
{
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
void IO::flush()
{
    fwrite(pbuf, 1, pp - pbuf, outfile), pp = pbuf;
}
void IO::input_from_file(const char* str)
{
    FILE* file = fopen(str, "rb");
    infile = file;
}
void IO::output_from_file(const char* str)
{
    FILE* file = fopen(str, "wb");
    outfile = file;
}
inline int IO::getch()
{
#if MY_DEBUG
    return fgetc(infile);
#endif
    if (p1 == p2)
#ifdef LX_LOCAL
    {
        auto end = std::chrono::steady_clock::now().time_since_epoch().count();
        auto t = end - timeout.begin;
        timeout.duration += t;
#endif
        p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, infile);
#ifdef LX_LOCAL
        timeout.begin = std::chrono::steady_clock::now().time_since_epoch().count();
    }
#endif
    return p1 == p2 ? -1 : *p1++;
}
template <typename T, typename... Args>
void IO::read(T& x, Args&... args)
{
    read(x);
    read(args...);
}
void IO::read() {}
template <typename T>
void IO::read(T& x)
{
    double tmp = 1;
    bool sign = 0;
    x = 0;
    int ch = getch();
    for (; !isdigit(ch) && ~ch; ch = getch())
        if (ch == '-')
            sign = 1;
    for (; isdigit(ch); ch = getch())
        x = x * 10 + (ch - '0');
    if (ch == '.')
        for (ch = getch(); isdigit(ch); ch = getch())
            tmp /= 10.0, x += tmp * (ch - '0');
    if (sign)
        x = -x;
}
void IO::read(char& ch)
{
    for (ch = getch(); blank(ch) && ~ch; ch = getch())
        ;
}
void IO::read(char* s)
{
    int ch = getch();
    while (blank(ch))
        ch = getch();
    while (!blank(ch) && ~ch)
        *s++ = ch, ch = getch();
    *s = 0;
}
void IO::readline(char* s)
{
    int ch = getch();
    while (blank(ch) && ch != '\n')
        ch = getch();
    while (ch != '\n' && ~ch)
        *s++ = ch, ch = getch();
    *s = 0;
}
void IO::putch(const char c)
{
#if MY_DEBUG
    fputc(c, outfile);
#else
    if (pp - pbuf == MAXSIZE)
        fwrite(pbuf, 1, MAXSIZE, outfile), pp = pbuf;
    *pp++ = c;
#endif
}
void IO::setprecision(int n)
{
    precision = n;
}
template <typename T, typename... Args>
void IO::write(const T& x, const Args&... args)
{
    write(x);
    write(args...);
}
void IO::write() {}
template <typename T>
void IO::write(T x)
{
    if (x < 0)
        x = -x, putch('-');
    static T sta[100];
    int top = 0;
    do
        sta[top++] = x % 10, x /= 10;
    while (x);
    while (top)
        putch(sta[--top] + '0');
}
void IO::write(char c) { putch(c); }
void IO::write(double x)
{
    const double eps = pow(10, -precision - 2);
    if (x == 0) {
        putch('0'), putch('.');
        for (int i = 1; i <= precision; ++i)
            putch('0');
        return;
    }
    if (x < 0)
        putch('-'), x = -x;
    LLL n = pow(10, precision);
    double res = (LLL)(x * n + 0.5) / (n * 1.0);
    LLL y = LLL(res * n + eps) % n;
    if (precision) {
        write(LLL(res + eps), '.');
        int sta[20], p = 0;
        for (; p < precision; y /= 10)
            sta[++p] = y % 10;
        for (int i = p; i >= 1; i--)
            putch(sta[i] ^ 48);
    } else
        write(LLL(res + eps));
}
void IO::write(char* s)
{
    while (*s)
        putch(*s++);
}
void IO::write(const char* s)
{
    while (*s)
        putch(*s++);
}
#undef isdigit