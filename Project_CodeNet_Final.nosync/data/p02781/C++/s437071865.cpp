#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long  ll;
#define EPS 1e-9
#define PI acos(-1.0)
const int N = 104;

long long memo[N][2][4];
string s;
long long solve(int indx , bool gr , int rem){
   if(indx == s.size())
      return (rem == 0);
   long long &ret = memo[indx][gr][rem];
   if(~ret)
      return ret;
   ret = 0;
   int num = s[indx] - '0' , theOne = (gr ? 9 : num);
   for(int i = 0 ; i <= theOne ; ++i){
      if(!i || (i && rem))ret += solve(indx + 1 , gr || (i < num) , rem - (i > 0));
   }
   return ret;
}
int main() {
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   cin >> s;
   int k;
   cin >> k;
   memset(memo , -1 , sizeof(memo));
   cout << solve(0 , 0 , k) << "\n";
}