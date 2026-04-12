#include <bits/stdc++.h>

using namespace std;

int main() {
  #ifdef _OFFLINE_
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n;
  cin >> n;
  vector<int> arr(n), res(n);
  for(int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int l = 0, r = n - 1;
  int index = n - 1;
  while(true) {
    res[l] = arr[index];
    --index;
    if(index < 0) {
      break;
    }
    res[r] = arr[index];
    --index;
    ++l; --r;
    if(l > r || index < 0) {
      break;
    }
  }

  for(int i = 0; i < n; ++i) {
    cout << res[i] << ' ';
  }
}