#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W,cnt=0;
  cin>>H>>W;
  for(int i=0;i<H*W;i++){
    char c;
    cin>>c;
    if(c=='#')cnt++;
  }
  if(cnt==H+W-1)puts("Possible");
  else puts("Impossible");
}