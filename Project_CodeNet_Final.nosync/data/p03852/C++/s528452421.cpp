#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<char> vow = {'a','i','u','e','o'};
  int length = S.size();
  int flag = 0;
  for (int i = 0;i < length;i++){
    for (int j = 0;j<5;j++){
      if (vow[j] == S.at(i)){
        flag = 1;
        break;
      }
    }
    if (flag == 1) break;
  }
  if (flag == 1) cout << "vowel" << endl;
  else cout << "consonant" << endl;
}