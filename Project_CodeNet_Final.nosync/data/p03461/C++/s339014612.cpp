#ifndef LOCAL
#pragma GCC optimize("Ofast")
#endif

#include "bits/stdc++.h"

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;
using ld = long double;

constexpr int nax = 300;
constexpr int infty = 1000 * 1000 * 1000 + 5;
constexpr int mod = 1000 * 1000 * 1000 + 7;

constexpr int MaxWsp = 145;

int n, s, t, A, B;
int D[11][11];
int gdziex[MaxWsp + 1];
int gdziey[MaxWsp + 1];
void DajKrawedz(int a, int b, int d);

void Algos() {
  for (int x = 1; x <= A; x++) {
    for (int y = 1; y <= B; y++) {
      for (int a = 0; a <= MaxWsp; a++) {
        for (int b = 0; b <= MaxWsp; b++) {
          const int c = D[x][y] - a * x - b * y;
          if (!(0 <= c and c <= 100)) {
            goto out;
          }
          for (int x2 = 1; x2 <= A; x2++) {
            for (int y2 = 1; y2 <= B; y2++) {
              if (a * x2 + b * y2 + c < D[x2][y2]) {
                goto out;
              }
            }
          }
          debug() << imie(x) imie(y) imie(a) imie(b) imie(c) imie(gdziex[a]) imie(gdziey[b]);
          DajKrawedz(gdziex[a], gdziey[b], c);
          goto mam_juz;
          out:;
        }
      }
      mam_juz:;
    }
  }
}

map<int, string> graf[nax];

ll mac[nax][nax];
ll odl[nax];
bool nakol[nax];

int Odl() {
  for (int i = 0; i < n; i++) {
    odl[i] = numeric_limits<ll>::max();
    nakol[i] = false;
  }
  odl[s] = 0;
  queue<int> kol;
  kol.push(s);
  while (!kol.empty()) {
    const int w = kol.front();
    kol.pop();
    nakol[w] = false;
    for (int i = 0; i < n; i++) {
      if (mac[w][i] == numeric_limits<ll>::max()) continue;
      const ll o = odl[w] + mac[w][i];
      if (o < odl[i]) {
        odl[i] = o;
        if (!nakol[i]) {
          nakol[i] = true;
          kol.push(i);
        }
      }
    }
  }
  return odl[t];
}

bool Check() {
  for (int i = 1; i <= A; i++) {
    for (int j = 1; j <= B; j++) {
      for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
          mac[k][l] = numeric_limits<ll>::max();
        }
      }
      for (int k = 0; k < n; k++) {
        for (auto& it : graf[k]) {
          if (it.second == "X") mac[k][it.first] = i;
          else if (it.second == "Y") mac[k][it.first] = j;
          else {
            stringstream str(it.second);
            int d;
            str >> d;
            mac[k][it.first] = d;
          }
        }
      }
      const ll o = Odl();
      if (o != D[i][j]) {
        debug() << imie(i) imie(j) imie(D[i][j]) imie(o);
        return false;
      }
    }
  }
  return true;
}

void DajKrawedz(int a, int b, int d) {
  assert(0 <= a and a < n);
  assert(0 <= b and b < n);
  assert(a != b);
  graf[a][b] = to_string(d);
}

int DajId() {
  assert(n < nax);
  return n++;
}

int main() {
  scanf("%d%d", &A, &B);
  for (int i = 1; i <= A; i++) {
    for (int j = 1; j <= B; j++) {
      scanf("%d", &D[i][j]);
    }
  }

  s = DajId();
  t = DajId();
  /*
  for (int y = 0; y <= MaxWsp; y++) {
    int last = t;
    for (int j = 0; j < y; j++) {
      const int nowy = DajId();
      graf[nowy][last] = "Y";
      last = nowy;
    }
    for (int x = 0; true; x++) {
      gdziex[x][y] = last;
      if (x == MaxWsp) break;
      const int nowy = DajId();
      graf[nowy][last] = "X";
      last = nowy;
    }
  }
  */

  int last = s;
  for (int x = 0; x <= MaxWsp; x++) {
    gdziex[x] = last;
    if (x == MaxWsp) break;
    const int nowy = DajId();
    graf[last][nowy] = "X";
    last = nowy;
  }
  last = t;
  for (int y = 0; y <= MaxWsp; y++) {
    gdziey[y] = last;
    if (y == MaxWsp) break;
    const int nowy = DajId();
    graf[nowy][last] = "Y";
    last = nowy;
  }
  debug() << imie(range(gdziex, gdziex + MaxWsp + 1));
  debug() << imie(range(gdziey, gdziey + MaxWsp + 1));

  Algos();
  if (!Check()) {
    printf("Impossible\n");
    return 0;
  }
  int m = 0;
  for (int i = 0; i < n; i++) {
    m += (int) graf[i].size();
  }
  printf("Possible\n");
  printf("%d %d\n", n, m);
  for (int i = 0; i < n; i++) {
    for (auto& it : graf[i]) {
      printf("%d %d %s\n", i + 1, it.first + 1, it.second.c_str());
    }
  }
  printf("%d %d\n", s + 1, t + 1);
  return 0;
}
