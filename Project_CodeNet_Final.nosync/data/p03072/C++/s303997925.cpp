#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  int cnt = 1;
  int hmax = H.at(0);
  for (int i = 1; i < N; i++) {
    if (H.at(i) >= hmax){
      hmax = H.at(i);
      cnt++;
    };
  }
  cout << cnt << endl;
}
