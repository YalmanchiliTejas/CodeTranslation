#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  scanf("%c", &c);
  const string vowel = "aeiou";
  printf("%s", vowel.find(c) != string::npos ? "vowel" : "consonant");
  return 0;
}

