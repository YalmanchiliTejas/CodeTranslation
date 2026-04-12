#include<iostream>
using namespace std;
int main(){
  int H, W;
  cin>>H>>W;
  char a[H][W];
  int row[W]={0},col[H]={0};
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++) cin>>a[i][j];
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++){
      if(a[i][j]=='#'){
        col[i]=1;
        row[j]=1;
      }
    }
  for(int i=0;i<H;i++){
    int count=0;
    for(int j=0;j<W;j++){
      if(col[i]==1&&row[j]==1){
        count++;
        cout<<a[i][j];
      }
    }
    if(count>0) cout<<endl;
  }
  return 0;
}