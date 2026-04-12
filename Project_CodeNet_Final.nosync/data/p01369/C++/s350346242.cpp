#include <bits/stdc++.h>
using namespace std;

bool b(char ch){
  string k="yuiophjklnm";
  for(int i=0;i<(int)k.size();i++)
    if(k[i]==ch) return 1;
  return 0;
}

int main(){
  string s;
  while(cin>>s && s!="#"){
    int ans=0;
    bool f=b(s[0]);
    for(int i=1;i<(int)s.size();i++){
      if(f!=b(s[i])){ans++;f=!f;}
    }
    cout<<ans<<endl;
  }
  return 0;
}