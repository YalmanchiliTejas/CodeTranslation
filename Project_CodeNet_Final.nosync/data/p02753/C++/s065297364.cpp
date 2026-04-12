#include <bits/stdc++.h>
using namespace std;

#define DEBUG(X) if(X)
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

int main()
{
  FASTIO;
  string str;
  cin >> str;
  if(str[0] == str[1] && str[1] == str[2])
    cout << "No\n";
  else
    cout << "Yes\n";
  return 0;
}
