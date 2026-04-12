#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define pb push_back
#define fi first
#define se second
 
const ll MOD = 1000000007;

int main() {
   int n; scanf("%d", &n);
   vector<int> a(n);
   for (int &i : a)
      scanf("%d", &i);
   multiset<int, greater<int>> ans;
   for (int i : a) {
      multiset<int>::iterator it = ans.upper_bound(i);
      if (it != ans.end())
         ans.erase(it);
      ans.insert(i);
   }
   printf("%d ", ans.size());
   return 0;
}