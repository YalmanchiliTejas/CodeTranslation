#include <bits/stdc++.h>

using namespace std;

int main()
{
  multiset<int> ms;
  int n;
  
  scanf("%d", &n);
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    auto it = ms.lower_bound(a);
    if (it == ms.begin()) {
      ans++;
    }
    else {
      --it;
      ms.erase(it);
    }
    ms.insert(a);
  }
  
  printf("%d\n", ans);
  
  return 0;
}