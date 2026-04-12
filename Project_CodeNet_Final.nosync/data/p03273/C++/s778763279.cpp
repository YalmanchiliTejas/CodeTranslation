/*Infor {{{
    > File Name: b.cpp
    > Author: samcompu
    > Mail: a1592710567@126.com
    > Website: https://www.samcompu.com
    > Created Time: 2018年08月25日 星期六 20时02分56秒
}}}*/
#include <bits/stdc++.h>

using namespace std;

/*Abbreviation {{{ */
#define FOR(i,a,b) for (int i = (int)(a); i <= (int)(b); i++)
#define ROF(i,a,b) for (int i = (int)(a); i >= (int)(b); i--)
#define FORLINE(i, t) for (int i = fi[t]; i; i = ne[i])
typedef long long ll;
typedef unsigned long long int ull;
/*}}}*/

/*Constant {{{*/
/*}}}*/

/*Class {{{*/
/*}}}*/

/*Variable {{{*/
bool book[101][101];
char s[101];
/*}}}*/

/*Declare {{{*/
/*}}}*/

/*Main {{{*/
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  FOR(i, 1, n) {
    cin >> s;
    FOR(j, 1, m) {
      if (s[j - 1] == '#') book[i][j] = true;
    }
  }
  FOR(i, 1, n) {
    bool all1 = true;
    FOR(j, 1, m) {
      if (book[i][j]) {
        all1 = false;
        break;
      }
    }
    if (all1) continue;
    FOR(j, 1, m) {
      bool all2 = true;
      FOR(k, 1, n) {
        if (book[k][j]) {
          all2 = false;
          break;
        }
      }
      if (all2) continue;
      if (book[i][j]) cout << "#";
      else cout << ".";
    }
    cout << endl;
  }
  return 0;
}
/*}}}*/

/*Define {{{*/
/*}}}*/
