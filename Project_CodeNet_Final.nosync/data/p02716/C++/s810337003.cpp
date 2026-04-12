#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector <int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;
const ll inf = 3e18 + 5;
int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }

const int maxn = 2e5 + 5;
ll dp[maxn][3];
ll sum[maxn];
ll a[maxn];
int n;

ll f(int i, int skip){
  if(i >= n) return 0;
  if(skip == (2 - (n % 2 == 0))) return sum[i];
  if(dp[i][skip] != -1) return dp[i][skip];
  ll ret = a[i] + f(i + 2, skip);
  ret = max(ret, f(i + 1, skip + 1));
  return dp[i][skip] = ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  sum[n - 1] = a[n - 1];
  sum[n - 2] = a[n - 2];
  for(int i = n - 3; i >= 1; i -= 2){
    sum[i] += sum[i + 2] + a[i];
    sum[i - 1] += sum[i + 1] + a[i - 1];
  }
  if(n % 2 == 1) sum[0] += sum[2] + a[0];
  memset(dp, -1, sizeof dp);
  cout << f(0, 0);
}