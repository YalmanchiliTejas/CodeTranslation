#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
#include <regex>
#include <climits>

#define FOR(i, f, n) for(int (i) = (f), TMPend = (n); (i) < TMPend; (i)++)
#define RFOR(i, f, n) for(int (i) = (f), TMPend = (n); (i) >= TMPend; (i)--)
#define REP(i, n) for(int (i) = 0, TMPend = (n); (i) < TMPend; (i)++)
#define RREP(i, n) for(int (i) = (n); (i) >= 0; (i)--)
#define rep(i, n) for(int (i) = 0, TMPend = (n); (i) < TMPend; (i)++)
#define rrep(i, n) for(int (i) = (n); (i) >= 0; (i)--)
#define forin(i, a) for(auto i: (a))
#define p(...) printf(__VA_ARGS__); cout << endl;
#define in(...) __VA_ARGS__; input__(__VA_ARGS__);
#define input(...) in(__VA_ARGS__)
#define out(...) output__(__VA_ARGS__);
#define output(...) out(__VA_ARGS__)
#define list_input(x, n) x[(n)]; for(int (i) = 0; (i) < (n); (i)++) cin >> x[i];
#define lambda(a, b, c) [](auto const &a, auto const &b){ return c ;}
#define key(t, x, compare) [](const t &a, const t &b){ return a x compare b x ;}
#define unless(a) if(!(a))

using namespace std;

using pii = pair<int, int>;

template <class... T>
void input__(T &...a) {
  for(auto v: {&a...}) {
    cin >> *v;
  }
}

void output__(){
  cout << endl;
}

template <class Head, class... T>
void output__(Head const &v, T const &...a) {
  if(sizeof...(a) == 0) {
    cout << v;
  } else {
    cout << v << " ";
  }
  output__(a...);
}

class SegTree {
  public:
    int t = 1;
    vector<long long> seg;
    vector<long long> lazy;
    SegTree(int n) {
      while (t < n) {
        t *= 2;
      }

      seg = vector<long long>(t * 2 - 1, 0);
      lazy = vector<long long>(t * 2 - 1, 0);
    }

    int up(int node) {
      return (node - 1) / 2;
    }

    int down(int node) {
      return node * 2 + 1;
    }

    long long lazy_eval(int node) {
      if (lazy[node] != 0) {
        long long value = lazy[node];
        lazy[node] = 0;
        seg[node] += value;

        if (node < t - 1) {
          int child = down(node);
          lazy[child] += value;
          lazy[child + 1] += value;
        }
      }

      return seg[node];
    }

    void add(long long x, int l, int r, int node=0, int sl=0, int sr=-1) {
      if (sr == -1) sr = t;

      if (sr <= l || r <= sl) {
        return;
      }

      if (l <= sl && sr <= r) {
        lazy[node] += x;
        return;
      }

      int sc = (sl + sr) / 2;
      int child = down(node);
      add(x, l, r, child, sl, sc);
      add(x, l, r, child + 1, sc, sr);

      seg[node] = max(lazy_eval(child), lazy_eval(child + 1));
    }
};

class Q {
  public:
    int l, r, a;
    pair<int, int> lr;

    Q(int l, int r, int a): l(l), r(r), a(a) {
      lr = make_pair(l, r);
    }
};

int main(){
  int input(n, m);

  vector<Q> q;
  rep(i, m) {
    int input(l, r, a);
    q.push_back({l, r, a});
  }

  sort(q.begin(), q.end(), key(Q, .lr, <));
  vector<int> left;

  forin(v, q) {
    left.push_back(v.l);
  }

  SegTree seg(n + 1);

  long long p = 0;
  vector<long long> score_table(n + 1, 0);
  left.push_back(10000000);
  RFOR(i, n - 1, -1) {
    int left_start_index = distance(left.begin(), lower_bound(left.begin(), left.end(), i + 1));
    int left_start_end = distance(left.begin(), upper_bound(left.begin(), left.end(), i + 1));
    FOR(j, left_start_index, left_start_end) {
      seg.add(q[j].a, i + 1, q[j].r + 1);
    }

    seg.add(p, i + 1, i + 2);
    p = seg.lazy_eval(0);
  }
  out(p);
}
