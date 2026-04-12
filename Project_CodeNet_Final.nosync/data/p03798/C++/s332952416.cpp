#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  string s;cin>>s;
  int a[n+1];
  int g=0,h;
  vector<int>b={1,1,2,2};
  vector<int>c={1,2,1,2};
  for(int j=0;j<4;j++){
    a[0]=b.at(j);a[1]=c.at(j);
    if(a[0]==1){
        if(a[1]==1){
          if(s[0]=='o'){
            h=1;
          }
          else{
            h=2;
          }
        }
        else{
          if(s[0]=='o'){
            h=2;
          }
          else{
            h=1;
          }
        }
      }
      else{
        if(a[1]==1){
          if(s[0]=='o'){
            h=2;
          }
          else{
            h=1;
          }
        }
        else{
          if(s[0]=='o'){
            h=1;
          }
          else{
            h=2;
          }
        }
      }
    
    for(int i=1;i<n;i++){
      if(a[i]==1){
        if(a[i-1]==1){
          if(s[i]=='o'){
            a[i+1]=1;
          }
          else{
            a[i+1]=2;
          }
        }
        else{
          if(s[i]=='o'){
            a[i+1]=2;
          }
          else{
            a[i+1]=1;
          }
        }
      }
      else{
        if(a[i-1]==1){
          if(s[i]=='o'){
            a[i+1]=2;
          }
          else{
            a[i+1]=1;
          }
        }
        else{
          if(s[i]=='o'){
            a[i+1]=1;
          }
          else{
            a[i+1]=2;
          }
        }
      }
    }
    if(a[n]==a[0]&&h==a[n-1]){
      g=1;
      break;
    }
  }
  if(g==1){
    for(int i=0;i<n;i++){
      if(a[i]==1) cout<<"S";
      else cout<<"W";
    }
  }
  else if(g==0)
    cout<<-1<<endl;
}
    