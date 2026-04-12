#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N,max,ans = 0;

  cin >> N;
  for(int i = 0; i < N; i++){
    int h;
    cin >> h;
    if(h >= max){
      ans++;
      max = h;
    }
  }

  cout << ans;
}
