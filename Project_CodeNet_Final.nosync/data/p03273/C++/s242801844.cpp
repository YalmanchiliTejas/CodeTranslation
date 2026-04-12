#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin>>H>>W;
  vector<vector<char>> vec(H,vector<char>(W));
  vector<int> flagW(W,0);
  int  flagH=0;
  
  for(int i=0;i<H;i++){
    flagH=0;
    for(int j=0;j<W;j++){
      cin>>vec.at(i).at(j);
      if(vec.at(i).at(j)=='#'){
        flagW.at(j)=1;
        flagH=1;
      }
    }
    if(flagH==0){
        i--;
        H--;
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(flagW.at(j)==1)
        cout<<vec.at(i).at(j);
    }
    cout<<endl;
  }
}