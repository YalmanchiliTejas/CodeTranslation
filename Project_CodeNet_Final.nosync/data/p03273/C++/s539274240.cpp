#include<bits/stdc++.h>
using namespace std;
int main(){
int H,W;
  cin>>H>>W;
  vector<vector<char>>A(H,vector<char>(W));
  for(int i=0;i<H;i++){
  string S;
    cin>>S;
    for(int j=0;j<W;j++)
      A.at(i).at(j)=S.at(j);
  
  }
  for(int i=0;i<H;i++){
  bool x=true;
    for(int j=0;j<W;j++){
  if(A[i][j]!='.'){
   x=false; break;
  }
  } if(x){
    for(int k=0;k<W;k++)
      A.at(i).at(k)='a';
    
    }
  
  }for(int i=0;i<W;i++){
  bool x=true;
    for(int j=0;j<H;j++){
  if(A[j][i]!='.' && A[j][i]!='a'){
   x=false; break;
  }
  } if(x){
    for(int k=0;k<H;k++)
      A.at(k).at(i)='a';
    
    }
  
  }for(int i=0;i<H;i++){
  for(int j=0;j<W-1;j++){
    if(A.at(i).at(j)!='a')cout<<A.at(i).at(j);
  }if(A.at(i).at(W-1)!='a')cout<<A.at(i).at(W-1)<<endl;
  else
    cout<<endl;
  }
  
  
 return 0;
}