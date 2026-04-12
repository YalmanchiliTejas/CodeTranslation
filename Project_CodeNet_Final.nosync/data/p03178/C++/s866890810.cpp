#include <bits/stdc++.h>

#define ll long long

#define mod 1000000007

#define pb push_back

#define pi pair<int,int>

#define pll pair<ll,ll>

#define inf 1000000000000000000

using namespace std;

string k;

int d;

ll dp[10010][100][2];

ll fun(int pos, int rem, int equal){

	if(pos == k.length()){		if(rem){

			return 0;

		}

		else{

			return 1;

		}

	}

	if(dp[pos][rem][equal] != -1){

		return dp[pos][rem][equal];

	}

	dp[pos][rem][equal] = 0;

	if(equal){

		for(int num = 0; num < k[pos] - '0'; num++){

			dp[pos][rem][equal] += fun(pos + 1, (rem - num + 10 * d) % d, 0);

		}

		dp[pos][rem][equal] += fun(pos + 1, (rem - (k[pos] - '0') + 10 * d) % d, 1);

	}

	else{

		for(int num = 0; num < 10; num++){

			dp[pos][rem][equal] += fun(pos + 1, (rem - num + 10 * d) % d, 0);

		}

	}

	dp[pos][rem][equal] %= mod;

	return dp[pos][rem][equal];

}

int main(){

	ios::sync_with_stdio(false);

	cin.tie(0);

	cin>>k;

	cin>>d;

	for(int i = 0; i < k.length(); i++){

		for(int j = 0; j < d; j++){

			dp[i][j][0] = -1;

			dp[i][j][1] = -1;

		}

	}

	ll ans = fun(0, 0, 1) - 1 + mod;

	ans %= mod;

	cout<<ans<<endl;

	return 0;

}