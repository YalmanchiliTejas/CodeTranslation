#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  int ans = 1;
  for (int i = 1; i < N; i++)  {
    vector<int> b(i);
      for (int j = 0; j < i; j++) b[j] = a[j];
    sort(b.begin(), b.end());
    
        if (a[i] >= b[i-1]) ++ans;
  }
  cout << ans << endl;
}