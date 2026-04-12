#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 1e9
#define LINF 1e18
#define MOD 1000000007
#define PI 3.14159265359
#define EPS 1e-10
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

/**
 * Usage:
 * 
 * G[from].push_back(Edge(to, weight));
 * using Graph = vector<vector<Edge>>;
 * 
 */ 
struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};

/**
 * Usage:
 * 
 * chmin(old, new);
 * chmax(old, new);
 * 
 */ 
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T>
void printv(vector<T>& v) {
  if (v.size() == 0) {
    cout << "\n";
    return;
  }

  Rep(i, v.size()) {
    cout << v[i] << ((i + 1 < v.size()) ? ' ' : '\n');
  }
}




 template< typename T >
 vector< vector< T > > binomial_table(int N) {
   vector< vector< T > > mat(N + 1, vector< T >(N + 1));
   for(int i = 0; i <= N; i++) {
     for(int j = 0; j <= i; j++) {
       if(j == 0 || j == i) mat[i][j] = 1;
       else mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
     }
   }
   return mat;
 }

string ns;
int K;

bool isbigger(string a, string b) {
  int a_len = a.size();
  int b_len = b.size();

  if (a_len > b_len) return true;
  else if (a_len < b_len) return false;
  else {
    Rep(i, a_len) {
      if (a[i] > b[i]) return true;
      else if (a[i] < b[i]) return false;
    }
    return false;
  }
}

int main () {
  cin >> ns;
  cin >> K;

  int n = ns.size();

  vector<vector<ll>> com;
  com = binomial_table<ll>(110);

  ll ans = 0;

  for (int i=0;i<n;++i) {
    ll tmp = 0;
    if (i >= K) {
      tmp = com[i-1][K-1];
      if (K == 3) tmp *= (9 * 9 * 9);
      else if (K == 2) tmp *= (9 * 9);
      else tmp *= 9;
    }

    ans += tmp;
  }
  
  vector<string> kouho;

  string moto = "";
  Rep(i, n) {
    moto += "0";
  }

  if (K == 1) {
    rep(ii, 9) {
      string tmp = moto;
      tmp[0] = '0' + ii;
      kouho.push_back(tmp);
    }
  } else if (K == 2) {
    for (int p=1;p<n;++p) {
      rep(ii, 9) {
        rep(jj, 9) {
          string tmp = moto;
          tmp[0] = '0' + ii;
          tmp[p] = '0' + jj;
          kouho.push_back(tmp);
        }
      }
    }
  } else {
    for (int p=1;p<n;++p) {
      for (int q=p+1;q<n;++q) {
        rep(ii, 9) {
          rep(jj, 9) {
            rep(kk, 9) {
              string tmp = moto;
              tmp[0] = '0' + ii;
              tmp[p] = '0' + jj;
              tmp[q] = '0' + kk;
              kouho.push_back(tmp);
            }
          }
        }
      }
    }
  }

  for (auto kou: kouho) {
    if (!isbigger(kou, ns)) {
      //cout << kou << "\n";
      ans++;
    }
  }

  //printv(kouho);
  cout << ans << "\n";
}