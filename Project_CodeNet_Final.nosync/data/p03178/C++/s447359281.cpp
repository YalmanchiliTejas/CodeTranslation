#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll N = 10011 ;
ll dp[N][109], n, d, mod = 1e9+7, q, ans;
string s ;
int main ()
{
	ios::sync_with_stdio(false) ;
	cin.tie() ;
	cout.tie() ;
	cin >> s >> d ; 
	for(int i = 0 ; i < 10 ; i ++)
		dp[1][i%d] ++ ;
	for(int i = 2 ; i < N ; i ++){
		for(int j = 0 ; j < d ; j ++){
			for(int k = 0 ; k <= 9 ; k ++){
				ll now = (j-k+(1000000000*d))%d ;
				dp[i][j] = (dp[i][j] + dp[i-1][now]) % mod ;
			}
		}
	}
	for(int i = 0 ; i < s.size()-1 ; i ++){
		int k = s.size() - i - 1 ;
		for(int j = 0 ; j < s[i]-'0' ; j ++){
			ll now = ((1000000000*d)-j-q)%d ;
			ans = (ans + dp[k][now]) % mod ;
		}
		q = (q + s[i]-'0');
	}
	for(int j = 0 ; j <= s[s.size()-1]-'0' ; j ++){
		ll now = ((100*d)-j-q)%d ;
		if(now == 0)
			ans ++ ;
	}
	ans = (ans - 1 + mod) % mod ;
	ans %= mod ;
	cout << ans ;
}
