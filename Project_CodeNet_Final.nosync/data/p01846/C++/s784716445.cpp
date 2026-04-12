#include<bits/stdc++.h>
using namespace std;

int main(){
  while(1){
    string s;
    vector<string> v;
    cin>>s;
    if(s=="#")break;
    string tmp="";
    for(int i=0;i<(int)s.size();i++){
      if(s[i]=='/'){
        v.push_back(tmp);
        tmp="";
      }else if(s[i]=='b'){
        tmp+='o';
      }else{
        for(int j=0;j<(s[i]-'0');j++)
          tmp+='.';
      }
    }
    v.push_back(tmp);
    
    int ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    v[ax-1][ay-1]='.';
    v[bx-1][by-1]='o';
    string ans="";
    for(int i=0;i<(int)v.size();i++){
      int cnt=0;
      for(int j=0;j<(int)v[i].size();j++){
        if(v[i][j]=='o'){
          if(cnt)ans+=('0'+cnt),cnt=0;
          ans+='b';
        }else{
          cnt++;
        }
      }
      if(cnt)ans+=('0'+cnt);
      if(i+1<(int)v.size())ans+='/';
    }

    cout<<ans<<endl;
  }
  return 0;
}