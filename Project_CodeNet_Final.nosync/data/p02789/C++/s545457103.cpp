#include <bits/stdc++.h>

#define ll long long
#define re register
#define il inline
#define gc getchar
#define pc putchar

template <class T>
void read(T &x) {
  re bool f = 0;
  re char c = gc();
  while ((c < '0' || c > '9') && c != '-') c = gc();
  if (c == '-') f = 1, c = gc();
  x = 0;
  while (c >= '0' && c <= '9') x = x * 10 + (c ^ 48), c = gc();
  f && (x = -x);
}

template <class T>
void print(T x) {
  if (x < 0) pc('-'), x = -x;
  if (x >= 10) print(x / 10);
  pc((x % 10) ^ 48);
}

#define priln(x) do{print(x);pc('\n');}while(0)
#define prisp(x) do{print(x);pc(' ');}while(0)



int main() {
  int n, m;
  read(n);
  read(m);
  if (n > m) puts("No");
  else puts("Yes");
}