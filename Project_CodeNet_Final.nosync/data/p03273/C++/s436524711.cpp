#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W,i,j;
  cin>>H>>W;
  vector<string> s(H);
  for(i=0;i<H;i++){
    cin>>s[i];
  }
  vector<bool> c(H,false),r(W,false);
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      if(s[i][j]=='#') 
      c[i]=r[j]=true;
    }
  }
  for(i=0;i<H;i++){
    if(c[i]==true){
      for(j=0;j<W;j++){
        if(r[j]==true){
          cout<<s[i][j];
        }
      }
      cout<<endl;
    }
  }
}
