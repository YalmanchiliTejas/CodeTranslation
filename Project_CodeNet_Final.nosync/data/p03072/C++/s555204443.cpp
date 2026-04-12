#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007

using namespace std ;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;




int main()
{
  int n ;
  cin >> n ;
  vector<int> hei(n) ;
  int count = 0 ;
  
  REP(i,n){
    cin >> hei.at(i) ;
  }
  
  int ma = 0 ;
  
  REP(i,n){
    ma = max(ma,hei.at(i)) ;
   // cout << ma <<endl ;
    if(ma==hei.at(i)){
      count++ ;
    }
  }
  cout << count <<endl ;
    
    

  return 0 ;
}


