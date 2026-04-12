#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  vector<char>v={'y','u','i','o','p','h','j','k','l','n','m'};
  while(true){
    string s;int ans=0;
    cin>>s;
    int n=s.size();
    if(s=="#")break;
    rep(j,n){
    bool b=false;
    rep(i,v.size()){
      if(v[i]==s[j])b=true;
    }
    if(b)s[j]='r';
    else s[j]='l';
    }
    rep(i,n-1){
      if(s[i]!=s[i+1])ans++;
    }
    cout<<ans<<endl;
  }
}

