#include <bits/stdc++.h>
#include <ios>
#include <iomanip>
using namespace std;

int main() {
  int H,W;
  cin>>H>>W;
  
  vector<char> a(H*W);
  for(int x=0;x<H*W;x++){
    cin>>a.at(x);
  }
  for(int n=0;n<H*W;n+=W){
    bool TF=1;
    for(int i=0;i<W;i++){
      if(a.at(i+n)=='#'){
        TF*=0;
      }
    }
    if(TF==1){
      for(int i=0;i<W;i++){
        a.at(i+n)=' ';
      }
    }
  }
  for(int m=0;m<W;m++){
    bool FT=1;
    for(int j=0;j<H*W;j+=W){
      if(a.at(j+m)=='#'){
        FT*=0;
      }
    }
    if(FT==1){
      for(int j=0;j<H*W;j+=W){
        a.at(j+m)=' ';
      }
    }
  }
  for(int l=0;l<H*W;l+=W){
    string c;
    bool empty=1;
    for(int k=0;k<W;k++){
      if(a.at(k+l)!=' '){
        c+=a.at(k+l);
        empty*=0;
      }
    }
    if(empty==0)
      cout<<c<<endl;
  }
}
