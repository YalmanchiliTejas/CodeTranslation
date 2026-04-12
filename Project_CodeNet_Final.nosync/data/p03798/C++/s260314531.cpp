#include <iostream>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < n; ++i)

using namespace std;

int n;
char s[100001];
int x[100000];

int next(int i){
  int p = x[i ? i - 1 : n - 1];
  return (s[i] == 'o') ^ x[i] ? p : !p;
}

int main(){
  cin >> n >> s;
  rep(i, 2){
    x[0] = i;
    rep(j, 2){
      x[1] = j;
      for(int k = 1; k + 1 < n; ++k){
        x[k + 1] = next(k);
      }
      if(next(n - 1) == i && next(0) == j){
        rep(l, n){
          cout << (x[l] ? 'W' : 'S');
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}