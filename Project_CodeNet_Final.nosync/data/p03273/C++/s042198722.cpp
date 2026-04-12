#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >>H >>W;
  string a[H];
  for(int i=0;i<H;i++){
    cin >> a[i];
  }
  int h[H];
  int w[W];
  for(int i=0;i<H;i++){
    h[i]=0;
    for(int j=0;j<W;j++){
      if(a[i].at(j)=='#'){
        h[i]=1;
      }
    }
  }
  for(int i=0;i<W;i++){
    w[i]=0;
    for(int j=0;j<H;j++){
      if(a[j].at(i)=='#'){
        w[i]=1;
      }
    }
  }
  for(int i=0;i<H;i++){
    if(h[i]==1){
      for(int j=0;j<W;j++){
      if(w[j]==1){
        cout<<a[i].at(j);
      }
      }
       cout << endl;
    }
  }
}
    
    
        
  
