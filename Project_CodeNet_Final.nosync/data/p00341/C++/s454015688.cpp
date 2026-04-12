#include<bits/stdc++.h>
using namespace std;
int main(){
  int t[101]={0},ans=0;
  for(int i=0;i<12;i++){
    int b;
    cin>>b;
    t[b]++;
    if(t[b]%4==0){
      ans++;
    }
  }
  if(ans==3){
    cout<<"yes"<<endl;
  }else{
    cout<<"no"<<endl;
  }
  return(0);
}

