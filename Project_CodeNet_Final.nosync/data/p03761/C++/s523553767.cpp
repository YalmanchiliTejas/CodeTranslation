#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n; cin >> n;
  int SN[55][30] = {}; // n個の文字列それぞれのa～zを数える
  
  for (int i = 0; i < n; i++)
  {
    string S; cin >> S;
    
    for (int j = 0; j < S.length(); j++)
    {
      int k = S[j] - 'a';
      SN[i][k]++;
    }
  }
  
  string ans = "";
  for (int alpha = 0; alpha < 26; alpha++)
  {
    int len = 0;
    
    for (int i = 0; i < n; i++)
    {
      if (SN[i][alpha] == 0)
      {
        len = 0;
        break;
      }
      else if (SN[i][alpha] != 0 && len == 0)
      {
        len = SN[i][alpha];
      }
      else // SN[i][alpha] != 0 && len != 0
      {
        len = min(len, SN[i][alpha]);
      }
    }
    
    for (int l = 0; l < len; l++)
    {
      ans += 'a' + alpha;
    }
  }
  
  cout << ans << endl;
  return 0;
}