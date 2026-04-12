#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define pii pair<int, int>
#define p3i pair<pii, int>
#define pll pair<ll, ll>
#define p3l pair<pll, ll>
#define vi vector<int>
#define vpii vector<pii>
#define vp3i vector<p3i>
#define vpll vector<pll>
#define vp3l vector<p3l>
#define lseg L, (L+R)/2, N*2+1
#define rseg (L+R)/2+1, R, N*2+2
#define ub upper_bound
#define lb lower_bound
#define pq priority_queue
#define MN 1000000007
#define fox(k, x) for (int k=0; k<x; ++k)
#define fox1(k, x) for (int k=1; k<=x; ++k)
#define foxr(k, x) for (int k=x-1; k>=0; --k)
#define fox1r(k, x) for (int k=x; k>0; --k)
#define ms multiset
#define flood(x) memset(x, 0x3f3f3f3f, sizeof x)
#define drain(x) memset(x, 0, sizeof x)
#define rng() ((rand() << 14)+rand())
#define scan(X) do{while((X=getchar())<'0'); for(X-='0'; '0'<=(_=getchar()); X=(X<<3)+(X<<1)+_-'0');}while(0)
char _;
#define pi 3.14159265358979323846

int n, m, dp[200005], psa[200005];
int sum, ans=0;
string s;
int get(int N, int L){
  int hi = N;
  int lo = hi - L - 1;
  //cout << N << ' ' << L << ' ' <<lo << ' ' << hi << endl;
  int res = psa[hi];
  if (lo >= 0) res -= psa[lo];
  return res%MN;
}
int32_t main(){
  cin >> n >> m >> s;
  int pref = 0, lim, c = 0;
  fox(l, m){
    if (s[l] != s[0]) break;
    pref++;
  }
  if (pref % 2 == 1)
    lim = pref;
  else
    lim = pref + 1;
  if (pref == m){
    dp[0] = 1;
    dp[1] = 1;
    for(int l = 2; l <= n; ++l){
      dp[l] = (dp[l-1]+dp[l-2])%MN;
    }
    cout << (dp[n-2] + dp[n] + 0LL + MN)%MN;
    return 0;
  }
  if (n%2 == 1){
    if (pref != m){
      printf("0\n");
      return 0;
    }
  }
  fox(l, m){
    if (s[l]!=s[0]){
      if (c%2 == 1){
        lim = min(lim, c);
      }
      c=0;
    } else {
      c++;
    }
  }
  n/=2;
  lim /= 2;
  lim = min(lim, n-1);
  //cout << lim << endl;
  dp[0]= 1;
  int p=0;
  sum = 1;
  psa[0] = 1;
  fox1(l, n){
    while(l-p-1 > lim){
      sum = (sum - dp[p]) % MN;
      ++p;
    }
    dp[l] = sum;
    psa[l] = (psa[l-1] + dp[l]) % MN;
    sum = (sum + dp[l]) % MN;
    //cout << dp[l] << ' ';
  }
  fox(l, lim+1){
    //starting component
    ans = (ans + get(n-1-l, lim-l))%MN;
  }
  if (ans < 0) ans += MN;
  cout << ans*2%MN;
  return 0;
}
