#include <bits/stdc++.h>
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); i++) 
#define FOR(i, a, b) for(int (i) = a; (i) < (int)b; i++)
#define RREP(i, n) for(int (i)=((int)(n)-1); (i)>=0; i--)
#define RFOR(i, a, b) for(int (i) =((int)(b)-1); (i)>=(int)a; i--)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define F first
#define S second

using namespace std ;
typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef pair<int, int> pint;
const int Inf = 1e9;
const double EPS = 1e-9;



int main()
{
  int h, w ;
  cin >> h >> w ;
  vector<bool> gyou(h,false) ;
  vector<bool> retsu(w,false) ;
  vector<string> lit(h) ;
  
  REP(i,h){
    cin >> lit.at(i) ;
  }
  
  REP(i,h){
    REP(j,w){
      if(lit.at(i).at(j)!='.'){
        gyou.at(i) = true ;
        retsu.at(j) = true ;
      }
    }
  }
  
  REP(i,h){
    if(gyou.at(i)){
      REP(j,w){
        if(retsu.at(j)){
          cout << lit.at(i).at(j) ;
        }
      }
      cout << endl ;
    }
  }

  
  return 0 ;
}


