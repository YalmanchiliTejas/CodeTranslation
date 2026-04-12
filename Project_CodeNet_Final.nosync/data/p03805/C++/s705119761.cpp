#include<bits/stdc++.h>
using namespace std;

const int nmax = 8;
vector<vector<bool>> routemap(nmax, vector<bool>(nmax, false));

int dfs(int n, int place, vector<bool>& visit)
{
  int i;
  bool allvisit = true;
  for(i = 1; i < n; i++)
  {
    if(visit.at(i) == false)
    {
      allvisit = false;
    }
  }
  if(allvisit == true) return 1;
  int result = 0;
  for(i = 1; i < n; i++)
  {
    if(visit.at(i) == false && routemap.at(place).at(i) == true)
    {
      visit.at(i) = true;
      result += dfs(n, i, visit);
      visit.at(i) = false;
    }
  }
  return result;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> b(m);
  int i, j;
  vector<bool> visit(n, false);
  for(i = 0; i < m; i++)
  {
    cin >> a.at(i);
    cin >> b.at(i);
  }
  for(i = 0; i < m; i++)
  {
    routemap.at(a.at(i)-1).at(b.at(i)-1) = true;
    routemap.at(b.at(i)-1).at(a.at(i)-1) = true;
  }
  cout << dfs(n, 0, visit) << endl;
} 