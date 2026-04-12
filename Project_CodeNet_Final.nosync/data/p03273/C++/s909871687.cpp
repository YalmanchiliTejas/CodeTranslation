#include <bits/stdc++.h>
using namespace std;

vector<string> transpose(vector<string> a){

  vector<string> ans(a.at(0).size());
  
  for (int i = 0; i < a.at(0).size(); i++){
    for (int j = 0; j < a.size(); j++){
      ans.at(i).push_back(a.at(j).at(i));
    }
  }

  return ans;
}

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

  vector<string> trans(0);
  trans=transpose(temp);

  vector<string> temp2(0);
  for (int i = 0; i < trans.size(); i++){
    if(trans.at(i).find('#')!=string::npos){
      temp2.push_back(trans.at(i));
    }
  }

  vector<string> ans(0);
  ans=transpose(temp2);
  
  for (int i = 0; i < ans.size(); i++){
    cout << ans.at(i) << endl;
  }

}