#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define DEBUG(x) cerr << #x << " = " << x << endl
int euler[100000];
int size[100000];
vector<vector<int>> G;
int dfs(int v, int &k) {
  euler[v] = k++;
  size[v] = 1;
  for (int u : G[v]) {
    size[v] += dfs(u, k);
  }
  return size[v];
}
typedef array<int, 10> ten;
const int sqrtN = 512;
//const int sqrtN = 1;
ten multi(ten a, ten b) {
  ten ret;
  for (int i = 0; i < 10; i++) {
    ret[i] = b[a[i]];
  }
  return ret;
}
struct SqrtDecomposition {
  int N, K;
  vector<int> data;
  vector<ten> blockCount;
  vector<bool> lazyFlag;
  vector<ten> lazyUpdate;
  ten initialValue;
  SqrtDecomposition(int n) : N(n) {
    K = (N + sqrtN - 1) / sqrtN;
    data.assign(K * sqrtN, 0);
    lazyFlag.assign(K, false);
    for (int i = 0; i < 10; i++) {
      initialValue[i] = i;
    }
    lazyUpdate.assign(K, initialValue);
    ten zero;
    zero.fill(0);
    zero[0] = sqrtN;
    blockCount.assign(K, zero);
  }
  void eval(int k) {
    if(lazyFlag[k]) {
      lazyFlag[k] = false;
      for (int i = k * sqrtN; i < (k + 1) * sqrtN; i++) {
        data[i] = lazyUpdate[k][data[i]];
      }
      lazyUpdate[k] = initialValue;
    }
  }
  void put(int a, int b, ten perm) {
    for(int k = 0; k < K; ++k) {
      int l = k * sqrtN, r = (k + 1) * sqrtN;
      if(r <= a || b <= l) continue;
      if(a <= l && r <= b) {
        lazyFlag[k] = true;
        lazyUpdate[k] = multi(lazyUpdate[k], perm);
        //cerr << "lazyUpdate[" << k << "] =";
        //for(int i = 0; i < 10; i++) {
        //  cerr << ' ' << lazyUpdate[k][i];
        //}
        //cerr << endl;
        ten cnt;
        cnt.fill(0);
        for(int i = 0; i < 10; i++) {
          cnt[perm[i]] += blockCount[k][i];
        }
        blockCount[k] = cnt;
      }
      else {
        eval(k);
        blockCount[k].fill(0);
        for(int i = max(a, l); i < min(b, r); ++i) {
          data[i] = perm[data[i]];
        }
        for (int i = l; i < min(r, N); ++i) {
          blockCount[k][data[i]]++;
        }
      }
    }
  }
  int get(int a, int b, int x, int y) {
    int ret = 0;
    for(int k = 0; k < K; ++k) {
      int l = k * sqrtN, r = (k + 1) * sqrtN;
      if(r <= a || b <= l) continue;
      if(a <= l && r <= b) {
        for (int i = x; i <= y; i++) {
          // cerr << "blockCount[" << k << "][" << i << "] = " << blockCount[k][i] << endl;
          ret += blockCount[k][i];
        }
      }
      else {
        eval(k);
        for(int i = max(a, l); i < min(b, r); ++i) {
          if(x <= data[i] && data[i] <= y) {
            ret++;
          }
        }
      }
    }
    return ret;
  }
};
signed main() {
  ios::sync_with_stdio(false);
  int N, Q; cin >> N >> Q;
  G.resize(N);
  REP(i,N-1) {
    int u, v; cin >> u >> v;
    G[u].push_back(v);
  }
  int k = 0;
  dfs(0, k);
  SqrtDecomposition sq(N);
  //cerr << "euler =";
  //for(int i = 0; i < N; i++) {
  //  cerr << ' ' << euler[i];
  //}
  //cerr << endl;
  //cerr << "size =";
  //for(int i = 0; i < N; i++) {
  //  cerr << ' ' << size[i];
  //}
  //cerr << endl;
  while(Q--) {
    int t, r, x, y; cin >> t >> r >> x >> y;
    if(t == 2) {
      ten perm;
      for(int i = 0; i < 10; i++) {
        perm[i] = i;
      }
      perm[x] = y;
      sq.put(euler[r], euler[r] + size[r], perm);
    } else {
      int ans = sq.get(euler[r], euler[r] + size[r], x, y);
      // DEBUG(ans);
      cout << ans << endl;
    }
  }
}