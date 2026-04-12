#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repa(i, a, n) for (int i = (int)(a); i < (int)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#define COUT(x) cout << (x) << endl;
#define _GLIBCXX_DEBUG

int main(){
  
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> c(n, vector<bool>(n, false));
  rep(i, m){
    int a, b;
    cin >> a >> b;
    c[a-1][b-1] = true;
    c[b-1][a-1] = true;
  }

  vector<int> v(n-1);
  iota(ALL(v), 1);

  int cnt = 0;
  do{
    int p = 0;
    bool f = true;
    for(auto x : v){
      if(c[p][x] == false){
        f = false;
        break;
      }
      else{
        p = x;
      }      
    }
    if(f) cnt++;
  }
  while(next_permutation(ALL(v)));
  cout << cnt << endl;

}
