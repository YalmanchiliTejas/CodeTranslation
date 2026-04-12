#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pi 3.14159265359
#define all(i) i.begin(),i.end()
using namespace std;
const long long INF=1e9+7;
const string alp="abcdefghijklmnopqrstuvwxyz"; //26
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=998244353LL;
//const ll MOD=1777777777LL;


int main() {
  ll H,W;
  cin>>H>>W;
  char a[H][W];
  rep(i,H){
    rep(j,W){
      cin>>a[i][j];
    }
  }
  bool b[H];
  bool c[W];
  rep(i,H) b[i]=true;
  rep(i,W) c[i]=true;
  rep(i,H){
    rep(j,W){
      if(a[i][j]=='#'){
        b[i]=false;
        c[j]=false;
      }
    }
  }
  rep(i,H){
    if(!b[i]){
      rep(j,W){
        if(!c[j]){
          cout<<a[i][j];
        }
      }
      cout<<endl;
    }
  }
}