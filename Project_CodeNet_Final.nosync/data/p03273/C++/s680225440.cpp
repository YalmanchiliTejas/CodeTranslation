#include <iostream>
#include <numeric>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
 
#define repd(i,a,b); for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define ll long long int
 
 
using namespace std;
int main() {
  int h,w;
  cin >> h >> w;
  string b[h];
  string a[h][w];
  rep(i,h){
    cin >> b[i];
    rep(j,w){
      a[i][j] = b[i].substr(j,1);
    }
  }

  bool c[w];
  bool d[h];
  rep(x,w){
    c[x]=false;
  }
  rep(y,h){
    d[y]=false;
  }
  rep(k,w){
    rep(m,h){
      if(a[m][k] == "#"){
        c[k] = true;
      }
    }
  }
  rep(p,h){
    rep(q,w){
      if(a[p][q] == "#"){
        d[p] = true;
      }
    }
  }
    rep(r,h){
      rep(s,w){
        if(d[r] == true && c[s] == true){
          cout << a[r][s];
        }
        if(s == w-1 && d[r] == true){
          cout << endl;
        }
      }
    }
        
    
    
 
 return 0;
}