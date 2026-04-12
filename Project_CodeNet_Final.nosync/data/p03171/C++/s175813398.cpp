#include<bits/stdc++.h>
using namespace std;
vector<long long> factors;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define _ <<'\n'
#define __ << ' '
#define all(x) (x).begin(), (x).end()
#define gcd __gcd
int IT_MAX = 1 << 17;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double ERR = 1e-10;
#define szz(x) (int)(x).size()
#define IOS ios_base::sync_with_stdio(false); cout.tie(0);cin.tie(0);
vector<ll> a;
ll dp[3003][3003] = {-1};
int n;

ll count(ll l,ll r){
	if(dp[l][r] != -LL_INF){
		return dp[l][r];
	}else{
		if((r - l + 1)%2 == n % 2){
			if(l == r)
				dp[l][r] = a[l];
			else{
				dp[l][r] = max(count(l + 1,r) + a[l],count(l,r-1) + a[r]);
			}
		}else{
			if(l == r)
				dp[l][r] = -a[l];
			else{
				dp[l][r] = min(count(l + 1,r) - a[l],count(l,r-1) - a[r]);
			}
		}
	}
	return dp[l][r];
}

int main()
{
	IOS
	for(int i = 0 ;i < 3003; ++i){
		for(int j = 0;j < 3003; ++j){
			dp[i][j] = -LL_INF;
		}
	}
	cin >> n;
	a.resize(n + 1);
	for(int i = 1;i < n+1; ++i){
		cin>> a[i];
	}

	cout << count(1,n);

	return 0;
}