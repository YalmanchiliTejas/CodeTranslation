#include <cstdio>
#include <iostream>
using namespace std;

int x[50][26];

int main(){
  string s[50];
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < s[i].size(); j++){
      x[i][s[i][j]-'a']++;
    }
  }
  for (int i = 0; i < 26; i++) {
    int mi = x[0][i];
    for (int j = 0; j < n; j++) {
      mi = min(mi, x[j][i]);
    }
    for (int k = 0; k < mi; k++) {
      printf("%c", i+'a');
    }
  }
  printf("\n");
  return 0;
}
