#include <bits/stdc++.h>
using namespace std;

#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define erep(i,j,n) for(int i=(j);i<=(n);i++)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define INF 1e9
const int mod = 1e9+7;

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef long long i64;

int n;
vi d;

bool func() {
  int MAX = 0;
  rep(i, 0, n) {
    if(MAX < i * 10) return false;
    MAX = max(MAX, i * 10 + d[i]);
  }
  return MAX >= (n - 1) * 10;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  d.resize(n);
  rep(i, 0, n) cin >> d[i];
  
  if(!func()) {
    cout << "no\n";
    return 0;
  }
  reverse(all(d));
  if(func()) cout << "yes\n";
  else cout << "no\n";
}

