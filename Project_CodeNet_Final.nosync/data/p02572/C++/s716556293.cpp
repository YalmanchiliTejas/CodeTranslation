#include<bits/stdc++.h>
#define pb push-back
#define all(x) x.begin(),x.end()

using ll = long long int;
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i < n; i++)

using namespace std;

ll power(ll n, ll k)
{
	ll res = 1;
	while(k){
		if(k & 1){
			res *= n;
			k--;
		}
		else{
			n *= n;
			k /= 2;
		}
	}
	return res;
}

const ll mod = 1000000007;
void solve()
{
	ll n; cin >> n;
	ll ar[n+1];
	rep1(i,n+1) cin >> ar[i];
	
  ll pre[n+1];
  memset(pre,0,sizeof(pre));
  
  rep1(i,n+1)
    pre[i] = (pre[i-1] + ar[i]) % mod;

  ll ans = 0;
  rep1(i,n+1)
    ans = (ans + (pre[i-1] * ar[i]) % mod) % mod;
 cout << ans << "\n";
}

int main()
{
	int tc=1;// cin >> tc;
	while(tc--)
	{
		solve();
	}
	return 0;
}

// ©beast_sr
