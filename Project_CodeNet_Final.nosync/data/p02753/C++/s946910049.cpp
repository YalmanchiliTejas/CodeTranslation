#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;
const string yes = "Yes";
const string no = "No";

int main()
{
  string s;
  cin >> s;
  if(s[0]==s[1]&&s[1]==s[2]) cout << no << endl;
  else cout << yes << endl;

  return 0;
}
