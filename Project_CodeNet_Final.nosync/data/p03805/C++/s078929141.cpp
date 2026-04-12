#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)

int main(){
  int n, m;
  cin >> n >> m;
  int a[m], b[m], p[n + 1][n + 1] = {0};
  REP(i, m){
    cin >> a[i] >> b[i];
    p[a[i]][b[i]] = 1;
    p[b[i]][a[i]] = 1;
  }

  vector<int> v;
  REP(i, n) v.pb(i + 1);

  int cnt, ans = 0;

  do{
    cnt = 0;
    REP(i, n - 1){
      if(p[v[i]][v[i + 1]]) cnt++;
    }
    if(cnt == n - 1) ans++;
  }while(next_permutation(v.begin() + 1, v.end()));

  cout << ans << endl;
}
