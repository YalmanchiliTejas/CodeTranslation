#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  int n;
  cin >> n;

  int c[n][26];

  for(int i = 0;i < n;i++) {
    for(int j = 0;j < 26;j++) {
      c[i][j] = 0;
    }
  }

  for(int i = 0;i < n;i++) {
    string S;
    cin >> S;
    for(int j = 0;j < S.size();j++) {
      int k = S.at(j) - 'a';
      c[i][k]++;
    }
  }

  string ans;
  for(int i = 0;i < 26;i++) {
    int mini = 100;
    for(int j = 0;j < n;j++) {
      mini = min(mini,c[j][i]);
    }

    for(int k = 0;k < mini;k++) {
      ans.push_back((char)(i + 'a'));
    }
  }

  cout << ans << endl;
  
}


