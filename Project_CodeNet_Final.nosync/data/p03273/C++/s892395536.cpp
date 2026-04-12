#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int h,w;
  char s[110][110];
  bool masu[110][110]={false};
  cin>>h>>w;
  bool out=false;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
      if(s[i][j]=='#') out=true;
    }
    if(out==false){
      for(int j=0;j<w;j++) masu[i][j]=true;
    }
    out=false;
  }
  for(int j=0;j<w;j++){
    for(int i=0;i<h;i++){
      if(s[i][j]=='#') out=true;
    }
    if(out==false){
      for(int i=0;i<h;i++) masu[i][j]=true;
    }
    out=false;
  }
  int sum=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(masu[i][j]==false) cout<<s[i][j];
      else sum++;
    }
    if(sum!=w) cout<<'\n';
    sum=0;
  }
  return 0;
}
