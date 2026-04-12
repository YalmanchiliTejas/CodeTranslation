#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, a=0, cnt=0;
  cin >> N;
  vector<int> H(N);
  rep(i, N){
    cin >> H.at(i);
    rep(j, i){
      if(H.at(j)>H.at(i)){
        a=1;
        break;
      }
    }
    if(a==0) cnt++;
    a=0;
  }
  cout << cnt << endl;
}