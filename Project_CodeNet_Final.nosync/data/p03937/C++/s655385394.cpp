#include<bits/stdc++.h>
using namespace std;
int main(){
int H,W;
  cin>>H>>W;
  vector<vector<char>>A(H+2,vector<char>(W+2,'.'));
  A.at(0).at(1)='#';
  A.at(H+1).at(W)='#';
  for(int i=1;i<=H;i++){
    string s;
    cin>>s;
  for(int j=1;j<=W;j++)
    A.at(i).at(j)=s.at(j-1);
  }
  vector<vector<int>>B(H+2,vector<int>(W+2,2));
  for(int i=1;i<=H;i++){
  for(int j=1;j<=W;j++){
  if(A.at(i).at(j)=='.')
    B.at(i).at(j)=2;
    else{
    int a=0;
      if((A.at(i-1).at(j)=='#' && A.at(i).at(j-1)=='.')||
         (A.at(i-1).at(j)=='.' && A.at(i).at(j-1)=='#'))
        a++;
      if((A.at(i+1).at(j)=='#' && A.at(i).at(j+1)=='.')||
         (A.at(i+1).at(j)=='.' && A.at(i).at(j+1)=='#'))
      a++;
      B.at(i).at(j)=a;
    
    }
  }
  }bool x=true;
  for(int i=1;i<=H;i++){
  for(int j=1;j<=W;j++)
    if(B.at(i).at(j)!=2){x=false; break;}
  }if(x)
    cout<<"Possible"<<endl;
  else
    cout<<"Impossible"<<endl;
     return 0;
}
   
