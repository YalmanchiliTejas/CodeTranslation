#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n;
  cin >> n;
  pair<int, int> a[n];
  for(int i = 0;i < n;i++)
    cin >> a[i].first, a[i].second = i;
  sort(a, a + n);
  int ans[n];
  for(int i = 0;i < n;i++){
    if(i >= n / 2)
      ans[a[i].second] = a[n / 2 - 1].first;
    else{
      ans[a[i].second] = a[n / 2].first;
    }
  }
  for(int i = 0;i < n;i++)
    cout << ans[i] << endl;

  return 0;
}
