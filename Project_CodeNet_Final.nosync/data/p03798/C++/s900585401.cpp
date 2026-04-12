#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<int> num;
bool flag;

void init(){
  for(int i=0;i<n;i++){
    num[i]=-1;
  }
}

void calc(){
  for(int i=1;i<n;i++){
    if(s[i]=='o'){
      if(num[i]==0){
        if(i==n-2){
          if(num[n-1]!=num[n-3]) return ;
        }
        if(i+1!=n) num[i+1]=num[i-1];
        else{
          if(num[0]==num[n-2]){
            for(int j=0;j<n;j++){
              if(num[j]==0){
                cout<<'S';
              }else{
                cout<<'W';
              }
            }
            cout<<endl;
            flag=true;
          }
        }
      }else{
        if(i==n-2){
          if(num[n-1]==num[n-3]) return;
        }
        if(i+1!=n){
          if(num[i-1]==0) num[i+1]=1;
          else num[i+1]=0;
        }else{
          if(num[0]!=num[n-2]){
            for(int j=0;j<n;j++){
              if(num[j]==0){
                cout<<'S';
              }else{
                cout<<'W';
              }
            }
            cout<<endl;
            flag=true;
          }
        }
      }
    }
    
    else{
      if(num[i]==1){
        if(i==n-2){
          if(num[n-1]!=num[n-3]) return;
        }
        if(i+1!=n) num[i+1]=num[i-1];
        else{
          if(num[0]==num[n-2]){
            for(int j=0;j<n;j++){
              if(num[j]==0){
                cout<<'S';
              }else{
                cout<<'W';
              }
            }
            cout<<endl;
            flag=true;
          }
        }
      }else{
        if(n-2==i){
          if(num[n-1]==num[n-3]) return ;
        }
        if(i+1!=n){
          if(num[i-1]==0) num[i+1]=1;
          else num[i+1]=0;
        }else{
          if(num[0]!=num[n-2]){
            for(int j=0;j<n;j++){
              if(num[j]==0){
                cout<<'S';
              }else{
                cout<<'W';
              }
            }
            cout<<endl;
            flag=true;
          }
        }
      }
    }
  }
}

int main(){
  cin>>n>>s;
  num.resize(n,-1);
  num[0]=0;
  flag=false;
  if(s[0]=='o'){
    num[1]=0; num[n-1]=0;
  }else{
    num[1]=0; num[n-1]=1;
  }
  calc();
  if(flag) return 0;
  init();
  num[0]=0;
  if(s[0]=='o'){
    num[n-1]=1; num[1]=1;
  }else{
    num[n-1]=0; num[1]=1;
  }
  calc();
  if(flag) return 0;
  init();
  num[0]=1;
  if(s[0]=='o'){
    num[1]=1; num[n-1]=0;
  }else{
    num[1]=0; num[n-1]=0;
  }
  calc();
  if(flag) return 0;
  init();
  num[0]=1;
  if(s[0]=='o'){
    num[1]=0; num[n-1]=1;
  }else{
    num[1]=1; num[n-1]=1;
  }
  calc();
  if(flag) return 0;
  cout<<-1<<endl;
}