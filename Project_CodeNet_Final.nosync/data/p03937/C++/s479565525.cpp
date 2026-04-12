#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
main(){
  int n,m; cin>>n>>m;
  int count(0);
  rep(i,n){
    string s; cin>>s;
    rep(j,m){
      if(s[j]=='#'){
        count++;
      }
    }
  }
  if(count==n+m-1){
    cout<<"Possible";
  }else{
    cout<<"Impossible";
  }
}
