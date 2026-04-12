#include <bits/stdc++.h>
using namespace std;

int f(int n, int v, int count, vector<bool> &passed, vector< forward_list<int> > &side)
{
  if (count == n) return 1;
  
  int sum = 0;
  passed[v] = true;
  for (auto itr = side[v].begin(); itr != side[v].end(); ++itr)
    if (!passed[*itr]) sum += f(n, *itr, count+1, passed, side);
  passed[v] = false;
  
  return sum;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector< forward_list<int> > side(n);
  for (int i = 0; i < m; ++i)
  {
    int a, b; cin >> a >> b; --a; --b;
    side[a].push_front(b);
    side[b].push_front(a);
  }
  
  vector<bool> passed(n, false);
  passed[0] = true;
  cout << f(n, 0, 1, passed, side) << endl;
}