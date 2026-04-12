#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define rep(i, n) for(int i=0;i<n;i++)

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> a.at(i).at(j);
    }
  }
  VI hcheck(h);
  rep(i,h){
    rep(j,w){
      if(a.at(i).at(j)=='.'){
        hcheck.at(i)++;
      }
    }
  }
  VI wcheck(w);
  rep(i,w){
    rep(j,h){
      if(a.at(j).at(i)=='.'){
        wcheck.at(i)++;
      }
    }
  }
  rep(i,h){
    rep(j,w){
      bool b=true;
      bool c=true;
    if(hcheck.at(i)==w){
      b=false;
    }
      if(wcheck.at(j)==h){
        c=false;
    }
     if(b && c) cout << a.at(i).at(j) ;
     if(b){
       if(j==w-1) cout << endl;
     }
    }
  }
      
      
}