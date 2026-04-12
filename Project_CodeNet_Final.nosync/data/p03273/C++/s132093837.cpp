#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  ll a,b;
  cin>>a>>b;
  vector<string> v(a);
  string in;
  FOR(i,0,a){
    cin>>in;
    v[i]=in;
  }
  int flag=0;
  char x;
  vector<int> keya(a,0);
  vector<int> keyb(b,0);


  FOR(i,0,a){
    x='.';
    flag=0;
    FOR(j,0,b){
      if(x!=v[i][j]) flag=1;
    }
    keya[i]=flag;
  }

  FOR(i,0,b){
    x='.';
    flag=0;
    FOR(j,0,a){
      if(x!=v[j][i]) flag=1;
    }
    keyb[i]=flag;
  }

  FOR(i,0,a){
    FOR(j,0,b){
      if(keya[i]==1 && keyb[j]==1){
        cout<<v[i][j];
      }
    }
    if(keya[i]==1)cout<<endl;
  }

}
