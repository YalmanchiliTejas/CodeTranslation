#include <bits/stdc++.h>
using namespace std;
template<typename T1, typename T2>
inline bool chmax (T1& a, T2 b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template<typename T>
class calculate_heights {
  const int n;
  const vector<vector<pair<T, int>>>& grh;
  vector<T> dp, ep;

  void dfs (
      int crr = 0,
      int prt = 0
    ) {
      for (auto const& e : grh[crr]) {
        T w; int nxt; tie(w, nxt) = e;
        if (nxt == prt) continue;
        dfs(nxt, crr);
        chmax(dp[crr], dp[nxt] + w);
      }
    }

  void efs (
      int crr = 0,
      int prt = 0
    ) {
      vector<T> cld = {ep[crr]};
      for (auto const& e : grh[crr]) {
        T w; int nxt; tie(w, nxt) = e;
        if (nxt == prt) continue;
        cld.push_back(dp[nxt] + w);
      }
      sort(cld.begin(), cld.end(), greater<T>());
      for (auto const& e : grh[crr]) {
        T w; int nxt; tie(w, nxt) = e;
        if (nxt == prt) continue;
        ep[nxt] = dp[nxt] + w == cld[0] ?
            cld[1] + w : cld[0] + w;
      }
      for (auto const& e : grh[crr]) {
        T w; int nxt; tie(w, nxt) = e;
        if (nxt == prt) continue;
        efs(nxt, crr);
      }
      chmax(dp[crr], ep[crr]);
    }

  public:
    calculate_heights(
        vector<vector<pair<T, int>>>& grh
      ) :
      n(grh.size()),
      grh(grh),
      dp(n, 0),
      ep(n, 0)
      {
        dfs();
        efs();
      }
    
    auto operator[] (int i) const -> const T {return dp[i];}
};
int main() {
  int n;
  cin >> n;
  vector<vector<pair<long long, int>>> grh(n);
  for (int i = 0; i < n - 1; i++) {
    int s, t; long long d;
    cin >> s >> t >> d;
    grh[s].emplace_back(d, t);
    grh[t].emplace_back(d, s);
  }
  calculate_heights<long long> hgt(grh);
  for (int i = 0; i < n; i++) {
    cout << hgt[i] << endl;
  }
  return 0;
}
