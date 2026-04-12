#include<bits/stdc++.h>
using namespace std;

int main(){
  while(1){
    int a,b,c,d;
    string s,jfen[9];
    cin>>s;
    if(s=="#")break;
    int h=0;
    for(int i=0;i<s.size();i++){
      if(s[i]=='b')jfen[h]+='b';
      else if(s[i]=='/')h++;
      else
	for(int j=0;j<s[i]-'0';j++)
	  jfen[h]+='.';
    }
    cin>>a>>b>>c>>d;
    jfen[a-1][b-1]='.';
    jfen[c-1][d-1]='b';
    string ans;
    for(int i=0;i<=h;i++){
      int x=0;
      for(int j=0;j<jfen[i].size();j++){
	if(jfen[i][j]=='b'){
	  if(x)ans+=x+'0';
	  ans+='b';
	  x=0;
	}else x++;
      }
      if(x)ans+=x+'0';
      if(i!=h)ans+='/';
    }
    cout<<ans<<endl;
  }
  return 0;
}