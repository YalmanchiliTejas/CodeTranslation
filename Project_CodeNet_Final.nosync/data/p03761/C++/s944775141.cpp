#include <bits/stdc++.h>
using namespace std;

void chmin(int& a, int b) {
  if (a > b) a = b;
}

int main() {
  int N;
  cin >> N;
  
  vector<string> S(N);
  
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  
  int char_num[100][26] = {0};
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < S[i].size(); j++) {
      char_num[i][S[i][j] - 'a']++;
    }
  }
  
  
  int char_min[26];
  for (int i = 0; i < 26; i++) {
    char_min[i] = char_num[0][i];
  }
  
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < N; j++) {
      chmin(char_min[i], char_num[j][i]);
    }
  }
  
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < char_min[i]; j++) {
      cout << (char)(i +'a');
    }
  }
  cout << endl;
}