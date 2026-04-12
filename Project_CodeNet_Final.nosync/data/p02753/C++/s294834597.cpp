#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int main()
{
  string S;
  cin >> S;
  int s_len = count(S.begin(), S.end(), 'A');
  if (s_len == S.size() || s_len == 0)
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }
}
