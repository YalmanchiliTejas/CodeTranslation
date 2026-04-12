#include <bits/stdc++.h>
using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<bool> VB;

//REPEAT
//------------------------------------------
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define REP(i,n)  FOR(i,0,n)

//container util
//------------------------------------------
#define pb(a) push_back(a)
#define SORT(V) sort((V).begin(),(V).end())

//constant
//------------------------------------------
const int MOD = 1000000007;
const int INF = 1061109567;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

//main
//------------------------------------------
int main() {
  int H, W;
  cin >> H >> W;
  VS a(H);
  REP(i, H){
      cin >> a.at(i);
  }

  VB goodx(H), goody(W);

  REP(i, H){
    REP(j, W){
      if(a.at(i).at(j)=='#'){
        goodx.at(i)=true;
        goody.at(j)=true;
      }
    }
  }

  REP(i, H){
    if(goodx.at(i)){
      REP(j, W){
        if(goody.at(j)){
          cout << a.at(i).at(j);
        }
      }
      cout << endl;
    }
  }










}
