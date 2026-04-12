#include <bits/stdc++.h>
using namespace std;
int main (){
  int H,W,n;
  cin>>H>>W;
  n=0;
  vector<vector<char>> vec(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>vec.at(i).at(j);
    }
  }
  for(int i=0;i<H;i++){
    n=0;
    for(int j=0;j<W;j++){
      if(vec.at(i).at(j)=='.'){
        n++;
      }
      if(n==W){
        for(int k=0;k<W;k++){
          vec.at(i).at(k)='0';
        }
      }
    }
  }
  for(int i=0;i<W;i++){
    n=0;
    for(int j=0;j<H;j++){
      if(vec.at(j).at(i)=='.'||vec.at(j).at(i)=='0'){
        n++;
      }
      if(n==H){
        for(int k=0;k<H;k++){
          vec.at(k).at(i)='0';
        }
      }
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(vec.at(i).at(j)!='0'){
        cout<<vec.at(i).at(j);
      }
      if(j==W-1){
        cout<<endl;
      }
    }
  }
}


