#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using PLL = pair<LL,LL>;
using VPI = vector<PII>;
using VPL = vector<PLL>;
using VB = vector<bool>;
using VVB = vector<VB>;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define RREP(i,m,n) for(int i=(m);i>=(n);i--)
#define all(v) v.begin(), v.end()

int main(){
  int n,m,ans=0;
  cin >> n >> m;
  VI a(m),b(m);
  REP(i,0,m){
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  VI path(n-1);
  REP(i,0,n-1){
    path[i] = i+1;
  }
  
  sort(all(path));
  do{
    bool ok = false;
    
    REP(i,0,n-1){
      ok = false;
      if(i==0){
        REP(j,0,m){
          if(a[j] == 0 && b[j] == path[0]){
            ok = true;
            break;
          }
        }
      }
      
      if(i>0){
        int former = min(path[i],path[i-1]);
        int latter = max(path[i],path[i-1]);
        REP(j,0,m){
          if(former == a[j] && latter == b[j]){
            ok = true;
            break;
          }
        }
      }
      
      if(!ok){break;}
    }
    
    if(ok){
      ans++;
    }
    
  }while(next_permutation(all(path)));
    
  
  cout << ans << endl;
  
  return 0;
}
