#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int i,j,h,w;
  cin >> h >> w;
  int x[110][110];
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      char s;
      cin >> s;
      if(s=='.'){
        x[i][j]=0;
      }
      else{
        x[i][j]=1;
      }
    }
  }
  for(i=0;i<h;i++){
    int res=0;
    for(j=0;j<w;j++){
      if(x[i][j]==1){
        res=1;
        break;
      }
    }
    if(res==0){
      for(j=0;j<w;j++){
        x[i][j]=-1;
      }
    }
  }
  for(i=0;i<w;i++){
    int res=0;
    for(j=0;j<h;j++){
      if(x[j][i]==1){
        res=1;
        break;
      }
    }
    if(res==0){
      for(j=0;j<h;j++){
        x[j][i]=-1;
      }
    }
  }
  for(i=0;i<h;i++){
    int res=0;
    for(j=0;j<w;j++){
      if(x[i][j]==0){
        cout << '.';
        res=1;
      }
      else if(x[i][j]==1){
        cout << '#';
        res=1;
      }
    }
    if(res==1){
      cout << endl;
    }
  }
}