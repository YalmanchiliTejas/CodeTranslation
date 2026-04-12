#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//*find_by_order
//order_of_key

const int maxn = 1e6 + 5;

ll a,b,c,x,y;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

  cin>>a>>b>>c>>x>>y;
  ll tot = 0;

  ll both = min(x,y);
  tot += both*min(a+b,2LL*c);
  x -= both;
  y -= both;

  tot += x*min(a,2LL*c);
  tot += y*min(b,2LL*c);
  
  cout<<tot<<endl;
  return 0;
}
