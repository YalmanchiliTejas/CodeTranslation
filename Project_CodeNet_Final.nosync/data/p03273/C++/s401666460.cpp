#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
  
int main()
{
  int H, W;
  cin >> H >> W;

  vector<string> A(H);
  vector<string> B(H);
  REP(i, H){
    cin >> A[i];
    B[i] = A[i];
  }
  
  REP(i,H){
    int flag = 0;
    REP(j,W){
      if(A.at(i).at(j)!='.'){
        flag = 1;
      }
    }
    if(flag == 0){
      REP(j,W){
        B.at(i).at(j) = '0';
      }
    }
  }

  REP(j,W){
    int flag = 0;
    REP(i,H){
      if(A.at(i).at(j)!='.'){
        flag = 1;
      }
    }
    if(flag == 0){
      REP(i,H){
        B.at(i).at(j) = '0';
      }
    }
  }

  REP(i,H){
    int flag = 0;
    REP(j,W){
      if(B.at(i).at(j) == '0'){
        continue;
      }
      cout << B.at(i).at(j);
      flag = 1;
    }
    if(flag == 1){
      cout << endl;
    }
  }
}