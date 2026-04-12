#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9+7;
const int N = 1e6+5;

int mpow(int x, int y) {
	int res = 1;
	while(y>0) {
		if(y&1) {
			res = (res*x)%MOD;
		}
		x = (x*x)%MOD;
		y/=2;
	}
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	int ans = 0;
	int x;
	int sq = 0;
	while(n--) {
		cin>>x;
		ans+=x;
		ans%=MOD;
		sq = (sq+(x*x)%MOD)%MOD;
	}	
	ans= (ans*ans+MOD-sq)%MOD;
	cout<<(ans*mpow(2,MOD-2))%MOD;

	return 0;
}