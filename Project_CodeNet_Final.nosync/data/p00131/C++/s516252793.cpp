#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin>>n;
  while(n--){
    int mp[12][12],ans[12][12];
    for(int i=1;i<=10;i++)for(int j=1;j<=10;j++) cin>>mp[i][j];
    int cp[12][12];
 
    for(int i=0;i<(1<<10);i++){
       
      for(int j=1;j<=10;j++)
    for(int k=1;k<=10;k++)cp[j][k]=mp[j][k],ans[j][k]=0;
      for(int j=0;j<10;j++){
    if(i&(1<<j)){
      cp[1][j+1]=!cp[1][j+1];
      cp[1][j]=!cp[1][j];
      cp[1][j+2]=!cp[1][j+2];
      cp[2][j+1]=!cp[2][j+1];
      ans[1][j+1]=1;
    }
      }
      for(int j=2;j<=10;j++){
    for(int k=1;k<=10;k++){
      if(cp[j-1][k]){
        cp[j-1][k]=!cp[j-1][k];
        cp[j][k]=!cp[j][k];
        cp[j][k-1]=!cp[j][k-1];
        cp[j][k+1]=!cp[j][k+1];
        cp[j+1][k]=!cp[j+1][k];
        ans[j][k]=1;
      }
    }
      }
      int f=0;
      for(int j=1;j<=10;j++)
    for(int k=1;k<=10;k++)
      if(cp[j][k])f=1;
      if(!f)break;
    }
 
    for(int i=1;i<=10;i++){
      for(int j=1;j<=10;j++){
    if(j!=1)cout<<' ';
    cout<<ans[i][j];
      }
      cout<<endl;
    }
  }
  return 0;
}