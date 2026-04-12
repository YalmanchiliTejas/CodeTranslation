#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
using namespace std;

using ll = long long;
const int INF = 1001001001;

#define rep(i,n) for (int i = 0; i < (n); ++i)

vector<vector<int>> hen(9);
int cnt = 0;

void f(set<int> nokori, int now)
{
  if (nokori.empty()) {
    cnt++;
    return; 
  }
  for (int x : hen[now]) {
    auto it = nokori.find(x);
    if (it != nokori.end()) {
      set<int> nkr = nokori;
      auto itr = nkr.find(x);
      nkr.erase(*itr);
      f(nkr, *itr);
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    hen[a].push_back(b);
    hen[b].push_back(a);
  }

  set<int> tyouten;
  for (int i = 2; i <= n; i++) {
    tyouten.insert(i);
  }
  f(tyouten, 1);

  cout << cnt << endl;
}
