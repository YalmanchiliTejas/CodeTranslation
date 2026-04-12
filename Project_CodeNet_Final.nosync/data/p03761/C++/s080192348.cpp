#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  vector<int> alphabet_min_count(26, 55);
  rep(i, n)
  {
    string S;
    cin >> S;
    vector<int> alphabet_count(26, 0);
    rep(j, S.size())
    {
      alphabet_count[S[j] - 'a']++;
    }

    rep(j, 26)
    {
      alphabet_min_count[j] = min(alphabet_min_count[j], alphabet_count[j]);
    }
  }

  rep(i, 26)
  {
    char c = 'a' + i;
    rep(j, alphabet_min_count[i])
    {
      cout << c;
    }
  }
  cout << endl;
  return 0;
}