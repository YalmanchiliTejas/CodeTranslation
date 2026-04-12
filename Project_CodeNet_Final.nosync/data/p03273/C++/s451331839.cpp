#include<bits/stdc++.h>
using namespace std;
int main(){

  int H,W;

  cin>>H>>W;

  int cnt=0;
  
  char mp[101][101];

  for(int i=0;i<H;i++){
    cnt=0;
    for(int j=0;j<W;j++){
      cin>>mp[i][j];

      if(mp[i][j]=='.'){
	cnt++;
      }
    }

    if(cnt==W){
      for(int j=0;j<W;j++){
	mp[i][j]='*';
      }
    }
  }
  
  for(int i=0;i<W;i++){
    cnt=0;
    for(int j=0;j<H;j++){
      if(mp[j][i]=='.'||mp[j][i]=='*'){
	cnt++;
      }
    }
    if(cnt==H){
      for(int j=0;j<H;j++){
	mp[j][i]='*';
      }
    }
  }
  

  bool judge=0;
  
  for(int i=0;i<H;i++){
    judge=0;
    for(int j=0;j<W;j++){
      if(mp[i][j]!='*'){
	cout<<mp[i][j];
	judge=1;
      }
    }
    if(judge)
      cout<<endl;
  }

  
  return 0;
}
