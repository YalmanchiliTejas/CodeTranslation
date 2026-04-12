#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000000007

int main(void)
{
  string str;
  cin >> str;

  if(str == "a" || str == "i" || str == "u" || str == "e" || str == "o")
    cout << "vowel" << endl;
  else cout << "consonant" << endl;
  return 0;
}