#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int h,w;cin>>h>>w;

  vector<string> s;
  rep(i,h){
    string t;
    cin>>t;
    if(count(t.begin(), t.end(), '.')==w)continue;
    s.push_back(t);
  }

  bool enable_columns[w];
  rep(i,w){
    enable_columns[i]=false;
    rep(j,s.size()){
      if(s[j][i]=='#'){
        enable_columns[i]=true;
        break;
      }
    }
  }

  rep(i,s.size()){
    rep(j,w){
      if(enable_columns[j])cout<<s[i][j];
    }
    cout<<endl;
  }

  return 0;
}