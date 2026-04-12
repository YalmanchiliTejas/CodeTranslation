#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string S[51];
  for (int i = 0; i < n; i++) cin >> S[i];
  
  int INF = 1e5;
  vector<int> A(26);
  for (char c = 'a'; c <= 'z'; c++) {
    int cnt = 100000;
    for (int i = 0; i < n; i++) {
      int tmp = 0;
      for (int j = 0; j < S[i].length(); j++) {
        if (S[i][j] == c) tmp++;
      }
      cnt = min(tmp, cnt);
    }
    int k = c - 'a';
    A[k] = cnt;
  }
  
  string ans = "";
  for (int i = 0; i < 26; i++) {  
    int c = 'a' + i;
    for (int j = 0; j < A[i]; j++) {
      ans += c;
    }
  }
  cout << ans << endl;
}
