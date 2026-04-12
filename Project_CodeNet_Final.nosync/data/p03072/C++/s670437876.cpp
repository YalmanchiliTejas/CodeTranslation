#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i=0; i<N; i++) cin >> H[i];
  int cnt = 0;
  int ma = H[0];
  for (int i=0; i<N; i++) {
    if (ma <= H[i]) {
      cnt++;
      ma = max(ma,H[i]);
    }
  }
  cout << cnt << endl;
}