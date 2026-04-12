#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  vector<int> H(100);
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  
  int ans = 0;
  int highest = 0;
  for(int i = 0; i < N; i++) {
    if(highest <= H.at(i)) {
      highest = H.at(i);
      ans++;
    }
  }
  cout << ans << endl;
}