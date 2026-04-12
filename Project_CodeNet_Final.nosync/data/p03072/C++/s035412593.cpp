#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

int main(){
  int n,ans=0;cin>>n;
  vector<int> h(n,0);
  REP(i,n) cin>>h.at(i);
  REP(i,n){
    bool f=1;
    REP(j,i) if(h.at(j)>h.at(i)) f=0;
    if(f) ans++;
  }
  cout<<ans;
}