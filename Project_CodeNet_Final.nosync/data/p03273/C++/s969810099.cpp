#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin>>H>>W;
  vector<vector<char>> a(H,vector<char>(W));
  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++){
      cin>>a.at(i).at(j);
    }
  }
  vector<int> i_remove;
  vector<int> j_remove;
  
  for (int i=0; i<H; i++){
    bool flag=false;
    for (int j=0; j<W; j++){
      if (a.at(i).at(j)=='#'){
        flag=true;
      }
    }
    if (!flag){
      i_remove.push_back(i);
    }
  }
  
  for (int j=0; j<W; j++){
    bool flag=false;
    for (int i=0; i<H; i++){
      if (a.at(i).at(j)=='#'){
        flag=true;
      }
    }
    if (!flag){
      j_remove.push_back(j);
    }
  }

  for (int i=0; i<H; i++){
    bool flag_i=false;
    for (int j=0; j<W; j++){
      if ((find(i_remove.begin(),i_remove.end(),i)!=i_remove.end())||(find(j_remove.begin(),j_remove.end(),j)!=j_remove.end())){
      } else {
        cout<<a.at(i).at(j);
        flag_i=true;
      }
    }
    if (flag_i){
      cout<<endl;
    }
  }
}