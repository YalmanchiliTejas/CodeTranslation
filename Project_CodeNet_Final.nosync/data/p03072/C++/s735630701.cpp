#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i=0; i<N; i++) cin >> H[i];
  
  int cnt = 0;
  int ans = H[0];
  for (int i=0; i<N; i++) {
    if (ans <= H[i]) cnt++;
    ans = max(ans,H[i]);
  }
  cout << cnt << endl;
}