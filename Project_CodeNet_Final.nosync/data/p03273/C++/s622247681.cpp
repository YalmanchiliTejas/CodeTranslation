#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  //二次元配列の宣言
  vector<vector<char>> input(N, vector<char>(M));
  vector<vector<char>> result;
  for (auto &vec: input) {
    for (auto &ch: vec)
    {
      cin >> ch;
    }
  }

  // 表示する列を決定する
  vector<int> vecInt;
  for(int j = 0; j < M; j ++)
  {
    string tempStr;
    for(int i = 0; i < N; i ++)
    {
      if(input.at(i).at(j) == '#')
      {
        vecInt.push_back(j);		//表示する列を決定
        break;
      }
    }
  }
    
  for (auto &vec: input) {
    // 行に#があれば出力する。
    if(count(vec.begin(), vec.end(), '#') != 0 )
    {
      for(auto i: vecInt)
      {
        cout << vec.at(i);
      }
      cout << endl;
    }
  }
}
