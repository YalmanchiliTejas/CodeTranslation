#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define SIZE(a) int((a).size();
const int INF=INT_MAX;
const int dx[5]={-1,0,0,0,1};
const int dy[5]={0,-1,0,1,0};
int main(){
  ll h,w;cin>>h>>w;
  vvb masu(h,vb(w));
  rep(i,0,h){
    rep(j,0,w){
      char x;cin>>x;
      masu[i][j]=(x=='#')?1:0;
    }
  }
  vll hh(h,0),ww(w,0);
  rep(i,0,h){
    ll count=0;
    rep(j,0,w){
      if(!masu[i][j]){count++;}
    }
    if(count==w){hh[i]++;}
  }
  rep(i,0,w){
    ll count=0;
    rep(j,0,h){
      if(masu[j][i]==0){count++;}
    }
    if(count==h){ww[i]++;}
  }
  rep(i,0,h){
    rep(j,0,w){
      if(hh[i]==0&&ww[j]==0){
        if(masu[i][j]){cout<<'#';}
        else{cout<<'.';}
      }
    }
    if(hh[i]==0)cout<<endl;
  }

}