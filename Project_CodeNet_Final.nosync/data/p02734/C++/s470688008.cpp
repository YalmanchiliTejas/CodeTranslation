#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
#define EPS 1e-9
#define PI acos(-1.0)
const int N = 3e3 + 4;
const int MOD = 998244353;
int memo[N][N] , a[N] , n , S , en;

int mul(int a , int b){
   return (1ll * a * b) % MOD;
}
int add(int a , int b){
   a += b;
   while (a > MOD) a -= MOD;
   while (a < 0) a += MOD;
   return a;
}

int solve(int indx , int sum){
   if(!sum)
      return n - indx + 1;
   if(indx == n)
      return 0;
   int &ret = memo[indx][sum];
   if(~ret)
      return ret;
   ret = 0;
   if(sum >= a[indx])ret = add(ret , solve(indx + 1 , sum - a[indx]));
   ret = add(ret , solve(indx + 1 , sum));
   return ret;
}

int main() {
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   cin >> n >> S;
   for(int i = 0 ; i < n ; ++i)
      cin >> a[i];
   memset(memo , -1, sizeof(memo));

   int ans = 0;
   for(int i = 0 ; i < n ; ++i){
      int cur = solve(i , S);
      ans = add(ans , cur);
   }
   cout << ans << "\n";
}