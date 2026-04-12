#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
#ifdef AIM
#include <sys/resource.h>
#endif
using namespace std;

#define all(a) a.begin(), a.end()
using li = long long;
using ld = long double;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
  //freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
//freopen("out.txt", "w", stdout);
#else
  //freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif

#ifdef AIM
  const rlim_t kStackSize = 256 * 1024 * 1024;
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0) {
    if (rl.rlim_cur < kStackSize) {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0) {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }
#endif

  start = clock();
  int t = 1;
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif
  cout.precision(20);
  cout << fixed;
  //cin >> t;
  precalc();
  while (t--) {
    solve(true);
  }
  cout.flush();

#ifdef AIM1
  while (true) {
    solve(false);
  }
#endif

#ifdef AIM
  cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif
  return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
  if (!w)
    return 1 % mod;
  if (w & 1)
    return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template<typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}

template <typename T>
void make_unique(vector<T>& vec) {
  sort(all(vec));
  vec.erase(unique(all(vec)), vec.end());
}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

mt19937 rng((unsigned long long)chrono::steady_clock::now().time_since_epoch().count());

void precalc() {

}

#define int li
const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

void add(int& cur, int val) {
  cur += val;
  cur %= mod;
  if (cur < 0) {
    cur += mod;
  }
}

int get_stupid(int n, int m, string s) {
  int ans = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
      dp[i] = (1 << i);
    }
    bool f = true;
    for (char c : s) {
      bool need = (c == 'R');
      vector<int> new_dp(n, 0);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (dp[i] & (1 << j)) {
            if ((bool)(mask & (1 << j)) == need) {
              new_dp[i] |= (1 << ((j + 1) % n));
            }
            int prev = ((j - 1 + n) % n);
            if ((bool)(mask & (1 << prev)) == need) {
              new_dp[i] |= (1 << prev);
            }
          }
        }
        if (new_dp[i] == 0) {
          f = false;
          break;
        }
      }
      if (!f) {
        break;
      }
      new_dp.swap(dp);
    }
    if (f) {
      ++ans;
    }
  }
  return ans;
}

void solve(__attribute__((unused)) bool read) {
  int n, m;
  string s;
  if (read) {
    cin >> n >> m;
    cin >> s;
  } else {
    n = rand() % 10 + 2;
    m = rand() % 10 + 1;
    for (int i = 0; i < m; ++i) {
      s += "RB"[rand() & 1];
    }
  }

  //int stupid_res = get_stupid(n, m, s);

  if (s[0] == 'B') {
    for (char& c : s) {
      c = 'B' + 'R' - c;
    }
  }
  const int INF = (int)1e9;
  int max_segment = INF;
  int last = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'B') {
      int cur_len = i - last;
      if (last == 0) {
        if (cur_len % 2 == 0) {
          ++cur_len;
        }
        relax_min(max_segment, cur_len);
      } else if (cur_len % 2) {
        relax_min(max_segment, cur_len);
      }
      last = i + 1;
    }
  }
  int res = 0;
  if (last == 0) {
    vector<int> fib(n + 1);
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < fib.size(); ++i) {
      fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    }
    if (n == 2) {
      res = 3;
    } else {
      add(res, fib[n - 1]);
      if (n > 2) {
        add(res, fib[n - 3]);
      }
    }
  } else {
    int max_divided = (max_segment + 1) / 2;
    //cout << max_segment << " " << max_divided << endl;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    vector<int> add_to_pref(n + 1, 0);
    int pref_add = 0;
    for (int i = 0; i <= n; ++i) {
      add(pref_add, add_to_pref[i]);
      add(dp[i], pref_add);
      add(pref_add, dp[i]);
      if (i + max_divided < n) {
        add(add_to_pref[i + max_divided + 1], -dp[i]);
      }
      /*if (i < n / 2) {
        cout << i << " " << dp[i] << endl;
      }*/
    }
    if (n % 2 == 0) {
      for (int seg = 2; seg <= 2 * max_divided && seg <= n; seg += 2) {
        //cout << "add seg: " << seg << " rest: " << (n - seg) / 2 << " dp: " << dp[(n - seg) / 2] << endl;
        res += dp[(n - seg) / 2] * seg;
        res %= mod;
      }
    }
  }

  /*if (res != stupid_res) {
    cout << "FOUND res: " << res << " stupid: " << stupid_res << endl;
    cout << n << " " << m << "\n" << s << endl;
    exit(0);
  } else {
    cout << "ok res: " << res << endl;
    return;
  }*/

  cout << res << "\n";

}