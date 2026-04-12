#include<iostream>
using namespace std;

int main() {
  char c;
  cin >> c;

  char vowel[] = {'a', 'o', 'i', 'u', 'e'};

  bool flag = false;
  for(int i = 0; i < 5; ++i) {
    if (c == vowel[i])
      flag = true;
  }

  cout << (flag ? "vowel" : "consonant") << endl;;
}
