#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int mod = 1e9 + 7;

int main()
{
  char c;
  cin >> c;
  if(string("aeiou").find(c) != string::npos) cout << "vowel" << endl;
  else cout << "consonant" << endl;
}