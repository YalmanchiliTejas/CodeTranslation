#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> masu(H,vector<char>(W));
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> masu.at(i).at(j);
    }
  }
  
  for(int i=0;i<masu.size();i++){
    int j=0;
    while(masu.at(i).at(j) == '.'){
      if(j == masu.at(i).size()-1){
        for(int k=i;k < masu.size()-1;k++){
          for(int l=0;l<masu.at(k).size();l++){
            masu.at(k).at(l) = masu.at(k+1).at(l);
          }
        }
        masu.pop_back();
        i--;
        break;
      }else{
        j++;
      }
    }
  }
  for(int i=0;i<masu.at(0).size();i++){
    int j=0;
    while(masu.at(j).at(i) == '.'){
      if(j == masu.size()-1){
        for(int k=0;k<masu.size();k++){
          for(int l=i;l < masu.at(k).size()-1;l++){
            masu.at(k).at(l) = masu.at(k).at(l+1);
          }
          masu.at(k).pop_back();
        }
        i--;
        break;
      }else{
        j++;
      }
    }
  }
  for(int i=0;i<masu.size();i++){
    for(int j=0;j<masu.at(i).size();j++){
      cout << masu.at(i).at(j);
    }
    cout << endl;
  }
}
