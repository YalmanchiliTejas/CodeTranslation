#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<char>> a(h+1,vector<char>(w+1));
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++)cin>>a[i][j];
    a[i][w]='.';
  }
  for(int i=0; i<w+1; i++)a[h][i]='.';

  bool ans=true;
  int i=0, j=0;
  a[i][j]='.';
  while(i!=h-1 || j!=w-1){
    if(a[i+1][j]==a[i][j+1]){
      ans=false;
      break;
    }else if(a[i+1][j]=='#'){
      a[i+1][j]='.';
      i++;
    }else if(a[i][j+1]=='#'){
      a[i][j+1]='.';
      j++;
    }
  }
  a[i][j]='.';

  for(i=0; i<h; i++){
    for(j=0; j<w; j++){
      if(a[i][j]=='#'){
        ans=false;
        break;
      }
    }
  }
  
  if(ans)cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}
