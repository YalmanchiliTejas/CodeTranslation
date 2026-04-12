#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int n;
  string s;
  cin>>n>>s;
  char sw[]={'S','W'};
  rep(i,4){
    vector<int> animals(n);
    animals[0]=i/2;
    animals[1]=i%2;
    rep(j,n-2){
      if(s[j+1]=='o'){
        if(animals[j]==animals[j+1]) animals[j+2]=0;
        else animals[j+2]=1;
      }
      else{
        if(animals[j]==animals[j+1]) animals[j+2]=1;
        else animals[j+2]=0;
      }
    }
    
    bool ok=true;
    if(animals[0]==0){
      if(animals[n-1]==animals[1] && s[0]=='x') ok=false;
      if(animals[n-1]!=animals[1] && s[0]=='o') ok=false;
    }
    else{
      if(animals[n-1]==animals[1] && s[0]=='o') ok=false;
      if(animals[n-1]!=animals[1] && s[0]=='x') ok=false;
    }
    
    if(animals[n-1]==0){
      if(animals[n-2]==animals[0] && s[n-1]=='x') ok=false;
      if(animals[n-2]!=animals[0] && s[n-1]=='o') ok=false;
    }
    else{
      if(animals[n-2]==animals[0] && s[n-1]=='o') ok=false;
      if(animals[n-2]!=animals[0] && s[n-1]=='x') ok=false;
    }
    
    if(ok){
      rep(k,n) cout<<sw[animals[k]];
      cout<<endl;
      return 0;
    }
  }
  cout<<"-1"<<endl;
  return 0;
}
