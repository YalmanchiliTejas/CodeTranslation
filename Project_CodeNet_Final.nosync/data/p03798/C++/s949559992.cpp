#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int n;
char s[100002];

int f (int i, char a, char b, char* ans) {
  if (i == n) {
    if (b == 'S') {
      if (s[n-1] == 'o' && ans[0] != a) return 1;
      else if (s[n-1] == 'x' && ans[0] != (a == 'S'?'W':'S')) return 1;
    } else {
      if (s[n-1] == 'x' && ans[0] != a) return 1;
      else if (s[n-1] == 'o' && ans[0] != (a == 'S'?'W':'S')) return 1;
    }
    if (ans[0] == 'S') {
      if ( s[0] == 'o' && ans[1] != b) {return 1;}
      else if (s[0] == 'x' && ans[1] != (b == 'S'?'W':'S')) {return 1;}
    } else {
      if (s[0] == 'x' && ans[1] != b) return 1;
      else if (s[0] == 'o' && ans[1] != (b == 'S'?'W':'S')) return 1;
    }
    return 0;
  }
  if (b == 'S') {
    if (s[i-1] == 'o') ans[i] = a;
    else ans[i] = a == 'S'? 'W' : 'S';
  } else {
    if (s[i-1] == 'x') ans[i] = a;
    else ans[i] = a == 'S'? 'W' : 'S';
  }
  return f(i+1, b, ans[i], ans);
}

int main () {
  int ret;
  string str = "";
  char ans[1000002];
  cin >> n >> s;
  for (int i = 0; i < n + 1; i++) ans[i]=0;

  if ( f(2, ans[0] = 'S', ans[1] = 'S', ans)
       && f(2, ans[0] = 'W', ans[1] = 'S', ans)
       && f(2, ans[0] = 'S', ans[1] = 'W', ans)
       && f(2, ans[0] = 'W', ans[1] = 'W', ans) ) {
    cout << -1 << endl;
  } else cout << ans << endl;
  return 0;
}