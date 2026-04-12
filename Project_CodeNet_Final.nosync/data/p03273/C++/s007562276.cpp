#include <bits/stdc++.h>
using namespace std;
string mp[111];
int N,M;
int a[111],b[111];
int main(){
  cin>>N>>M;
  for(int i=0;i<N;i++)
    cin>>mp[i];
  for(int i=0;i<N;i++){
    int f=0;
    for(int j=0;j<M;j++){
      if(mp[i][j]=='#')f=1;
    }
    if(!f){
      a[i]=1;
    }
  }
  for(int i=0;i<M;i++){
    int f=0;
    for(int j=0;j<N;j++){
      if(mp[j][i]=='#')f=1;
    }
    if(!f){
      b[i]=1;
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++)
      if(!a[i]&&!b[j])
        putchar(mp[i][j]);
    if(!a[i])puts("");
  }
}