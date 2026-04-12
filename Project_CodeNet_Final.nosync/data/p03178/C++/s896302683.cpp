#include <bits/stdc++.h>
using namespace std;
#define forloop(n) for(int i = 0; i < n; i++)
#define ll long long
#define mod 1000000007
long long exp(long long taban, long long us) {
    long long carpan = taban;
    long long temp = us;
    long long res = 1;
    for(int i = 0;;i++){
        if(temp % 2) res = (res*carpan) % mod;
        temp /= 2;
        carpan = (carpan*carpan) % mod;
        if(temp == 0) break;
    }
    return res;
}
ll ebob(ll a, ll b){
	if(!a)return b;
	return ebob(b%a, a);
}
ll ekok(ll a, ll b){
	return (((a*b)%mod)*(exp(ebob(a,b), (ll)mod-2))) % mod;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string k; ll d; cin>>k>>d;
	ll dp[k.size()][d][2] = {};
	ll sum = 0;
	ll tmp1[10] = {};
	for(int j = 0; j < 10; j++){
		tmp1[j%d]++;
	}
	for(int i = 0; i < k.size(); i++){
		sum += k[i] - '0';
		if(i == 0){
			for(int j = 0; j < k[i] - '0'; j++){
				dp[i][j%d][0]++;
			}
			dp[i][sum % d][1]++;
			continue;
		}
		dp[i][sum%d][1]++;
		ll tmp2[k[i] - '0'] = {};
		for(int j = 0; j < k[i] - '0'; j++){
			tmp2[j%d]++;
		}
		
		for(int j = 0; j < d; j++){
			for(int m = 0; m < 10; m++){
				dp[i][(j+m)%d][0] = (dp[i][(j+m)%d][0] + dp[i-1][j][0] * tmp1[m] + mod) % mod;
			}
			for(int m = 0; m < k[i] - '0'; m++){
				dp[i][(j+m)%d][0] = (dp[i][(j+m)%d][0] + dp[i-1][j][1] * tmp2[m] + mod) % mod;
			}
		}
	}
	//-1 is for 00000...0
	cout<<(dp[k.size()-1][0][0] + dp[k.size()-1][0][1] - 1 + mod) % mod;
	return 0;
}
