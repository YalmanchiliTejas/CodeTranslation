#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> R(H,vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin>>R.at(i).at(j);
    }
  }
  for(int i=R.size()-1;i>=0;i--){
 	bool isallwhite=true;
    for(int j=0;j<R[0].size();j++){
      if(R.at(i).at(j)=='#')
        isallwhite=false;
    }
    if(isallwhite==true){
      R.erase(R.begin()+i);
    }
  }
  
  for(int i=R[0].size()-1;i>=0;i--){
 	bool isallwhite=true;
    for(int j=0;j<R.size();j++){
      if(R.at(j).at(i)=='#')
        isallwhite=false;
    }
    if(isallwhite==true){
      for(int j=0;j<R.size();j++)
        R[j].erase(R[j].begin()+i);
    }
  }
  
  for (int i = 0; i < R.size(); i++) {
    for (int j = 0; j < R[0].size(); j++) {
      cout<<R.at(i).at(j);
    }
    cout<<endl;
  }
  
}
