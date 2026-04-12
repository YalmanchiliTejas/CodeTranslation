#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;cin>>h>>w;
  string a[h];
  for(int i=0;i<h;i++)cin>>a[i];
  for(int i=0;i<1<<h+w-2;i++){
    bool used[h][w];
    for(int j=0;j<h;j++)for(int k=0;k<w;k++)used[j][k]=false;
    int now=i;
    int c=0;
    int x=0,y=0;
    used[0][0]=true;
    for(int j=0;j<h+w-2;j++){
      if(now%2==0)x++;
      else y++;
      if(x>=w||y>=h){
        c=1;
        break;
      }
      now/=2;
      used[y][x]=true;
    }
    int d=0;
    if(c==0){
      for(int j=0;j<h;j++){
        for(int k=0;k<w;k++){
          if((a[j][k]=='#'&&used[j][k]==false)||(a[j][k]=='.'&&used[j][k]==true)){
            d=1;
            break;
          }
        }
        if(d==1)break;
      }
      if(d==0){
        cout<<"Possible"<<endl;
        return 0;
      }
    }
  }
  cout<<"Impossible"<<endl;
}
