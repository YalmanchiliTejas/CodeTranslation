#include<bits/stdc++.h>
using namespace std;
int main(){
  int flag=1,e[12],x[111]={0};
  for(int i=0;i<12;i++){
    cin>>e[i];
    x[e[i]]++;
  }
  for(int i=1;i<=100;i++){
    int ret=0;
    if(x[i]==0) ret++;
    if(x[i]==4) ret++;
    if(x[i]==8) ret++;
    if(x[i]==12) ret++;
    if(ret==0){
      flag=0;
      break;
    }
  }
  if(flag==0) cout<<"no"<<endl;
  else cout<<"yes"<<endl;
  return(0);
}

