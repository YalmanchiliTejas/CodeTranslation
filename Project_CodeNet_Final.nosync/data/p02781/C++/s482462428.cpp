#include <bits/stdc++.h>
using namespace std;
int main(){
  string N;
  int K;
  cin >> N >> K;
  int d = N.size();
  if (K == 1){
    cout << (d - 1) * 9 + N[0] - '0';
  } else if (K == 2){
    if (d == 1){
      cout << 0;
    } else {
      int ans = 81 * (d - 1) * (d - 2) / 2;
      ans += (N[0] - '1') * 9 * (d - 1);
      int z = 1;
      while (N[z] == '0') z++;
      if (z == d){
        cout << ans;
      } else {
        ans += 9 * (d - z - 1);
        ans += N[z] - '0';
        cout << ans;
      }
    }
  } else {
    if (d < 3){
      cout << 0;
    } else {
      int ans = 729 * (d - 1) * (d - 2) * (d - 3) / 6;
      ans += (N[0] - '1') * 81 * (d - 1) * (d - 2) / 2;
      int z1 = 1;
      while (N[z1] == '0') z1++;
      if (z1 == d){
        cout << ans;
      } else {
        ans += 81 * (d - z1 - 1)* (d - z1 - 2) / 2;
        ans += (N[z1] - '1') * 9 * (d - z1 - 1);
        int z2 = z1 + 1;
        while (N[z2] == '0') z2++;
        if (z2 == d){
          cout << ans;
        } else {
          ans += 9 * (d - z2 - 1);
          ans += N[z2] - '0';
          cout << ans;
        }
      }
    }
  }
}