// #pragma GCC optimize("O3", "unroll-loops")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define endl '\n'
#define all(a) a.begin(),a.end()
#define int long long
#define pb push_back
#define pii pair <int, int>
#define ff first
#define ss second
#define point pair <double, double>
#define debug(x) cerr << #x << " is " << x << endl;

const int INF = 1e15 + 0;
//const int mod = 1e9 + 7;
const int mod = 998244353;
const int N = 3e3 + 5;
int dp[N][N], P[N][N];

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  // #ifndef ONLINE_JUDGE
	//   freopen("input.txt", "r", stdin);
	//   freopen("output.txt", "w", stdout);
  // #endif

  int n, sum; cin >> n >> sum;
  int data[n+5];
  for(int i = 1; i <= n; i++) {
    cin >> data[i];
    dp[i][data[i]] = i;
  }
 
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= sum; j++){
         if((j-data[i]) >= 0){
           dp[i][j] += P[i-1][j-data[i]];
           dp[i][j] %= mod;
         }
         P[i][j] = (dp[i][j] + P[i-1][j]) % mod;
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++){
    int temp = (dp[i][sum]*(n-i+1)) % mod; 
    ans += temp; ans %= mod;
  }
  cout << ans << '\n';
}

