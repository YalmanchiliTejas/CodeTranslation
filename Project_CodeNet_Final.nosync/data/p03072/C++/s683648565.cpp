#include <bits/stdc++.h>
using namespace std;
int main()  {
  int N; cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) cin >> H[i];

  int res = 0;
  int current_max = 0;
  for (int i = 0; i < N; i++) {
    
    if (H[i] >= current_max) res++;

    if (current_max < H[i]) current_max = H[i];
  }
cout << res << endl;
}
