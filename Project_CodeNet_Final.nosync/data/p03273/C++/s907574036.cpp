#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin>>H>>W;
  vector<vector<char>> vec(H,vector<char>(W));
  for (int i=0;i<H;i++){
    for (int j=0;j<W;j++){
      cin>>vec.at(i).at(j);
    }
  }
  
  vector<int> space;
  
  for (int i=0;i<H;i++){
    bool judge=true;
    for(int j=0;j<W;j++){
      if (vec.at(i).at(j)=='#'){
        judge=false;
        break;
      }
    }
    if(judge){
      space.push_back(i);
      for(int j=0;j<W;j++){
        vec.at(i).at(j)='0';
      }
    }
  }
  space.push_back(-1);
  
  for (int j=0;j<W;j++){
    bool judge=true;
    for(int i=0;i<H;i++){
      if (vec.at(i).at(j)=='#'){
        judge=false;
        break;
      }
    }
    if(judge){
      for(int i=0;i<H;i++){
        vec.at(i).at(j)='0';
      }
    }
  }
  
  //test
  //for(int k=0;k<space.size();k++){
  //  cout<<space.at(k);
  //}
  //cout<<endl;
  
  int skip,x=0;
  skip=space.at(x);
  
  for (int i=0;i<H;i++){
    if(i==space.at(x)){
      x++;
    }
    else{
      for (int j=0;j<W;j++){
        if(vec.at(i).at(j)!='0'){
          cout<<vec.at(i).at(j);
        }
      }
    cout<<endl;
    }
  }
}

