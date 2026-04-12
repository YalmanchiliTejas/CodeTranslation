#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  string s;
  cin >> s;
  char before;
  before = s[0];
  bool isSame = true;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != before) isSame = false;
  }

  if (isSame) cout << "No" << endl;
  else cout << "Yes" << endl;
}

