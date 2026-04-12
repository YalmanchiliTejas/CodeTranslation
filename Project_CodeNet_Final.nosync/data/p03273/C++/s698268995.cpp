#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)

int main(){
  int h, w;
  cin >> h >> w;
  char a[h][w];

  int b[h] = {0};
  int c[w] = {0};

  REP(i, h){
    REP(j, w){
      cin >> a[i][j];
      if(a[i][j] == '#') b[i] = 1;
    }
  }

  REP(j, w){
    REP(i, h){
      if(a[i][j] == '#') c[j] = 1;
    }
  }

  REP(i, h){
    if(b[i] == 1){
      REP(j, w){
        if(c[j] == 1) cout << a[i][j];
      }
      cout << endl;
    }
  }
}
