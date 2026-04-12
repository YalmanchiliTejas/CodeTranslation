#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;

const ll mod = 1e9 + 7;

int n, m;
vector<int> e[10];
bool used[10];

int dfs(int x)
{
  if(used[x]) return 0;

  bool flag = true;
  for(int i = 1; i <= n; i++){
    if(i != x and !used[i]) flag = false;
  }
  if(flag) return 1;

  used[x] = true;
  
  int ret = 0;
  for(auto u : e[x]){
    ret += dfs(u); 
  }

  used[x] = false;

  return ret;
}

int main()
{
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;

    e[a].pb(b);
    e[b].pb(a);
  }

  cout << dfs(1) << endl;

  return 0;
}
