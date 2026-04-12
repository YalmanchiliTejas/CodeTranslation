#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(Int i=0;i<h;i++) cin>>s[i];

  {
    vector<string> t;
    for(Int i=0;i<h;i++)
      if(s[i]!=string(w,'.')) t.emplace_back(s[i]);
    s=t;
    h=s.size();
  }
  
  {
    vector<string> t(h);
    for(Int j=0;j<w;j++){
      Int flg=0;
      for(Int i=0;i<h;i++) flg|=s[i][j]=='#';
      if(!flg) continue;
      for(Int i=0;i<h;i++)
	t[i].push_back(s[i][j]);
    }
    s=t;
    w=s[0].size();
  }
  

  for(string x:s) cout<<x<<endl;
  return 0;
}
