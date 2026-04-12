#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
typedef long long ll;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pii pair < int , int >
#define pll pair < ll, ll >
#define mp make_pair
#define ff first
#define ld long double
#define ss second
#define vi vector < int >
#define vll vector < ll >
#define pb push_back
#define pf push_front
#define PI 3.1415926535897932384626
#define INF 0x3f3f3f3f
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)

const int mod = 1'000'000'007;

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
#define INFF 200

	
int main()
{
		fastio;
		ll ttt = 1;
		//cin >> t;
		rep(tt,1,ttt+1)
		{
			ll  d;
			string k;
			cin >> k >> d;
			//deb(k);
			vll dp(d), dp1(d), dp1old(d);
			dp[0] = 1; dp1old[0] = 1;
			ll now = 1;
			repr(i, k.size()-1, 0)
			{
				rep(j, 0, 10)
				{
					rep(ii, 0, d)
					{
						dp1[((j*now)%d + ii)%d] += dp1old[ii];
						dp1[((j*now)%d + ii)%d] %= mod;
					}
				}
				vll dpnew(d);
				rep(ii, 0, d)
				{
					ll val = k[i] - '0';
					dpnew[((val*now)%d + ii)%d] += dp[ii];
					dpnew[((val*now)%d + ii)%d] %= mod;
				}
				rep(j, 0, k[i]-'0')
				{
					rep(ii, 0, d)
					{
						dpnew[((j*now)%d + ii)%d] += dp1old[ii];
						dpnew[((j*now)%d + ii)%d] %= mod;
					}
				}
				dp1old = dp1;
				dp = dpnew;
				dp1 = vector<ll> (d, 0);
			}
			cout << (dp[0]-1+mod)%mod << endl;
		}
		return 0;
	}
