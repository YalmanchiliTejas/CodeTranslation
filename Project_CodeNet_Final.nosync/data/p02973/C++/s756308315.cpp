#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
int N;
int a;
 
multiset <int> q;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin >> N;
  int ans = 0;
  for(int i = 0; i < N; i++) {
    cin >> a;
    if(q.size() == 0 || *q.begin() >= a) {
      ans++;
      q.insert(a);
    } else {
      q.erase(--q.lower_bound(a));
      q.insert(a);
    } 
  }
  cout << ans << endl;
}
