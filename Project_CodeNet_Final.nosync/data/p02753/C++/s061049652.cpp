#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,n) for(int i=0; i < n; i++)
#define ALL(n) begin(n), end(n)

string s, ans;

int main()
{
  cin >> s;
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());

  if(s.size() == 1) ans = "No";
  else ans = "Yes";

  cout << ans << endl;
}