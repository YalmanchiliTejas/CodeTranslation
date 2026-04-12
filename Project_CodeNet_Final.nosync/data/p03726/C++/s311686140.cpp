#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<19;

int bio[MAX];
vector <int> V[MAX];
int ok=1;

int dfs(int x, int pr) { //vraca 1 ako treba spojit
  int treba = 0;
  for (auto it : V[x])
    if (it != pr) treba += dfs(it, x);  

  if (treba > 1) ok = 0;
  if (treba) return 0;
  return 1;
}

int main()
{
  int n;
  scanf("%d", &n);

  REP(i, n-1) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  ok &= (!dfs(0, -1));
  printf("%s\n", (!ok) ? "First" : "Second");

  return 0;
}
