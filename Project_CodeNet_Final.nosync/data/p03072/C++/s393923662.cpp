#include <bits/stdc++.h>
using namespace std;

int n;
int h[25];

int main()
{
  int p=0;
  int ans=0;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> h[i];
    if (p<=h[i]) {
      ans++;
      p=h[i];
    }
  }

  cout << ans << endl;

  return 0;
}
