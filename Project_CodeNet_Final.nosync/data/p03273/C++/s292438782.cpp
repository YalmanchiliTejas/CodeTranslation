#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef long  l;
typedef pair<int,int> P;
const ll INF=100000000000000001;
const double PI=3.141592653589;


int main(){
  int h,w; cin>>h>>w;
  vector<string> a(h);
  rep(i,h) cin>>a[i];

  set<int> t;
  set<int> y;

  rep(i,h){
    bool c=1;
    // cout<<"i "<<i<<endl;
    rep(j,w){
      if(a[i][j]=='#')
      c=0;
    }
    if(c){
      // cout<<"i ireru "<<i<<endl;
      y.insert(i);
    }
  }
  rep(i,w){
    bool c=1;
    rep(j,h){
      if(a[j][i]=='#')
      c=0;
    }
    if(c)
    t.insert(i);
  }

  rep(i,h){
    if(y.count(i))
    continue;
    rep(j,w){
      if(t.count(j))
      continue;
      cout<<a[i][j];
    }
    cout<<endl;
    // cout<<"aa"<<endl;
  }
  return 0;
}
