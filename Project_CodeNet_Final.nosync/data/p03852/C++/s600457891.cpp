#include <bits/stdc++.h>
using namespace std;
 
int main() {
  char s;
  cin >> s;
  string vowelStr = "aiueo";
  int compare = count(vowelStr.cbegin(), vowelStr.cend(), s);
  if(0 == compare)
  {
     cout << "consonant" << endl;
  }else
  {
     cout << "vowel" << endl;
  }
}