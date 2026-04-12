#include<bits/stdc++.h>
using namespace std;

int main(){

  int n, ans = 0, flag;
  cin >> n;
  int h[n];
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  reverse(h, h + n);

  for (int i = 0; i < n; i++) {
    flag = 1;
    for (int j = i; j < n; j++) {
      if(h[i] < h[j]) flag = 0;
    }
    if(flag == 1) ans += 1;
  }

  cout << ans << endl;

}
