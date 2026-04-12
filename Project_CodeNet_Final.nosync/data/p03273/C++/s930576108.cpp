#include<bits/stdc++.h>
using namespace std;
main(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;++i)cin>>s[i];
  
  for(int i=0;i<h;++i){
    bool lf=false;
    for(int j=0;j<w;++j){
      string t(w,'.');
      if(t==s[i])continue;
      bool ok=false;
      for(int k=0;k<h;++k)if(s[k][j]=='#')ok=true;
      if(ok){
        cout<<s[i][j];
        lf=true;
      }
    }
    if(lf)cout<<endl;
  }
}
