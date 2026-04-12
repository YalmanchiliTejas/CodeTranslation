#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
#include<set>
#include<limits>
using namespace std;


const int mod = 1000000007;

struct Mod {
  int num;
  Mod() : num(0) { ; }
  Mod(long long int n) : num((n % mod + mod) % mod) { ; }
  Mod(int n) : num((n % mod + mod) % mod) { ; }
  operator int() { return num; }
};

Mod operator+(Mod a, Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(long long int a, Mod b) { return Mod(a)+b; }
Mod operator-(Mod a, Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(long long int a, Mod b) { return Mod(a) - b; }
Mod operator*(Mod a, Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(long long int a, Mod b) { return Mod(a)*b; }
Mod operator+=(Mod &a, Mod b) { return a = a + b; }
Mod operator+=(long long int &a, Mod b) { return a = a + b; }
Mod operator-=(Mod &a, Mod b) { return a = a - b; }
Mod operator-=(long long int &a, Mod b) { return a = a - b; }
Mod operator*=(Mod &a, Mod b) { return a = a * b; }
Mod operator*=(long long int &a, Mod b) { return a = a * b; }
Mod operator^(Mod a, int n) {
  if (n == 0) return Mod(1);
  Mod res = (a * a) ^ (n / 2);
  if (n % 2) res = res * a;
  return res;
}
Mod inv(Mod a) { return a ^ (mod - 2); }
Mod operator/(Mod a, Mod b) { 
assert(b!=0);
return a * inv(b);
 }
Mod operator/(long long int a, Mod b) {
  assert(b != 0);
  return Mod(a) * inv(b);
}

#define MAX_N 1024000

Mod fact[MAX_N], factinv[MAX_N];
void init() {
  fact[0] = Mod(1); factinv[0] = 1;
  for (int i = 0; i < MAX_N - 1; ++i) {
    fact[i + 1] = fact[i] * Mod(i + 1);
    factinv[i + 1] = factinv[i] / Mod(i + 1);
  }
}
Mod comb(int a, int b) {
  return fact[a] * factinv[b] * factinv[a - b];
}


vector<map<vector<int>, Mod>>dp;


vector<vector<Mod>> keisann(const vector<vector<Mod>>l, const vector<vector<Mod>>r) {
  vector<vector<Mod>>ans(l.size(), vector<Mod>(r[0].size()));
  assert(l[0].size() == r.size());
  for (int h = 0; h < l.size(); ++h) {
for (int i = 0; i < r.size(); ++i) {
    for (int w = 0; w < r[0].size(); ++w) {
      
        ans[h][w] += l[h][i] * r[i][w];
      }
    }
  }
  return ans;
}

vector<vector<Mod>>powgyou(vector<vector<Mod>>a, const long long int n) {
  if (n == 1)return a;
  else {
    vector<vector<Mod>>ans(a.size(), vector<Mod>(a[0].size(), 0));
    ans = powgyou(a, n / 2);
    ans = keisann(ans, ans);
    if (n % 2) {
      ans = keisann(ans, a);
    }
    return ans;
  }
}


  /*int N; cin >> N;
  vector<pair<int, int>>cs;
  for (int i = 0; i < N; ++i) {
    int x, r; cin >> x >> r;
    int l = x - r; int r = x + r;
    cs.emplace_back({ l,r });
  }
  sort(cs.begin(), cs.end(), [](const pair<int, int>l, const int pair<int, int>r) {
    return l.first == r.first ? l.second < r.second : l.first < r.first; }));
  return 0;*/

  /*int H, W; cin >> W >> H;
  dp.resize(H+1);
  vector<int>s(W,0);
  s[0] = Mod(1);
  dp[0][s] = Mod(1);
  for (int i = 1; i <= H; ++i) {
    for (auto it = dp[i - 1].begin(); it != dp[i - 1].end(); ++it) {
      vector<int>pre((*it).first);
      for (int j = 0; j < (1 <<( W)); ++j) {
        bitset<6>bs(j);
        vector<int>now(W);
        int num = 2;
        for (int k = 0; k < W; ++k) {
          if (bs[k]) {
            now[k] = num;
            num++;
          }
        }
        for (int k = 0; k < W; ++k) {
          if (now[k] && pre[k]) {
            now[k] = pre[k];
          }
        }
        for (int k = 0; k < W - 1; ++k) {
          if (now[k] && now[k + 1]) {
            int amin = min(now[k], now[k + 1]);
            now[k] = amin;
            now[k + 1] = amin;
          }
        }
        for (int k = W - 1; k > 0; --k) {
          if (now[k] && now[k - 1]) {
            int amin = min(now[k], now[k - 1]);
            now[k] = amin;
            now[k - 1] = amin;
          }
        }
        int nnum = 2;
        for (int k = 0; k < W; ++k) {
          if (now[k]>=2) {
            int aa = now[k];
            for (int l = 0; l < W; ++l) {
              if (now[l] == aa)now[l] = nnum;
            }
            nnum++;
          }
        }
        bool isok = false;
        for (int k = 0; k < W; ++k) {
          if (now[k] == 1) {
            isok = true;
          }
        }
        if (isok) {

          dp[i][now] += (*it).second;
        }

      }
    }
  }
  Mod ans(0);
  for (auto it = dp[H].begin(); it != dp[H].end(); ++it) {
    if ((*it).first[W - 1] == 1) {
      ans += (*it).second;
    }
  }
  cout << ans << endl;
  return 0;*/


int main(void) {
  /*int N; cin >> N;
  vector<pair<int, int>>cs;
  for (int i = 0; i < N; ++i) {
    int x, r; cin >> x >> r;
    int l = x - r; int r = x + r;
    cs.emplace_back({ l,r });
  }
  sort(cs.begin(), cs.end(), [](const pair<int, int>l, const int pair<int, int>r) {
    return l.first == r.first ? l.second < r.second : l.first < r.first; }));
  return 0;*/

  /*int H, W; cin >> W >> H;
  dp.resize(H+1);
  vector<int>s(W,0);
  s[0] = Mod(1);
  dp[0][s] = Mod(1);
  for (int i = 1; i <= H; ++i) {
    for (auto it = dp[i - 1].begin(); it != dp[i - 1].end(); ++it) {
      vector<int>pre((*it).first);
      for (int j = 0; j < (1 <<( W)); ++j) {
        bitset<6>bs(j);
        vector<int>now(W);
        int num = 2;
        for (int k = 0; k < W; ++k) {
          if (bs[k]) {
            now[k] = num;
            num++;
          }
        }
        for (int k = 0; k < W; ++k) {
          if (now[k] && pre[k]) {
            now[k] = pre[k];
          }
        }
        for (int k = 0; k < W - 1; ++k) {
          if (now[k] && now[k + 1]) {
            int amin = min(now[k], now[k + 1]);
            now[k] = amin;
            now[k + 1] = amin;
          }
        }
        for (int k = W - 1; k > 0; --k) {
          if (now[k] && now[k - 1]) {
            int amin = min(now[k], now[k - 1]);
            now[k] = amin;
            now[k - 1] = amin;
          }
        }
        int nnum = 2;
        for (int k = 0; k < W; ++k) {
          if (now[k]>=2) {
            int aa = now[k];
            for (int l = 0; l < W; ++l) {
              if (now[l] == aa)now[l] = nnum;
            }
            nnum++;
          }
        }
        bool isok = false;
        for (int k = 0; k < W; ++k) {
          if (now[k] == 1) {
            isok = true;
          }
        }
        if (isok) {

          dp[i][now] += (*it).second;
        }

      }
    }
  }
  Mod ans(0);
  for (auto it = dp[H].begin(); it != dp[H].end(); ++it) {
    if ((*it).first[W - 1] == 1) {
      ans += (*it).second;
    }
  }
  cout << ans << endl;
  return 0;*/

  /*int k = 0;
  while (1) {

    k++;
    int a; cin >> a;
    if (a) {
      cout << "Case " << k << ": " << a << endl;
    }
    else {
      return 0;
    }
  }
  return 0;*/

  while (1) {
    int n; cin >> n;
    if (!n)return 0;
    vector<int>b;
    for (int i = 0; i < n; ++i) {
      int a; cin >> a;
      b.push_back(a);
    }
    sort(b.begin(), b.end());
    int ans = accumulate(b.begin() + 1, b.end() - 1, 0);
    ans /= b.size() - 2;
    cout << ans << endl;
  }




  return 0;
}