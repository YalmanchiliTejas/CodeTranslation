#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  
  vector<string> grid(h);
  for (int i = 0; i < h; i++){
    cin >> grid.at(i);
  }
  
  vector<string> temp(0);
  for (int i = 0; i < h; i++){
    if(grid.at(i).find('#')!=string::npos){
      temp.push_back(grid.at(i));
    }
  }

  vector<string> trans(w);
  for (int i = 0; i < w; i++){
    for (int j = 0; j < temp.size(); j++){
      trans.at(i).push_back(temp.at(j).at(i));
    }
  }

  vector<string> temp2(0);
  for (int i = 0; i < trans.size(); i++){
    if(trans.at(i).find('#')!=string::npos){
      temp2.push_back(trans.at(i));
    }
  }

  vector<string> ans(temp2.at(0).size());
  for (int i = 0; i < temp2.at(0).size(); i++){
    for (int j = 0; j < temp2.size(); j++){
      ans.at(i).push_back(temp2.at(j).at(i));
    }
  }
  
  for (int i = 0; i < ans.size(); i++){
    cout << ans.at(i) << endl;
  }

}