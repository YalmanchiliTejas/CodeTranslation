#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()
using namespace std;

bool is_white_line(vector<char> &vec){
  int count = 0;
  rep(i, vec.size()){
    if (vec.at(i) == '.') count++;
  }
  if (count == vec.size()) return true;
  else return false;
}
bool is_white_row(vector<vector<char>> &vec, int i){
  int count = 0;
  rep(j, vec.size()){
    if (vec.at(j).at(i) == '.') count++;
  }
  if (count == vec.size()) return true;
  else return false;
}
int main(){
  int a, b;
  cin >> a >> b;
  vector<vector<char>> plane(a, vector<char>(b));
  rep(i, a){
    rep(j, b) cin >> plane.at(i).at(j);
  }
  vector<int> el;
  rep(i, a){
    if (is_white_line(plane.at(i))){
      el.push_back(i);
    }
  }
  rep(i, el.size()) plane.erase(plane.begin() + el.at(i) - i);
  vector<int> er;
  rep(i, b){
    if (is_white_row(plane, i)){
      er.push_back(i);
    }
  }
  rep(i, er.size()){
    rep(j, plane.size()) plane.at(j).erase(plane.at(j).begin() + er.at(i) - i);
  }
  rep(i, plane.size()){
    rep(j, plane.at(i).size()){
      cout << plane.at(i).at(j);
    }
    cout << endl;
  }
}