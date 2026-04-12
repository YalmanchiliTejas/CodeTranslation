#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repa(i, a, n) for (int i = (int)(a); i < (int)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#define COUT(x) cout << (x) << endl
#define _GLIBCXX_DEBUG

int main(){
  
  int r, g, b;
  cin >> r >> g >> b;
  int c = 100*r + 10*g + b;
  if (!(c % 4))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

}