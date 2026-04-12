#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,w[10000]={};
  int q[10000]={};
  string c[1000];
  cin>>a>>b;
  for(int i=0;i<a;i++){
    cin>>c[i];
  }
  for(int i=0;i<a;i++){
     q[10000];
    for(int j=0;j<b;j++){
      if(c[i][j]=='#') q[i]=1,w[j]=1;
    }
  }
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      if(w[j]==1&&q[i]==1) cout<<c[i][j];
    }
    cout<<"\n";
  }
}
