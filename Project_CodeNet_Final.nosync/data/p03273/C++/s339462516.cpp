#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin>>H>>W;
  vector<string> grid(H);
  for(int i=0;i<H;i++){
    cin>> grid[i];
  }
 vector<bool> a(H,false);
 vector<bool> b(W,false);
 for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(grid[i][j]=='#'){
        a[i]=true;
        b[j]=true;
         }
      }
    }
  
  
  for(int i=0;i<H;i++){
    if(a[i]){
      for(int j=0;j<W;j++){
        
          if(b[j]){
            cout<<grid[i][j];
        }
      }
      cout<<endl;
    }
      
    
  }
}



