#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
  int h,w; cin>>h>>w;
  char masu[h][w];
  int cnt=0;
  rep(i, h){
    rep(j, w){
      cin>>masu[i][j];
      if(masu[i][j]=='#')
        cnt++;
    }
  }
  bool imp=false;
    rep(i, h){
    rep(j, w){
      if(masu[i][j]=='#'){
        if(i!=h-1&&j!=w-1){
          if(masu[i+1][j]=='.'&&masu[i][j+1]=='.'){
            imp=true;}
        }
        else if(i==h-1&&j!=w-1){
          if(masu[i][j+1]=='.'){
            imp=true;}
        }
        else if(i!=h-1&&j==w-1){
          if(masu[i+1][j]=='.'){
            imp=true;}
        }  
      }
    }
  }
     if(imp==true||cnt!=h+w-1)
       cout<<"Impossible"<<endl;
      else
        cout<<"Possible"<<endl;
      

}
