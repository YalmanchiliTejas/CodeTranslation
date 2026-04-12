#include <iostream>
#include <vector>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int N, M;
vector< vector<int> > nodes;

bool contain(const vector<int> &v, int n)
{
  rep(i, v.size()) {
    if(v[i] == n) return true;
  }
  return false;
}

int dfs(int n, vector<int> *visited)
{
  if(visited->size() == N - 1) return 1;
  visited->push_back(n);
  vector<int> ns = nodes[n];
  int sum = 0;
  rep(i, ns.size()) {
    if(!contain(*visited, ns[i]))
      sum += dfs(ns[i], visited);
  }
  visited->pop_back();
  return sum;
}

int main()
{
  cin >> N >> M;

  nodes.resize(N);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    nodes[a].push_back(b);
    nodes[b].push_back(a);
  }

  cout << dfs(0, new vector<int>()) << endl;
  return 0;
}
