#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b=0;
  for(int i=0;i<12;i++){
    cin>>a;
    b^=a;
  }
  if(b==0)cout<<"yes"<<endl;
  else cout<<"no"<<endl;
  return 0;
}