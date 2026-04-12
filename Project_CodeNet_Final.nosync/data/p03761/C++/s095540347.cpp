#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  vector<vector<int>> data(N, vector<int>(26,0));
 
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    for (int j = 0; j < S.size(); j++) {
      int M = S.at(j) - '0';
      data.at(i).at(M-49)++;
    }
  }
  
  vector<int>A(26);
  for (int i = 0; i < 26; i++) {
    int MIN = 50;
    for (int j = 0; j < N; j++) {
      if (MIN > data.at(j).at(i)){
        MIN = data.at(j).at(i);
      }
      if (j == N-1){
        A.at(i) = MIN;
      }
    }
    for (int k = 0; k < A.at(i); k++) {
      printf("%c", i + 'a');
    }
  }
  cout << endl;
}
  