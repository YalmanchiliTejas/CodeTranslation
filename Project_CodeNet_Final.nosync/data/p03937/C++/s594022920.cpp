#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W; cin>>H>>W;
  vector<vector<char>>A(H+2,vector<char>(W+2,'.'));
  for(int i=1;i<H+1;i++){
    string S; cin>>S;
    for(int j=1;j<W+1;j++)A[i][j]=S.at(j-1);
  }
  int a=1,b=1;
  for(int i=0;i<H+W-2;i++){
    if((A[a+1][b]=='#'&&A[a][b+1]=='#')||(A[a-1][b]=='#'&&A[a][b-1]=='#')){cout<<"Impossible"<<endl;return 0;}
    else if(A[a+1][b]=='#'){a++;continue;}
    else if(A[a][b+1]=='#'){b++;continue;}
    cout<<"Impossible"<<endl;
    return 0;
  }
  if(A[a-1][b]=='#'&&A[a][b-1]=='#'){cout<<"Impossible"<<endl; return 0;}
  cout<<"Possible"<<endl;
}