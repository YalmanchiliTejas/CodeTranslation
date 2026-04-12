#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  string s[50];
  int a[26] = {0};

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int j = 0; j < s[0].size(); j++) {
    a[s[0][j] - 'a']++;
  }
  for (int i = 1; i < n; i++) {
    int tmp[26] = {0};
    for (int j = 0; j < s[i].size(); j++) {
      tmp[s[i][j] - 'a']++;
    }
    for (int k = 0; k < 26; k++) {
      if (tmp[k] < a[k]) {
        a[k] = tmp[k];
      }
    }
  }

  for (int k = 0; k < 26; k++) {
    for (int l = 0; l < a[k]; l++) {
      cout << (char)('a' + k);
    }
  }
  cout << endl;
}
