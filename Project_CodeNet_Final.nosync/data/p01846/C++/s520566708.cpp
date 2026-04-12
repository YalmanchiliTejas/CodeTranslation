#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> conv1(string S){
  int N = S.size();
  vector<vector<char>> A(1);
  for (int i = 0; i < N; i++){
    if (S[i] == '/'){
      A.push_back(vector<char>());
    } else if (S[i] == 'b'){
      A.back().push_back('b');
    } else {
      int cnt = S[i] - '0';
      for (int j = 0; j < cnt; j++){
        A.back().push_back('.');
      }
    }
  }
  return A;
}
string conv2(vector<vector<char>> A){
  int H = A.size();
  int W = A[0].size();
  string S;
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (A[i][j] == 'b'){
        S += 'b';
      } else {
        if (j == 0){
          S += '1';
        } else if (A[i][j - 1] == 'b'){
          S += '1';
        } else {
          S.back()++;
        }
      }
    }
    if (i < H - 1){
      S += '/';
    }
  }
  return S;
}
int main(){
  while (1){
    string S;
    cin >> S;
    if (S == "#"){
      break;
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<vector<char>> A = conv1(S);
    A[a - 1][b - 1] = '.';
    A[c - 1][d - 1] = 'b';
    cout << conv2(A) << endl;
  }
}
