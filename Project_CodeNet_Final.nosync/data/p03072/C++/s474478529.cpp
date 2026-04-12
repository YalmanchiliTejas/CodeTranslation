#include <bits/stdc++.h>
using namespace std;
int main()  {
  int N;
  cin >> N;
  vector<int> a(N);
  int ans = 0;
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < N; i++)  {
    bool is_candidate = true;
    for (int j = 0; j < i; j++)  {
      if (a[j]>a[i])  {
      is_candidate = false;
      break;
    }
  }
  if(is_candidate) ++ans;
}
cout << ans <<endl;
}