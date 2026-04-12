#include <iostream>
#include <string>
using namespace std;

#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define IEP(i,b,n) for(int i=b;i>=n;i--)
#define iep(i,b) IEP(i,b,0)

const string nesw = "NESWRL";
int n;

void solve() {
  int dice[4][3] = {
    {4,1,3},
    {0,2,0},
    {0,6,0},
    {0,5,0}
  };
  
  int res = 1;
  rep(i,n) {
    string order; cin>>order;
    int o = nesw.find(order[0]);
    switch (o) {
      case 0: {
        int t = dice[0][1];
        rep(j,3) dice[j][1] = dice[j+1][1];
        dice[3][1] = t;
        break;
      }
      case 1: {
        int t = dice[0][2];
        dice[0][2] = dice[0][1];
        dice[0][1] = dice[0][0];
        dice[0][0] = dice[2][1];
        dice[2][1] = t;
        break;
      }
      case 2: {
        int t = dice[3][1];
        IEP(j,3,1) dice[j][1] = dice[j-1][1];
        dice[0][1] = t;
        break;
      }
      case 3: {
        int t = dice[0][0];
        dice[0][0] = dice[0][1];
        dice[0][1] = dice[0][2];
        dice[0][2] = dice[2][1];
        dice[2][1] = t;
        break;
      }
      case 4: {
        int t = dice[0][0];
        dice[0][0] = dice[1][1];
        dice[1][1] = dice[0][2];
        dice[0][2] = dice[3][1];
        dice[3][1] = t;
        break;
      }
      case 5: {
        int t = dice[0][2];
        dice[0][2] = dice[1][1];
        dice[1][1] = dice[0][0];
        dice[0][0] = dice[3][1];
        dice[3][1] = t;
        break;
      }
    }
    /*
    cout<<dice[0][1]<<endl;
    rep(j,3) cout<<dice[0][j];
    cout<<endl;
    REP(j,1,4) cout<<" "<<dice[j][1]<<endl;
    */
    res += dice[0][1];
  }
  cout<<res<<endl;
  //cout<<"+++++"<<endl;
}

int main (int argc, char const* argv[]) {
  while (cin>>n, n) {
    solve();
  }
  return 0;
}