#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin>>H>>W;
  
  vector<vector<char>> date(H,vector<char>(W));
   
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>date.at(i).at(j);
  }
  }
 
  vector<bool> h(H, false);
  vector<bool> w(W, false);
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(date.at(i).at(j)=='#'){
        h.at(i)=true;
        w.at(j)=true;
      }
    }
  }
    
    for(int i=0;i<H;i++){
      if(h.at(i)){
      for(int j=0;j<W;j++){
if(w.at(j)){
  cout<<date.at(i).at(j);
}
      }
      cout<<endl;
    }
  }
  
  }
  
  
  