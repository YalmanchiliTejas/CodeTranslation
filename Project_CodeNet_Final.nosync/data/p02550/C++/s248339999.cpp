#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using ll = long long;
using P = pair<long long, long long>;
using MATRIX = vector< vector<ll> >;
template <class T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <class T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}

long long nxt[40][100001];
vector<long long> chd[100000];
long long depth[100000] = {0};
long long NUM;
long long Q;
long long sum[40][100000] = {0};


//各要素について深さを計算
void dfs(long long key, long long dep) {
  // if(chd[key].size() == 0) {
  //   depth[key] = dep;
  // }
  rep(i, chd[key].size()) {
    long long ni = chd[key][i];
    depth[ni] = dep + 1;
    dfs(ni, dep+1);
  }
  return;
}

//key分先の親を計算
long long calcPar(long long a, long long key) {
  long long temp = a;
  long long res = 0;
  for(long long i = NUM; i >= 0; i--) {
    if((key >> i) & 1) {
      res += sum[i][temp];
      temp = nxt[i][temp];
    }
  }
  return res;
}

bool isOk(long long a, long long b, long long key) {
  if(a == b) return true;
  if(calcPar(a, key) == calcPar(b, key)) {
    return true;
  }
  return false;
}

long long lower_search(long long a, long long b) {
  long long l = -1, r = depth[a];
  while(r - l > 1) {
    long long half = (r + l) / 2;
    if(isOk(a, b, half)) r = half;
    else l = half;
  }
  return r;
}

int main() {
  long long N, X, M;
  cin >> N >> X >> M;
  NUM = floor(log2(N));
  rep(i, M) {
    nxt[0][i] = (i * i) % M;
  }
  //ダブリングの表を作成
  rep(i, NUM) {
    rep(j, M) {
      if(nxt[i][j] == -1) {
        nxt[i+1][j] = -1;
      } else {
        nxt[i+1][j] = nxt[i][nxt[i][j]];
      }
    }
  }
  rep(i, M) {
    sum[0][i] = nxt[0][i];
  }
  rep(i, NUM) {
    rep(j, M) {
      if(sum[i][j] == -1) {
        sum[i+1][j] = -1;
      } else {
        sum[i+1][j] = sum[i][j] + sum[i][nxt[i][j]];
      }
    }
  }
  // rep(i, NUM+1) {
  //   rep(j, M) {
  //     cout << nxt[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout << calcPar(X, N-1) + X << endl;
  // cout << sum[0][2] << endl;
  // cout << sum[1][2] << endl;
  // cout << sum[2][2] << endl;
  return 0;
}