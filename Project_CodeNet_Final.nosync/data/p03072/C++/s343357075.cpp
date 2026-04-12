#include<iostream>
using namespace std;
int main(){
  int n,i,b,h=0,r=0;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>b;
    if(b>=h){
      h=b;
      r++;
    }
  }
  cout<<r<<endl;
  return 0;
}