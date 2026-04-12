#include <bits/stdc++.h>

using namespace std;

#define INF (1ll << 62)
#define eb emplace_back
#define ii pair<int,int>
#define OK (cerr <<"OK"<< endl)
#define debug(x) cerr << #x " = " << (x) << endl
#define ff first
#define ss second
#define int long long
#define tt tuple<int, int, int>
#define all(x) x.begin(), x.end()
#define Matrix vector<vector<int>>
#define Mat(n, m, v) vector<vector<int>>(n, vector<int>(m, v))
#define endl '\n'
const int MOD = 1e9 + 7;

signed main () {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;

  cin >> s;

  set<char> ss;
  for(char c: s) {
    ss.insert(c);
  }

  if(ss.size() > 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

}