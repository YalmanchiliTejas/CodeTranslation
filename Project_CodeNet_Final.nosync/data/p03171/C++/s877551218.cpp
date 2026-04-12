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


	
int main()
{
		fastio;
		ll t = 1;
		//cin >> t;
		rep(tt,1,t+1)
		{
			ll n;
			cin >> n;
			vll A(n);
			ll sum = 0;
			rep(i, 0, n)
			{
				cin >> A[i];
				sum+=A[i];
			}
			ll dp[n][n];
			for(int i = n-1; i>=0; i--)
			{
				rep(j,0,n)
				{
					if(i>j) continue;
					if(i == j) 
					{
						dp[i][i] = A[i];
						continue;
					}
					dp[i][j] = max(A[i] - dp[i+1][j], A[j] - dp[i][j-1]);
				}
			}
			
			ll ans = 0;
			ans = dp[0][n-1];
			cout << ans<< endl;
		}
		return 0;
	}
					
