#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define RFOR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define LL long long
#define INF INT_MAX/3

const double EPS = 1e-14;
const double PI  = acos(-1.0);


int n, m;
int ans = 0;
vector<vector<int> > v(9);

void solve(int num, vector<int> root) {
  if (int(root.size()) == n) {
    ans++;
    return;
  } 

  for (auto x : v[num]) {
    auto itr = find(root.begin(), root.end(), x);
    if (itr == root.end()) {
      root.push_back(x);
      solve(x, root);
      root.pop_back();
    }
  }
};

int main(){
  cin >> n >> m;

  int a, b;
  REP (i, m) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  vector<int> root;
  root.push_back(1);
  solve(1, root);
  cout << ans << endl;
}
