#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int H,W;
  cin>>H>>W;
  
  string a[110];
  bool goodx[110]={false};
  bool goody[110]={false};
  
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
