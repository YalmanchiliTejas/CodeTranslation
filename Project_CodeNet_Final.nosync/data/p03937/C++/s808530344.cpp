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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  int cou = 0;
  rep(i, 0, h) {
    string s;
    cin >> s;
    rep(j, 0, w) if(s[j] == '#') cou++;
  }
  if(cou == h + w - 1) cout << "Possible\n";
  else cout << "Impossible\n";
}
