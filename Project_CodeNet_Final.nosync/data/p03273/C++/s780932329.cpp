#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
const int inf=1e9+7;
const ll INF=1e18;


int main() {
  int h,w;
  cin>>h>>w;
  vector<vector<char>> a(h,vector<char> (w));
  rep(i,h){
    rep(j,w){
      cin>>a[i][j] ;
    }
  }
  ///////////
  
  bool ok;
  rep(i,h){
     ok=true;
    rep (j,w){
       if(a[i][j]=='#'){
         ok=false; 
       }
    }
    if(ok){
      a.erase(a.begin()+i);
      h--;
      i--;
      //cout<<1<<endl;
    }
  }
  

  
  
  
  
  rep(i,w){
     ok=true;
    rep (j,h){
       if(a[j][i]=='#'){
         ok=false; 
       }
    }
    if(ok){
      rep(k,h){///上かあらk行目
        a[k].erase(a[k].begin()+i);
        
       // cout<<1<<endl;
      }
      i--;
      w--;
    }
  }
  
  rep(i,h){
     rep(j,w){
       cout<<a[i][j]; 
       
     }
    
    cout<<endl;
  }
  
  
}



