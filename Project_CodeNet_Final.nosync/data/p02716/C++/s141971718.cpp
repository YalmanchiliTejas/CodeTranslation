// --------------
// Tejas Pandey  |
// 11 - 04 - 20  |
// Atcoder BC 162|
// --------------

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define lim 1000000000000000000
#define vi vector<int>
typedef long long int ll;

int gcd(int a,int b){
	return (a%b?gcd(b,a%b):b);
}

ll mpow(ll a,ll b){
	ll res = 1;
	while(b){
		if(b&1) res *= a,res %= mod;
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return res;
}

int main (void)
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  //cin >> t;
  while(t--){
  	//cout << "Case :" << c - t << ": ";
  	int n;
  	cin >> n;
  	ll a[n];
  	for(int i = 0;i < n;i++) cin >> a[i];
  	ll dp[2 + (n&1)][n/2];
  	ll su[2 + (n&1)];
  	memset(dp,0,sizeof(dp));
  	ll ans = -lim;
  	for(int i = 0;i < 2 + (n&1);i++){
  		ll sum = 0,cur = 0;
  		for(int j = i;j < i + (n/2)*2;j += 2)
  			sum += a[j],dp[i][cur] = sum,cur++;
  		//cout << cur << "\n";
  		su[i] = sum;
  		ans = max(ans,sum);
  	}
  	for(int i = 0;i < 1 + (n&1);i++){
  		ll cur = 0;
  		for(int j = i;j < i + (n/2 - 1)*2;j += 2){
  			for(int k = 0;k < 2 + (n&1);k++)
  				ans = max(ans,dp[i][cur] + su[k] - dp[k][cur]);
  			cur++;
  		}
  	}
  	if(n&1){
  		for(int i = 1;i < 2;i++){
  			ll cur = n/2 - 1;
  			dp[i][cur] = max(a[1 + cur*2],a[2 + cur*2]);
  			while(cur--){
  				dp[i][cur] = a[1 + cur*2] + max(dp[i][cur + 1],su[i + 1] - dp[i + 1][cur]);
  			}
  		}
  		for(int i = 0;i < 1;i++){
  		ll cur = 0;
  			for(int j = i;j <= i + (n/2 - 1)*2;j += 2){
  				for(int k = 1;k < 1 + (n&1);k++)
  					ans = max(ans,dp[i][cur] + dp[k][cur + 1]);
  				cur++;
  			}
  	    }
  	}
  	cout << ans;
  }
  return 0;
}