#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int H,W;
  cin>>H>>W;
  
  vector<string> a(H);
  vector<bool> goodx(H,false);
  vector<bool> goody(W,false);
  
  for(int i=0;i<H;++i){
    cin>>a[i];
  }
  
  for(int i=0;i<H;++i){
    for(int j=0;j<W;++j){
      if(a[i][j]=='#'){
        goodx[i]=true;
        goody[j]=true;
      }
    }
  }
  
  for(int i=0;i<H;++i){
    if(goodx[i]){
      for(int j=0;j<W;++j){
        if(goody[j]){
          cout<<a[i][j];
        }
      }
      cout<<endl;
    }
    
  }
  
}
