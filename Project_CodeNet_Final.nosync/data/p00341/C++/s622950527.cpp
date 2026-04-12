#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  
  int e, cnt[110]={};

  for(int i=0;i<12;i++){
    cin>>e;
    cnt[e]++;
  }

  for(int i=1;i<=100;i++){
    if(cnt[i]%4){
      cout<<"no"<<endl;
      return 0;
    }
  }

  cout<<"yes"<<endl;
  
  return 0;
}