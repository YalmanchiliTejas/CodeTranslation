#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int e[12],count=0;
  for(int i=0;i<12;i++){
    cin>>e[i];
  }
  sort(e,e+12);
  for(int i=0;i<12;i+=4){
    if(e[i]==e[i+3]){
      count++;
    }
  }
  if(count==3){
    cout<<"yes"<<"\n";
  }else{
    cout<<"no"<<"\n";
  }
  return 0;
}

