#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
 
int main()
{
  string s;
  cin >> s;
  if(s[0] == 'a' || s[0] == 'i' || s[0] == 'u' || s[0] == 'e' || s[0] == 'o')
    cout << "vowel" << endl;
  else cout << "consonant" << endl;
  return 0;
}
