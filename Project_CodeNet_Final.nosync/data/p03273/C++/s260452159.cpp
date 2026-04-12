#include <bits/stdc++.h>
using namespace std;
main() {
  int H,W,i,j;
  cin>>H>>W;
  vector<vector<char>>S(H,vector<char>(W));
  for(i=0;i<H;i++)for(j=0;j<W;j++)cin>>S.at(i).at(j);
  for(i=0;i<H;i++){
    for(j=0;j<W;j++)if(S.at(i).at(j)=='#')break;
    if(j==W)for(j=0;j<W;j++)S.at(i).at(j)='-';
  }
  for(i=0;i<W;i++){
    for(j=0;j<H;j++)if(S.at(j).at(i)=='#')break;
    if(j==H)for(j=0;j<H;j++)S.at(j).at(i)='-';
  }
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      if(S.at(i).at(j)!='-'){
        cout<<S.at(i).at(j);
      }
    }
    for(j=0;j<W;j++)if(S.at(i).at(j)=='#')break;
    if(j!=W)cout<<endl;
  }
}