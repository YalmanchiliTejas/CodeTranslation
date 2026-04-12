#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  multiset<int> st;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    {
      int x; scanf("%d", &x);
      x = -x;
      auto it = st.upper_bound(x);
      if (it != st.end()) st.erase(it);
      st.insert(x);
    }
  printf("%d\n", (int) st.size());
}
