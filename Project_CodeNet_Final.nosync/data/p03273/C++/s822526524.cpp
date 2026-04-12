#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll H,W;
  cin>>H>>W;
  vector<vector<char>> vec(H,vector<char>(W));
  for(ll i=0;i<H;i++) {
    for(ll j=0;j<W;j++) {
      cin>>vec[i][j];
    }
  }
  

set<ll> tate;
  set<ll> yoko;
  
  for(ll i=0;i<H;i++) {
    bool a=true;
for(ll j=0;j<W;j++) {
  if(vec[i][j]=='#') {
a=false;
  }
}
    
    if(a) {
yoko.insert(i);
    }
  }
  
  
  for(ll i=0;i<W;i++) {
    bool a=true;
for(ll j=0;j<H;j++) {
  if(vec[j][i]=='#') {
a=false;
  }
}
    
    if(a) {
tate.insert(i);
    }
  }
  
  
  for(ll i=0;i<H;i++) {
    if(yoko.count(i)) {
continue;
    }
for(ll j=0;j<W;j++) {
  if(tate.count(j)) {
continue;
  }
  cout<<vec[i][j];
}
    cout<<endl;
  }
}



  
 

