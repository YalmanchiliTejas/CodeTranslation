#include <bits/stdc++.h>
using namespace std;

int main(){
  while(1){
  string str;
  cin>>str;
  if(str=="#")break;
  int mp[10][10]={};

  int  x=0,y=0;
  int w,h;
  for(int i=0;i<str.size();i++){
    if(str[i]=='/'){
      y++;
      h=y;
      w=x;
      x=0;
      continue;
    }
    if(str[i]=='b') mp[y][x++]=1;
    else if('0'<=str[i]&&str[i]<='9') x+=str[i]-'0';
  }


  int a,b,c,d;
  cin>>a>>b>>c>>d;
  a--,b--,c--,d--;
  mp[c][d]=mp[a][b];
  mp[a][b]=0;

  string ans;
  for(int i=0;i<=h;i++){
    int cnt=0;
    for(int j=0;j<w;j++){
      if(mp[i][j]==0) cnt++;
      else if(cnt) ans+=(cnt+'0'),cnt=0;
      if(mp[i][j]==1) ans+='b';
    }
    if(cnt) ans+=(cnt+'0');
    if(i!=h)ans+='/';
  }
  cout <<ans<<endl;
  }
  return 0;
}