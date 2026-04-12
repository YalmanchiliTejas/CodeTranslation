#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int H,W;
  cin >> H >> W;
  
  vector<vector<char>> a(H,vector<char>(W));
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> a.at(i).at(j);
    }
  }
  
  bool finished=false;
  
  while(finished==false){
    finished=true;
    for(int i=0;i<H;i++){
      bool t=true;
      
      for(int j=0;j<W;j++){
        if(a.at(i).at(j)=='#'){
          t=false;
        }
      }
      
      if(t==true){
        for(int j=i;j<H-1;j++){
          for(int k=0;k<W;k++){
            a.at(j).at(k)=a.at(j+1).at(k);
          }
        }
        
        H--;
        finished=false;
      }
      
    }
    
    for(int i=0;i<W;i++){
      bool t=true;
      
      for(int j=0;j<H;j++){
        if(a.at(j).at(i)=='#'){
          t=false;
        }
      }
      
      if(t==true){
        for(int j=i;j<W-1;j++){
          for(int k=0;k<H;k++){
            a.at(k).at(j)=a.at(k).at(j+1);
          }
        }
        
        W--;
        finished=false;
      }
    }
  }
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout << a.at(i).at(j);
      if(j==W-1){
        cout << endl;
      }
    }
      
  }
  
}