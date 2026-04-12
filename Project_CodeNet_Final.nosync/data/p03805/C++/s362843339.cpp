#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;

int G[8][8];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  REP(i,m){
    int a,b;
    cin >> a >> b;
    a--,b--;
    G[a][b]=1;
    G[b][a]=1;
  }
  vector<int> arr(n-1);
  REP(i,n-1) arr[i] = i+1;
  int cnt = 0;
  do{
    if(G[0][arr[0]]!=1) continue;
    bool flag = true;
    REP(i,n-2){
      if(G[arr[i]][arr[i+1]]!=1) flag = false;
    }
    if(flag)cnt++;
  }while(next_permutation(ALL(arr)));
  cout << cnt << '\n';
  return 0;
}
