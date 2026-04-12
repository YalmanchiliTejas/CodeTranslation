#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
multiset<ll> s;
int n;

int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++){
      int x;
      scanf("%d",&x);
      if(s.empty()){
        s.insert(x);
        continue;
      }
      auto it = s.lower_bound(x);
      if(it == s.begin()) s.insert(x);
      else{
        s.erase(-- it);
        s.insert(x);
      }
    }
    printf("%d\n", s.size());
    return 0;
}

