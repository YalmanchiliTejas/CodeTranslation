#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int K;
  cin >> s >> K;
  long long ans = 0;
  vector<vector<bool>> notZero(s.size(), vector<bool>(s.size()));
  if(s.size() < K) {
    cout << 0 << endl;
    return 0;
  }
  for(int i=0;i<s.size();i++) {
    if(s[i] != '0') notZero[i][i] = true;
    for(int j=i+1;j<s.size();j++) {
      if(notZero[i][j-1]) notZero[i][j] = true;
      else if(s[j] != '0') notZero[i][j] = true;
    }
  }
  if(K == 1) {
    for(int i=0;i<s.size();i++) {
      if(i == 0) ans += s[i] - '0';
      else ans += 9;
    }
  }
  else if(K == 2) {
    for(int i=0;i<s.size();i++) {
      int digit_i = s[i] - '0';
      for(int j=i+1;j<s.size();j++) {
        int digit_j = s[j] - '0';
        if(i == 0) {
          if(j == 1) ans += digit_j + (digit_i-1) * 9;
          else if(notZero[i+1][j-1]) ans += digit_i * 9;
          else ans += digit_j + (digit_i-1) * 9;
        }
        else ans += 81;
      }
    }
  }
  else if(K == 3) {
    for(int i=0;i<s.size();i++) {
      int digit_i = s[i] - '0';
      for(int j=i+1;j<s.size();j++) {
        int digit_j = s[j] - '0';
        for(int k=j+1;k<s.size();k++) {
          int digit_k = s[k] - '0';
          int alt;
          if(digit_j == 0) alt = 0;
          else alt = (digit_k + (digit_j-1) * 9) + (digit_i-1) * 9 * 9;
          if(i == 0) {
            if(j == 1) {
              if(k == 2) ans += alt;
              else if(notZero[j+1][k-1]) ans += digit_j * 9 + (digit_i-1) * 9 * 9;
              else ans += alt;
            }
            else if(notZero[i+1][j-1]) ans += digit_i * 9 * 9;
            else {
              if(k == j+1) ans += alt;
              else if(notZero[j+1][k-1]) ans += digit_j * 9 + (digit_i-1) * 9 * 9;
              else ans += alt;
            }
          }
          else ans += 729;
        }
      }
    }
  }

  cout << ans << endl;
}