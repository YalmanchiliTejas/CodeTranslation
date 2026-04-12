#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
//using namespace __gnu_pbds;

//template<typename T>
//using ordered_set =
//tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long  ll;
#define EPS 1e-9
#define PI acos(-1.0)
const int N = 2e5 + 4;

int n , a[N];
ll memo[N][3];
bool v[N][3];
ll solve(int idx , int r){
   if(idx >= n)
      return (r <= 1 ? 0 : -LLONG_MAX / 2);
   ll &ret = memo[idx][r];
   if(v[idx][r])
      return ret;
   v[idx][r] = true;
   ret = -LLONG_MAX / 2;
   ret = max(ret , a[idx] + solve(idx + 2 , r));
   if(r)ret = max(ret , solve(idx + 1 , r - 1));
   return ret;
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   cin >> n;
   for(int i = 0 ; i < n ;++i)
      cin >> a[i];
   cout << solve(0 , 1 + (n & 1)) << "\n";
}