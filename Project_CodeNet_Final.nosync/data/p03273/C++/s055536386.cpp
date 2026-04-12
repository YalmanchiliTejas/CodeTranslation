#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <utility>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
typedef long long int ll;

int main() {
  int H,W;
  cin>>H>>W;
  
  vector<string> a(H);
  rep(i,H){
    cin>>a[i];
  }
  
  vector<bool> tate(H,false);
  vector<bool> yoko(W,false);
   
  rep(i,H){
    rep(j,W){
      if(a[i][j]=='#')
        tate[i]=true;
    }
  }
  
  rep(j,W){
    rep(i,H){
      if(a[i][j]=='#')
        yoko[j]=true;
    }
  }
  
  rep(i,H){
    if(tate[i]){
      rep(j,W){
        if(yoko[j])
          cout<<a[i][j];
      }
      cout<<endl;
    }
  }
  
}
