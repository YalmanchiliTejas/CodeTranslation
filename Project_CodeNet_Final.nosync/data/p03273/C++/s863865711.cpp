#include <bits/stdc++.h>
using namespace std;

// 表を転置する
vector<vector<char>> transpose(vector<vector<char>>);

// '.'ばかりの行を消す
vector<vector<char>> delete_white_col(vector<vector<char>>);

int main() {
  int H, W;
  cin>>H>>W;
  
  vector<vector<char>> a(H, vector<char>(W));
  for(int i=0;i<H;i++){
    string s;
    cin >> s;
    for(int j=0;j<W;j++){
      a.at(i).at(j) = s.at(j);
    }
  }
  
  a = delete_white_col(a);
  a = transpose(a);
  a = delete_white_col(a);
  a = transpose(a);
  
  for(int i=0;i<a.size();i++){
    for(int j=0;j<a.at(0).size();j++){
      cout << a.at(i).at(j);
    }
    cout << endl;
  }
}

vector<vector<char>> transpose(vector<vector<char>> a){
  int H, W;
  H = a.size();
  W = a.at(0).size();
  
  vector<vector<char>> a1(W, vector<char>(H));
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      a1.at(j).at(i) = a.at(i).at(j);
    }
  }
  
  return a1;
}

vector<vector<char>> delete_white_col(vector<vector<char>> a){
  vector<vector<char>> a1;
  
  for(vector<char> vec : a){
    // vecに'#'が含まれている場合true
    bool flag = false;
    for(char x : vec){
      if(x=='#'){
        flag = true;
        break;
      }
    }
    if(flag){
      a1.push_back(vec);
    }
  }
  
  return a1;
}