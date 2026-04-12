#include<iostream>
using namespace std;
int main(){
  int n;cin>>n;
  int m[10],count=0,M;
  for(int i=0;i<n;i++){
    cin>>m[i];
    if(i==0)M=m[0];
    if(i>=1){
      if(m[i]>=M){M=m[i];count++;
                 }else continue;
             }
  }
  cout<<count+1;
}