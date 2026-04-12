#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int h,w,p;
  cin>>h>>w;
  char a[h][w];
  rep(i,h){
    rep(j,w){
      cin>>a[i][j];
    }
  }
  int co[h],co2[w];
  rep(i,h){
    co[i]=0;
  }
  rep(i,w){
    co2[i]=0;
  }
   rep(i,h){
    rep(j,w){
      if(a[i][j]=='#'){
        break;
      }else{
        co[i]++;
      }
    }
   }
   rep(j,w){
    rep(i,h){
      if(a[i][j]=='#'){
        break;
      }else{
        co2[j]++;
      }
    }
   }
  p=0;
  rep(i,h){
    rep(j,w){
      if(co[i]!=w&&co2[j]!=h){
        cout<<a[i][j];
      }
      if(co[i]!=w){
        p=1;
      }
    }
    if(p==1){
      cout<<endl;
      p=0;
    }
  }     
}
