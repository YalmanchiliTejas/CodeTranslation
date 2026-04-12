#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int h,w;
  cin>>h>>w;
  char c[h][w];
  rep(i,0,h){
    rep(j,0,w){
      cin>>c[i][j];
    }
  }
  vector<int> a,b;
  rep(i,0,h){
    bool p=false;
    rep(j,0,w){
      if(c[i][j]=='#'){
        p=true;
      }
    }
    if(p) a.push_back(i);
  }
  rep(i,0,w){
    bool p=false;
    rep(j,0,h){
      if(c[j][i]=='#'){
        p=true;
      }
    }
    if(p) b.push_back(i);
  }
  for(int i:a){
    for(int j:b){
      cout<<c[i][j];
    }
    cout<<endl;
  }
}