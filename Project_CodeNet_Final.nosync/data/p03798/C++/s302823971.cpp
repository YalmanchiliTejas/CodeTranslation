#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i,n) for(ll i=0; i < (n); ++i)
#define REPR(i,n) for(ll i=(n); i >= 0; --i)
#define FOR(i, m, n) for(ll i = (m); i < (n); ++i)

#define INF 1e9

int N;
string s;
vector<vector<int>> patern;
int W = 0, S = 1;


int cmb(int sw, char ox, int t){
  if(sw == W && ox == 'o'){
    return (t+1) % 2;
  }
  else if(sw==W && ox=='x'){
    return t;
  }
  else if(sw == S && ox=='o'){
    return t;
  }
  else{
    return (t+1) % 2;
  }
}

void solve(){
  REP(i, 4){
    REP(j, N-1){
      if(j == 0){
        patern[i][N-1] = cmb(patern[i][0], s[0], patern[i][1]);
      }
      else if(j == N-2){
        if(cmb(patern[i][j], s[j], patern[i][j-1]) == patern[i][N-1] && cmb(patern[i][j+1], s[j+1], patern[i][j]) == patern[i][0]){
          REP(k, N){
            if(patern[i][k] == W){
              cout << 'W';
            }
            else{
              cout << 'S';
            }
          }
          cout << endl;
          return;
        }
      }
      else{
        patern[i][j+1] = cmb(patern[i][j], s[j], patern[i][j-1]);
      }
    }
  }
  cout << -1 << endl;
}

int main(){
  cin >> N >> s;
  patern.resize(4, vector<int>(N));
  patern[0][0] = patern[0][1] = W;
  patern[1][0] = W, patern[1][1] = S;
  patern[2][0] = patern[2][1] = S;
  patern[3][0] = S, patern[3][1] = W;
  solve();

  return 0;
}
