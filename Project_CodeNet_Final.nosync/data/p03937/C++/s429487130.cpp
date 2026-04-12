#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W,s=1;cin>>H>>W;char x;
  for(int i=0;i<H*W;i++){
    cin>>x;if(x=='#')s++;
  }
  if(s==H+W)cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}