#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H,vector<char>(W));
  int t=0;
  
  for(int i=0;i<H;i++){
	for(int j=0;j<W;j++){
     	cin>>a.at(i).at(j);
    }
  }
  
  for(int i=0;i<H;i++){
   	for(int j=0;j<W;j++){
     	if(a.at(i).at(j)=='.'){
          if(j==W-1){
           	for(int k=0;k<W;k++){
             	a.at(i).at(k)=' ';
            }
          }
          else
         	continue; 
        }
      	else{
         	break; 
        }
    }
  }
  
   for(int j=0;j<W;j++){
   	for(int i=0;i<H;i++){
     	if(a.at(i).at(j)=='.'||a.at(i).at(j)==' '){
          if(i==H-1){
           	for(int k=0;k<H;k++){
             	a.at(k).at(j)=' ';
            }
          }
          else
         	continue; 
        }
      	else{
         	break; 
        }
    }
  }
  
  
   for(int i=0;i<H;i++){
     t=0;
   	for(int j=0;j<W;j++){
        if(a.at(i).at(j)!=' '){
     		cout<<a.at(i).at(j);
      		t=1;
        }
    }
     if(t==1){
      	cout<<endl;
     }
     else{
     }	
  }
    
    
}