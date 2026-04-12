#include <bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(0); cin.tie(0);
#define T() int tt; cin >> tt; rep1(qq,1,tt)
#define rep(i,start,lim) for(int i=start;i<lim;i++)
#define rep1(i,start,lim) for(int i=start; i<=lim; ++i)
#define repd(i,start,lim) for(int i=start;i>=lim;i--)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define br cout<<"\n"
#define MOD (1000000007LL)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define eps (1e-6)
#define what_is(x) cerr << #x << " is " << x << "\n";
#define int long long int
#define infll 9e18
#define inf 1e12

#define lnode (2 * node + 1)
#define rnode (2 * node + 2)

using namespace std;

typedef pair<int, int> pii;

const int N = 3005;

int n, s;
int a[N], dp[N][N], ndp[N][N];

int add(int x, int y, int m){
  int res = ((x % m) + (y % m)) % m;
  return res;
}

int mul(int x, int y, int m){
  int res = ((x % m) * (y % m)) % m;
  return res;
}

int sub(int x, int y, int m){
  int res = ((x % m) - (y % m) + m) % m;
  return res;
}

int32_t main()
{

	FIO
	//cout << fixed << setprecision(10);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

  const int M = 998244353;
  cin >> n >> s;
  for(int i = 0; i < n; ++i) cin >> a[i];
  dp[0][a[0]] = (0 + 1);
  ndp[0][a[0]] = 1;
  int res = 0;
  if(a[0] == s) res = n;
  for(int i = 1; i < n; ++i){
    dp[i][a[i]] = (i + 1);
    ndp[i][a[i]] = (i + 1);
    for(int j = 0; j <= s; ++j){
      ndp[i][j] = add(ndp[i][j], ndp[i - 1][j], M);
      if(j > a[i]) ndp[i][j] = add(ndp[i][j], ndp[i - 1][j - a[i]], M);
      if(j > a[i]) dp[i][j] = ndp[i - 1][j - a[i]];
    }
    res = add(res, mul((n - i), dp[i][s], M), M);
    res %= M;
  }
  cout << res << '\n';
  
	return 0;
}



