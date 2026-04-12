#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const long long INF = 1LL << 60;

string s;

int main()
{
  cin >> s;
  if(s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
  else cout << "Yes" << endl;
}