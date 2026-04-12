#include <bits/stdc++.h>
using namespace std;


  
    
  void show(vector<vector<char>> vct){
  for(int i=0;i<vct.size();i++){
      for(int l=0;l<vct[0].size();l++){
            cout<<vct[i][l];
      }
      cout <<endl;
  }
  }  
  

 
int main() {
  
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<vector<char>> vct(n,vector<char>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)  {
        cin>>vct[i][j];
    }
  }
 
  
  for(int i=0;i<vct.size();i++){
      for(int j=0;j<vct[i].size();j++){
          if(vct[i][j]!='.'){
              break;
          }
          if(j==vct[i].size()-1){
            vct.erase(vct.begin() + i);
            i--;
          }
      }
  }
  for(int i=0;i<vct[0].size();i++){
      for(int j=0;j<vct.size();j++){
          if(vct[j][i]!='.'){
              break;
          }
          if(j==vct.size()-1){
             for(int k=0;k<vct.size();k++){
               vct[k].erase(vct[k].begin() + i);  
             }
             i--;
          } 
          
      }
  }
   show(vct);            
              
           
            

  }
 