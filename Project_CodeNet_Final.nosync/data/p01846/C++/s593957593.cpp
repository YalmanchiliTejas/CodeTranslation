#include<bits/stdc++.h>
using namespace std;

int main(){

  string s;

  while(cin>>s&&s!="#"){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    bool mp[9][9]={};
    int x=0,y=0;
    for(int i=0;i<s.size();i++){
      if(s[i]=='/')y++,x=0;
      else if(s[i]=='b')mp[y][x]=1,x++;
      else x+=s[i]-'0';
    }
    
    swap(mp[a-1][b-1],mp[c-1][d-1]);
    
    for(int i=0;i<=y;i++){
      int t=0;
      for(int j=0;j<x;j++){
	if(mp[i][j]){
	  if(t)cout<<t,t=0;
	  cout<<'b';
	}
	else t++;
      }

      if(t)cout<<t;
      if(i!=y)cout<<'/';
    }
    
    cout<<endl;
  }

  return 0;
}