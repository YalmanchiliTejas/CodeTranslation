#include<bits/stdc++.h>
using namespace std;
char c[109][109];
int p[109];
int q[109];

int main(){
  int h,w;
  cin>>h>>w;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>c[i][j];
    }
  }
  for(int i=0;i<h;i++){
    int cnt=0;
    for(int j=0;j<w;j++){
      if(c[i][j]=='#')cnt++;
    }
    if(cnt==0)p[i]=1;
  }
  for(int i=0;i<w;i++){
    int cnt=0;
    for(int j=0;j<h;j++){
      if(c[j][i]=='#')cnt++;
    }
    if(cnt==0)q[i]=1;
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(p[i]==0&&q[j]==0){
        cout<<c[i][j];
      }
    }
    if(p[i]==0)cout<<endl;
  }
  return(0);
}