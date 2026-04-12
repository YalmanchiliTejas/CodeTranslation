#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
int main() {
  char c;
  cin >> c;
  vector<char> vo = {'a','i','u','e','o'};
  bool flag = 1;
  for (int i=0; i<5; i++) {
    if (vo[i] == c) {
      cout << "vowel" << endl;
      flag = 0;
      break;
    }
  }
  if (flag) cout << "consonant" << endl;
} 