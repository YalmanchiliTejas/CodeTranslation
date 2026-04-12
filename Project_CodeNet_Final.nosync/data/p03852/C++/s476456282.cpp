#include<iostream>
using namespace std;
int main() {
  char c;
  string str = "aiueo";
  int aws = 0;
  cin >> c;
  for (int i = 0; i < str.size(); i++) {
    if (str.at(i) != c) {
      aws++;
    }
  }
  if (aws != str.size()) {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }
}