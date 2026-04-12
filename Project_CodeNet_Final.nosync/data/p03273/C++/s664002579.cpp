#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W; cin>>H>>W;
  vector<vector<char>> data(H, vector<char>(W));
  for(int i=0; i<H; i++)for(int j=0; j<W; j++) cin>>data.at(i).at(j);
  
  for(int i=0; i<H; i++){
    bool check=false;
    for(int j=0; j<W; j++){
      if(data.at(i).at(j)=='.') check=true;
      else{
        check=false;
        break;
      }
    }
    if(check) for(int j=0; j<W; j++) data.at(i).at(j)='x';
    check=false;
  }
  
  for(int i=0; i<W; i++){
    bool check=false;
    for(int j=0; j<H; j++){
      if(data.at(j).at(i)=='.' || data.at(j).at(i)=='x') check=true;
      else{
        check=false;
        break;
      }
    }
    if(check==true) for(int j=0; j<H; j++) data.at(j).at(i)='x';
    check=false;
  }
  
  bool test=false;
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(data.at(i).at(j)=='x') continue;
      else{
        cout<<data.at(i).at(j);
        test=true;
      }
    }
    if(test){
      cout<<endl;
      test=false;
    }
  }
}
