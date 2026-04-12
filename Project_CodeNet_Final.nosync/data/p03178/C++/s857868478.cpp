#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define N 10005
using namespace std;
typedef long long ll;
ll n, k, dp[2][N][105];
char s[N];

ll f(ll ind, ll md, ll d){
	ll &r = dp[d][ind][md];
	if(r != -1)
		return r;
	if(ind > n){
		if(!md)
			return r = 1;
		return r = 0;
	}
	// cout << ind << " " << md << " " << d << endl;
	r = 0;
	if(!d){
		r = f(ind + 1, (md + s[ind] - '0')%k, 0);
		for(ll i = 0; i < s[ind] - '0'; i++)
			r = (r + f(ind + 1, (md + i)%k, 1) )%mod;
		return r;
	}
	for(ll i = 0; i < 10; i++)
		r = (r + f(ind + 1, (md + i)%k, 1) )%mod;
	return r;
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	memset(dp, -1, sizeof dp);
	scanf("%s %lld",s + 1, &k);
	n = strlen(s + 1);
	printf("%lld\n", (f(1, 0, 0) + mod - 1)%mod );
	return 0;
}