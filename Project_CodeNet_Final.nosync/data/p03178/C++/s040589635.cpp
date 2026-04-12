#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const ll inf = 1e18+5;
const ll mod = 1e9+7;
const ll maxn = 100005;
char k[maxn];
string s;
ll D;
ll add(ll a, ll b){
	return (a%mod+b%mod+mod)%mod;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> s;
	cin >> D;
	for (ll i = 0; i < s.length(); i++)k[i] = s[i];
	vector<vector<ll>> dp(D, vector<ll>(2));
	dp[0][0] = 1;
	for (ll where = 0; where < s.length(); where++){ //each digit
		vector<vector<ll>> new_dp(D, vector<ll>(2));
		for (ll sum = 0; sum < D; sum++){ //each possible modulo
			for (ll i = 0; i < 2; i++){ 
				for (ll digit = 0; digit < 10; digit++){
					if (digit > k[where]-'0' && i == 0)break;
					bool check = 0;
					if (i == 1)check = 1;
					new_dp[(sum+digit)%D][check || (digit < k[where]-'0')] = add(new_dp[(sum+digit)%D][check || (digit < k[where]-'0')], dp[sum][i]);
				}
			}
		}
		dp = new_dp;
	}
	ll ans = (dp[0][0] + dp[0][1])%mod;
	ans = add(ans, -1);
	cout << ans;
	
}	
