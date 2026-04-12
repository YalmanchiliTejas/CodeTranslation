#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
int parent[N];
int rnk[N];

int getParent(int x)
{
  if(parent[x] == x)
    return x;
  return parent[x] = getParent(parent[x]);
}

void connect(int x, int y)
{
  x = getParent(x), y = getParent(y);
  if(x == y)
    return;
  if(rnk[x] <= rnk[y])
  {
    parent[x] = y;
    rnk[y] += rnk[x];
  }
  else
  {
    parent[y] = x;
    rnk[x] += rnk[y];
  }
}

bool isconnected(int x, int y)
{
  return getParent(x) == getParent(y);
}

int main()
{
 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 int n;
 cin >> n;
 for(int i = 0; i < n; i++)
  parent[i] = i, rnk[i] = 1;
 vector<pair<int, int>> points(n);
 vector<pair<int, pair<int, int>>> dist;
 vector<pair<pair<int, int>, int>> sortx, sorty;
 for(auto &x: points)
 {
   cin >> x.first >> x.second;
 }
 for(int i = 0; i < n; i++)
 {
   sortx.push_back({points[i], i});
   sorty.push_back({{points[i].second, points[i].first}, i});
 }
 sort(sortx.begin(), sortx.end());
 sort(sorty.begin(), sorty.end());
 for(int i = 1; i < n; i++)
 {
   int dif = sortx[i].first.first - sortx[i - 1].first.first;
   dist.push_back({dif, {sortx[i].second, sortx[i - 1].second}});
   dif = sorty[i].first.first - sorty[i - 1].first.first;
   dist.push_back({dif, {sorty[i].second, sorty[i - 1].second}});
 }
 sort(dist.begin(), dist.end());
 ll ans = 0;
 for(auto &x: dist)
 {
   int firstNode = x.second.first, secondNode = x.second.second;
   if(isconnected(firstNode, secondNode))
    continue;
   ans += x.first;
   connect(firstNode, secondNode);
 }
 cout << ans;
 return 0;
}
