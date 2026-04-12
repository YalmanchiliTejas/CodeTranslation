#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool PN(T x)
{
  if (x <= 1)
    return false;
  if (x == 2)
    return true;
  for (int i = 2; i < sqrt(x) + 1; i++)
    if (x % i == 0)
      return false;
  return true;
}

void solve()
{
  int n; cin >> n;
  int letter[n][26] ={};
  for(int i = 0; i < n; ++i){
    string s; cin >> s;
    for(int j = 0; j < s.size(); ++j){
      letter[i][s[j]-'a']++;
    }
  }
  string ans;
  for(int i = 0; i < 26; ++i){
    int mm = 100;
    for(int j = 0; j < n; ++j){
      if(mm > letter[j][i]) mm = letter[j][i];
    }
    // cout << "i: " << i << " ,mm:" << mm << endl;
    char ch = 'a' + i;
    for(int k = 0; k < mm; ++k){
      ans += ch;
    }
  }
  cout << ans << endl;
}

int main()
{
  solve();
  return 0;
}