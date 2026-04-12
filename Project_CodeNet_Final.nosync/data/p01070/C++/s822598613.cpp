/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            pass System Test!
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  if (!v.empty()) {
    out << '[';
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &p) {
  out << "[" << p.first << ", " << p.second << "]";
  return out;
}
template <class T, class U>
void chmin(T &t, U f) {
  if (t > f) t = f;
}
template <class T, class U>
void chmax(T &t, U f) {
  if (t < f) t = f;
}

template <typename T>
class FenwickTree {
 public:
  int N;
  vector<T> dat;

 public:
  FenwickTree(int N) : N(N + 1) { dat.assign(N + 1, 0); }

  void add(int k, T val) {
    for (int x = k; x < N; x |= x + 1) {
      dat[x] += val;
    }
  }

  // [0, k)
  T sum(int k) {
    if (k >= N) k = N - 1;
    T ret = 0;
    for (int x = k - 1; x >= 0; x = (x & (x + 1)) - 1) {
      ret += dat[x];
    }
    return ret;
  }

  // [l, r)
  T sum(int l, int r) { return sum(r) - sum(l); }

  T get(int k) {
    assert(0 <= k && k < N);
    return sum(k + 1) - sum(k);
  }

  int lower_bound(int w) {
    if (w <= 0) return -1;
    int x = 0;
    int k = 1;
    while (k * 2 <= N) k *= 2;
    for (; k > 0; k /= 2) {
      if (x + k <= N && dat[x + k - 1] < w) {
        w -= dat[x + k - 1];
        x += k;
      }
    }
    return x;
  }
};

class SuffixArray {
 private:
  string s;
  SuffixArray() {}

 public:
  vector<int> sa;
  SuffixArray(string const &s) {
    this->s = s;
    sa.resize(s.size() + 1);
    build();
  }

  void build() {
    int n = s.length();
    vector<int> rank(n + 1);
    for (int i = 0; i < n + 1; ++i) {
      sa[i] = i;
      rank[i] = i < n ? s[i] : -1;
    }

    for (int k = 1; k <= n; k *= 2) {
      auto compare = [&](int i, int j) {
        int ri = i + k <= n ? rank[i + k] : -1;
        int rj = j + k <= n ? rank[j + k] : -1;
        return make_pair(rank[i], ri) < make_pair(rank[j], rj);
      };
      sort(sa.begin(), sa.end(), compare);
      vector<int> dp(n + 1);
      dp[sa[0]] = 0;
      for (int i = 0; i < n; ++i)
        dp[sa[i + 1]] = dp[sa[i]] + compare(sa[i], sa[i + 1]);
      rank = dp;
    }
    sa.erase(sa.begin());
  }

  int lower_bound(const string &t) {
    int a = -1, b = s.size() - 1;
    while (b - a > 1) {
      int c = (a + b) / 2;
      if (s.compare(sa[c], t.size(), t) < 0)
        a = c;
      else
        b = c;
    }
    return s.compare(sa[b], t.size(), t) == 0 ? b : -1;
  }

  int upper_bound(const string &t) {
    int a = -1, b = s.size();
    while (b - a > 1) {
      int c = (a + b) / 2;
      if (s.compare(sa[c], t.size(), t) <= 0)
        a = c;
      else
        b = c;
    }
    return b;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;
  int N = S.size();
  SuffixArray sa(S);
  int Q;
  cin >> Q;
  vector<pair<int, int>> query(Q);
  vector<tuple<int, int, int>> que;
  for (int q = 0; q < Q; ++q) {
    string M;
    int lq, rq;
    cin >> lq >> rq >> M;
    rq -= M.size() - 1;
    if (lq > rq) continue;
    int l = sa.lower_bound(M);
    int u = sa.upper_bound(M);
    if (l < 0) continue;
    query[q] = {l, u};
    que.push_back(make_tuple(lq, 0, q));
    que.push_back(make_tuple(rq, 2, q));
  }
  for (int i = 0; i < N; ++i) que.push_back(make_tuple(sa.sa[i], 1, i));
  sort(que.begin(), que.end());

  vector<int> ans(Q, 0);
  FenwickTree<int> bit(N);
  for (const auto &qt : que) {
    int i, t, q;
    tie(i, t, q) = qt;
    if (t == 1) {
      bit.add(q, 1);
    } else if (t == 0) {
      ans[q] -= bit.sum(query[q].first, query[q].second);
    } else {
      ans[q] += bit.sum(query[q].first, query[q].second);
    }
  }
  for (int i = 0; i < Q; ++i) {
    cout << ans[i] << endl;
  }
}