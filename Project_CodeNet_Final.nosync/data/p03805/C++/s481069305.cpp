#include <bits/stdc++.h>


using namespace std;


// Powered by caide (code generator, tester, and library code inliner)


class Solution {
  int n, m;
  vector<int> edge[8];
public:
  int dfs(int now, int bits)
  {
    if (bits & 1 << now) return 0;
    bits |= 1 << now;
    if (bits + 1 == (1 << n)) return 1;
    int res = 0;
    for(auto&& i : edge[now]) {
      if (bits & 1 << i) { continue; }
      res += dfs(i, bits);
    }
    return res;
  }

  void solve(std::istream& in, std::ostream& out)
  {
    in >> n >> m;
    for(int i = 0; i < m; i++) {
      int a, b;
      in >> a >> b;
      edge[--a].push_back(--b);
      edge[b].push_back(a);
    }
    out << dfs(0, 0) << "\n";
    for(int i = 0; i < n; i++) {
      edge[i].clear();
    }
  }
};

void solve(std::istream& in, std::ostream& out)
{
  out << std::setprecision(12);
  Solution solution;
  solution.solve(in, out);
}


#include <fstream>
#include <iostream>


int main() {
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  istream& in = cin;


  ostream& out = cout;

  solve(in, out);
  return 0;
}


