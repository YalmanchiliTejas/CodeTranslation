#include "bits/stdc++.h"
using namespace std;
 
////////////// Prewritten code follows. Look down for solution. ////////////////

//#define int long long
#define endl '\n'
#define fs first
#define sc second
#define pb push_back
#define len(x) ((int)(x).size())     
#define all(x) (x).begin(), (x).end()
#define test int _; cin >> _; while(_--)
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;

ll gcd(ll a, ll b){return (b == 0LL ? a : gcd(b, a%b));}
inline ll mod(ll a, ll b){return ((a%b)+b)%b;}
inline ll expo(ll b, ll p, ll m = MOD){
  ll ans = 1; 
  while(p > 0){
    if(p&1LL) ans = mod(ans*b, m); 
    b = mod(b*b, m); 
    p >>= 1LL;
  } 
  return ans;
}
 
////////////////////////// Solution starts below. //////////////////////////////

ll dp[3005][3005];
ll v[3005];

int32_t main(){
  fastio;
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> v[i];
    dp[i][i] = v[i];
  }
  for(int l = n; l >= 1; l--){
    for(int r = l; r <= n; r++){
      if((r-l+1)%2 == n%2){
        dp[l][r] = max(v[l] + dp[l+1][r], dp[l][r-1] + v[r]);
      }else{
        dp[l][r] = min(dp[l+1][r] - v[l], dp[l][r-1] - v[r]);
      }
    }
  }
  cout << dp[1][n] << endl;
  return 0;
}