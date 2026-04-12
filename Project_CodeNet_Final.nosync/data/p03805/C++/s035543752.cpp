#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> path(10, vector<bool>(10, false));
  rep(i, M){
    int a, b;
    cin >> a >> b;
    path.at(a).at(b) = true;
    path.at(b).at(a) = true;
  }
  
  vector<int> p(10);
  rep(i, N - 1) p.at(i) = i + 2;
  int ans = 0;
  
  do{
    bool flag = true;
    rep(i, N-1){
      int a, b;
      if(i == 0){
        a = 1;
        b = p.at(0);
      } else {
        a = p.at(i-1);
        b = p.at(i);
      }
      
      if(!path.at(a).at(b)){
        flag = false;
        break;
      }
    }
    if(flag) ans++;
  } while (next_permutation(p.begin(), p.end()));
  
  cout << ans << endl;
}