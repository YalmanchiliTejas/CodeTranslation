#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  int h,w;
  cin>>h>>w;
  string masu[h];
  for(int i=0;i<h;i++){
    cin>>masu[i];
  }
  bool yoko[h],tate[w];
  for(int i=0;i<h;i++) yoko[i]=true;
  for(int i=0;i<w;i++) tate[i]=true;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(masu[i][j]=='#'){
        yoko[i]=false;
        tate[j]=false;
      }
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(!yoko[i] and !tate[j])cout<<masu[i][j];
    }
    cout<<endl;
  }
  return 0;
}
