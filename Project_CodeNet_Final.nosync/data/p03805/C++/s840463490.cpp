#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int N, M;
int a[28], b[28];

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) cin >> a[i] >> b[i];
  int array[N-1];
  int ans = 0;
  for (int i = 0; i < N-1; i++) array[i] = i + 2;
  do {
    int p, q;
    bool ikeru;
    for (int i = 0; i < N-1; i++) {
      if (i == 0) p = 1;
      q = array[i];
      ikeru = false;
      for (int j = 0; j < M; j++)
        if ((p == a[j] && q == b[j]) || (q == a[j] && p == b[j])) ikeru = true;
      if (!ikeru) break;
      p = q;
    }
    if (ikeru) ans++;    
  } while (next_permutation(array, array + N - 1));
  cout << ans << endl;
  return 0;
}