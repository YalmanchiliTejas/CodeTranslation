#include <bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<vector<int>> data(26, vector<int> (N));
  string S;
  for(int i = 0; i < N; i++) {
    cin >> S;
    for(char a: S) {
      data.at(a - 'a').at(i)++;
    }
  }
  int minnum;
  char c;
  for(int i = 0; i < 26; i++) {
    minnum = 100;
    for(int j = 0; j < N; j++) {
      minnum = min(minnum, data.at(i).at(j));
    }
    for(int j = 0; j < minnum; j++) {
      c = i + 'a';
      cout << c;
    }
  }
  cout << endl;
  return 0;
}