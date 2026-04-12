#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  char c;
  const char vowels[] = "aiueo";
  cin >> c;
  bool isVowel = find(vowels, vowels + 5, c) < (vowels + 5);

  cout << (isVowel ? "vowel" : "consonant") << endl;
}
