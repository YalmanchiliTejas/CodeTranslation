#include <bits/stdc++.h>
//---------------------------
using namespace std;
//---------------------------
#define REP(i,n) for(int i = 0; i < (n); i++)
#define P(x) cout << (x) << "\n"
#define fcout cout << fixed << setprecision(18)

#define MOD 1000000007 // 1e9+7
#define PI 3.1415926535
/*
3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
*/
#define ll long long int // 10^18
#define INF 1000000001 // 1e9+1
#define LINF 1000000000000000001 // 1e18+1

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
//---------------------------

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  int h,w;cin>>h>>w;
  vector<string> a,b;
  REP(i,h){
    string aa;cin>>aa;
    a.push_back(aa);
  }
  int y=0,x=0;
  REP(i,h){
    REP(j,w){
      if(a[i][j]=='#'){
        b.push_back(a[i]);
        y++;
        break;
      }
    }
  }
  // REP(i,y){
  //   P(b[i]);
  // }
  vector<int> v;
  REP(i,w){
    REP(j,y){
      if(b[j][i]=='#'){
        v.push_back(i);
        break;
      }
    }
  }
  REP(i,y){
    string s;
    for(auto index:v){
      s+=b[i][index];
    }
    P(s);
  }
  return 0;
}
