#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int N = 1e5 + 5;

vector <int> ed[N];
int n;

int f(int cur,int back) {
  int cnt = 0;
  for (auto i : ed[cur]) {
    if (i != back)
      cnt += f(i,cur);
  }
  if (cnt > 1) {
    cout << "First\n";
    exit(0);
  }
  return !cnt; 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1 ; i < n ; i++) {
    int u,v;
    cin >> u >> v;
    ed[u].push_back(v);
    ed[v].push_back(u);
  }
  if (n == 2) {
    cout << "Second\n";
    return 0;
  }
  int root = 1;
  for (int i = 1 ; i <= n ; i++)
    if (ed[i].size() != 1)
      root = i;
  f(root,-1);
  cout << "Second\n";
}