#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}

using ull = unsigned long long;

vector<vector<ull>> solve(vector<int> S, vector<int> T, vector<int> U, vector<int> V) {
  const int N = S.size();
  vector<vector<ull>> ans(N, vector<ull>(N));

  REP(i, N) REP(j, N) ans[i][j] = 2;

  REP(i, N) if (S[i] == 0 && U[i] == 1) REP(j, N) ans[i][j] = 1;
  REP(i, N) if (S[i] == 1 && U[i] == 0) REP(j, N) ans[i][j] = 0;
  REP(j, N) if (T[j] == 0 && V[j] == 1) REP(i, N) ans[i][j] = 1;
  REP(j, N) if (T[j] == 1 && V[j] == 0) REP(i, N) ans[i][j] = 0;

  REP(_, 4) {
    REP(i, N) if (S[i] == 0 && U[i] == 0) {
      vector<int> c(3); REP(j, N) c[ans[i][j]]++;
      if (c[0] == 0 && c[2] == 1) {
        REP(j, N) if (ans[i][j] == 2) ans[i][j] = 0;
      }
    }
    REP(i, N) if (S[i] == 1 && U[i] == 1) {
      vector<int> c(3); REP(j, N) c[ans[i][j]]++;
      if (c[1] == 0 && c[2] == 1) {
        REP(j, N) if (ans[i][j] == 2) ans[i][j] = 1;
      }
    }
    REP(j, N) if (T[j] == 0 && V[j] == 0) {
      vector<int> c(3); REP(i, N) c[ans[i][j]]++;
      if (c[0] == 0 && c[2] == 1) {
        REP(i, N) if (ans[i][j] == 2) ans[i][j] = 0;
      }
    }
    REP(j, N) if (T[j] == 1 && V[j] == 1) {
      vector<int> c(3); REP(i, N) c[ans[i][j]]++;
      if (c[1] == 0 && c[2] == 1) {
        REP(i, N) if (ans[i][j] == 2) ans[i][j] = 1;
      }
    }
  }

  vector< vector<int> > poss;
  REP(i, N) {
    vector<int> pos;
    REP(j, N) if (ans[i][j] == 2) { pos.push_back(i * 10000 + j); }
    if (pos.size() > 0) poss.push_back(pos);
  }

  REP(a, poss.size()) {
    REP(b, poss[a].size()) {
      int i = poss[a][b] / 10000;
      int j = poss[a][b] % 10000;
      ans[i][j] = (a + b) % 2;
    }
  }

  return ans;
}

int main2() {
  int N; cin >> N;
  vector<int> S(N), T(N);
  vector<ull> U(N), V(N);
  REP(i, N) cin >> S[i];
  REP(i, N) cin >> T[i];
  REP(i, N) cin >> U[i];
  REP(i, N) cin >> V[i];

  vector<vector<ull>> ans(N, vector<ull>(N));

  REP(b, 64) {
    vector<int> u(N), v(N);
    REP(i, N) u[i] = (U[i] >> b & 1);
    REP(i, N) v[i] = (V[i] >> b & 1);

    vector<vector<ull>> m = solve(S, T, u, v);
    REP(i, N) REP(j, N) {
      ans[i][j] |= (m[i][j] << b);
    }
  }

  bool valid = true;
  REP(i, N) {
    ull val = ans[i][0];
    if (S[i] == 0) { REP(j, N) val &= ans[i][j]; }
    else {           REP(j, N) val |= ans[i][j]; }
    if (val != U[i]) valid = false;
  }
  REP(j, N) {
    ull val = ans[0][j];
    if (T[j] == 0) { REP(i, N) val &= ans[i][j]; }
    else {           REP(i, N) val |= ans[i][j]; }
    if (val != V[j]) valid = false;
  }
  if (valid) {
    REP(i, N) {
      REP(j, N) {
        if (j) cout << " ";
        cout << ans[i][j];
      }
      cout << endl;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}