#include <map>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <climits>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;

template<class T>
class IdMaker{
public:
  std::map<T,int> _m;
  int getId(const T &v){
    if(_m.find(v) == _m.end()){
      int next = _m.size();
      return _m[v] = next;
    }
    return _m[v];
  }
};

int V[7];
int P[7];

int L[7];
int X[7];
int Y[7];

int Q[7][7];

int dist(int x1, int y1, int x2, int y2){
  return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
  int n, m, w, t;
  IdMaker<string> idm;

  cin >> n >> m >> w >> t;

  vector<long long> dpa(t + 1);

  REP(i, m){
    string s; cin >> s;
    cin >> V[idm.getId(s)] >> P[idm.getId(s)];
  }

  REP(i, n){
    cin >> L[i] >> X[i] >> Y[i];

    REP(j, L[i]){
      string r; cin >> r;
      cin >> Q[i][idm.getId(r)];
    }
  }

  REP(i, (1 << n)){
    vector<int> v;
    REP(j, n) if(i & (1 << j))
      v.push_back(j);

    int t_memo = INT_MAX;
    long long m_memo = 0;

    do{
      int px = 0;
      int py = 0;

      int tm = 0;

      REP(j, v.size()){
        tm += dist(px, py, X[v[j]], Y[v[j]]);
        px = X[v[j]]; py = Y[v[j]];
      }
      tm += dist(px, py, 0, 0);

      t_memo = min(t_memo, tm);
    }while(next_permutation(v.begin(), v.end()));

    // cout << "i=" << i << " : tm=" << t_memo << endl;

    vector<long long> dp(w + 1);

    REP(i, v.size()){
      REP(j, m) if(Q[v[i]][j]){
        int weight = V[j];
        int earn   = P[j] - Q[v[i]][j];

        if(earn <= 0) continue;

        REP(k, w){
          if(k + weight > w) break;
          dp[k + weight] = max(dp[k + weight], dp[k] + earn);
        }
      }
    }

    REP(k, w + 1)
      m_memo = max(m_memo, dp[k]);

    REP(k, t + 1){
      if(k + t_memo > t) break;
      dpa[k + t_memo] = max(dpa[k + t_memo], dpa[k] + m_memo);
    }
  }

  long long ans = 0;

  REP(i, t + 1){
    // cout << "dpa[" << i << "]: " << dpa[i] << endl;
    ans = max(ans, dpa[i]);
  }

  cout << ans << endl;

  return 0;
}