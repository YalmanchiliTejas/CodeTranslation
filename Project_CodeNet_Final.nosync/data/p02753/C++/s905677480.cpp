#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <vector>

#ifdef GONGKUNPENG
#include <cassert>

#define _GG 1
#else
#define _GG 0
#endif

#define uint unsigned
#define vector std::vector
#define max(a, b) std::max(a, b)
#define min(a, b) std::min(a, b)
#define swap(a, b) std::swap(a, b)
#define sort(...) std::sort(__VA_ARGS__)
#define ms(a, v) memset(a, v, sizeof(a))
#define sfor(i, n) for (int i = 1; i <= n; ++i)
#define tfor(i, n) for (int i = 0; i < n; ++i)

#if __cplusplus >= 201103L
using ll = long long;
using ull = unsigned long long;
#else
typedef long long ll;
typedef unsigned long long ull;
#endif

#define _GIO 1

#if _GIO
struct _gio {
#define BFSZ 1 << 18
#define blank(x) (x == ' ' || x == '\t' || x == '\n' || x == '\r')

  char rcha;
  bool rneg;
#if _GG
#else
  char ruf[BFSZ], wuf[BFSZ], *r1, *r2, *w1;
#endif

  _gio() {
    rcha = ' ';
#if _GG
#else
    r1 = r2 = ruf, w1 = wuf;
#endif
  }

  ~_gio() {
#if _GG
#else
    fwrite(wuf, 1, w1 - wuf, stdout);
#endif
  }

  inline void flush() {
#ifdef _GG
#else
    fwrite(wuf, 1, w1 - wuf, stdout), w1 = wuf;
#endif
  }

  inline int readc() {
#if _GG
    return getchar();
#else
    return (r1 == r2 && (r2 = (r1 = ruf) + fread(ruf, 1, BFSZ, stdin), r1 == r2)
                ? -1
                : *r1++);
#endif
  }

  template <typename T, typename... Args>
  void read(T &x, Args &... args) {
    read(x), read(args...);
  }

  inline void read() {}

  inline void read(char *s) {
    while (blank(rcha)) rcha = readc();
    while (!blank(rcha) && rcha > 0) *s++ = rcha, rcha = readc();
    *s = '\0';
  }

  inline void readl(char *s) {
    while (blank(rcha)) rcha = readc();
    while (rcha != '\n' && rcha > 0) *s++ = rcha, rcha = readc();
    *s = '\0';
  }

  template <typename T>
  inline void read(T &x) {
    x = rcha = rneg = 0;
    while (!isdigit(rcha) && rcha != '-') rcha = readc();
    rcha == '-' && (rneg = true, rcha = readc());
    while (isdigit(rcha)) x = (x << 3) + (x << 1) - 48 + rcha, rcha = readc();
    rneg && (x = -x);
  }

  inline void writec(const char &c) {
#if _GG
    putchar(c);
#else
    (w1 - wuf == BFSZ) && (fwrite(wuf, 1, BFSZ, stdout), w1 = wuf);
    *w1++ = c;
#endif
  }

  template <typename T, typename... Args>
  void write(const T &x, const Args &... args) {
    write(x), write(args...);
  }

  template <typename T, typename... Args>
  void writel(const T &x, const Args &... args) {
    write(x), write(args...);
    writec('\n');
  }

  inline void write() {}

  inline void write(const char &c) { writec(c); }

  template <typename T>
  void write(T x) {
    if (x < 0) {
      writec('-');
      write(-ll(x));
      return;
    }
    if (x > 9) write(x / 10);
    writec(x % 10 ^ 48);
  }

  inline void write(const char *s) {
    while (*s) writec(*s++);
  }
#undef BFSZ
} io;
#endif

const ll INF = 0x3f3f3f3f;
const uint MAXN =
#ifdef GONGKUNPENG
    15
#else
    1000005
#endif
    ;

int main() {
  char inp[5];
  int st = 0;
  io.read(inp);
  for (int i = 0; i < 3; ++i)
    if (inp[i] == 'A')
      st |= 1;
    else
      st |= 2;
  io.write(st == 3 ? "Yes\n" : "No\n");
  return 0;
}