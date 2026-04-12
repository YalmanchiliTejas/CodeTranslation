#include <bits/stdc++.h>
#include <set>
#include <map> 

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++) 
#define ll long long
#define ld long double
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++) 
#define repvec(i, v) for(auto i = v.begin(); i != v.end(); ++i)

void calc(int n, int now, map<int, vector<int>>* tree, vector<int>vis, int& ans)
{
 
  auto list = (*tree)[now];
  vis.push_back(now);
  
    if(vis.size() == n)
  {
    ans++;
    return;
  }
  
  for(auto iter = list.begin(); iter != list.end(); ++iter)
  {
    int next = *iter;
    if(find(vis.begin(), vis.end(), next) != vis.end())
    {
      continue;
    }
    calc(n, next, tree, vis, ans);
  }
}

int main()
{
  int n,m;
  cin >> n >> m;
  
  map<int, vector<int>> tree;
  
  rep(i, m)
  {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  
  int ans = 0;
  vector<int> vis;
  calc(n, 1, &tree, vis, ans);
  
  cout << fixed << ans << endl;
  return 0;
}