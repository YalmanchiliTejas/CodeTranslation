#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define pii pair<int, int>
#define Task "abc"
#define For(i, a, b) for(int i = (a), _b = (b); i <= b; ++i)
#define Debug(X) cout << #X << " = " << X << '\n'
#define All(x) (x).begin(), (x).end()
#define mp make_pair

typedef unsigned long long ull;
typedef long long ll;

const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
//  freopen(Task".inp", "r", stdin);
//  freopen(Task".out", "w", stdout);
  string s;
  cin >> s;
  map<char,int> m;
  for (auto c : s) m[c]++;
  if ((int)m.size() == 2) cout << "Yes";
  else cout << "No";

}

