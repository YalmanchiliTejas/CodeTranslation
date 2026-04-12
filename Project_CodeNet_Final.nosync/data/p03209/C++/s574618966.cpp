#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll a[51];
ll p[51];

 ll solve(ll n, ll x){
   ll ans = 0;
   if(n == 0){
     ans += 1;
   }
   else if(x == 1){
     ans += 0;
   }
   else if(x <= 1 + a[n-1]){
     ans += solve(n - 1, x - 1);
   }
   else if(x == 2 + a[n-1]){
     ans += p[n-1] + 1;
   }
   else if(x <= 2 + 2 * a[n-1]){
     ans += p[n-1] + 1 + solve(n - 1, x - 2 - a[n-1]);
   }
   else{
     ans += 2 * p[n-1] + 1;
   }
   return ans;
 }

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll n, x;
  cin >> n >> x;

  a[0] = 1;
  p[0] = 1;
  rep(i, 51){
    a[i+1] = a[i] * 2 + 3;
    p[i+1] = p[i] * 2 + 1;
  }

  ll ans = solve(n, x);

  cout << ans << endl;
  return 0;
}