#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long double ld;

char a[100][100];
bool b[100][100];
bool line[100];

int main()
{
  int h,w;
  cin >> h >> w;
  bool flag;
  REP(i,h){
    flag = true;
    REP(j,w){
      cin >> a[i][j];
      b[i][j] = true;
      if(a[i][j] == '#') flag = false;
    }
    if(flag){
      line[i] = false;
      REP(j,w) b[i][j] = false;
    }else{
      line[i] = true;
    }
  }
  REP(j,w){
    flag = true;
    REP(i,h){
      if(a[i][j] == '#') flag = false;
    }
    if(flag){
      REP(i,h) b[i][j] = false;
    }
  }
  
  REP(i,h){
    flag = true;
    REP(j,w){
      if(b[i][j]) cout << a[i][j];
    }
    if(line[i]) cout << '\n';
  }
  return 0;
}
