#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int H,W;
  cin>>H>>W;
  vector<string>a(H);
  for(int i=0;i<H;i++)cin>>a[i];
  vector<vector<bool>>b(H,vector<bool>(W,true));
  for(int i=0;i<H;i++){
    bool black=false;
    for(int j=0;j<W;j++){
      if(a[i][j]=='#')black=true;
    }
    if(!black){
      for(int j=0;j<W;j++){
        b[i][j]=false;
      }
    }
  }
  for(int i=0;i<W;i++){
    bool black=false;
    for(int j=0;j<H;j++){
      if(a[j][i]=='#')black=true;
    }
    if(!black){
      for(int j=0;j<H;j++){
        b[j][i]=false;
      }
    }
  }
  for(int i=0;i<H;i++){
    bool c=false;
    for(int j=0;j<W;j++){
      if(b[i][j])cout<<a[i][j],c=true;
    }
    if(c)cout<<endl;
  }
  return 0;
}
