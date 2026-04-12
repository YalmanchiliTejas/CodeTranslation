#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W,count=0;cin>>H>>W;
  char a;
  for(int i=0;i<H*W;i++){
    cin>>a;
    if(a=='#')count++;
  }
  if(count==H+W-1)cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}