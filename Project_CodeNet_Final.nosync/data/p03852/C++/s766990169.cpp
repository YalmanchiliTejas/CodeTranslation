#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define all(a) a.begin(), a.end()
#define ll long long
#define mod 1e9+7

using namespace std;

int main()
{
  char c;
  cin >> c;
  switch (c) {
    case 'a':
    case 'i':
    case 'u':
    case 'e':
    case 'o':
      cout << "vowel" << endl; break;
    default:
      cout << "consonant" << endl; break;
  }
}
