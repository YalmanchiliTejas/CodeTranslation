#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll oo = 1e18;
const int mod = 1e9+7;
const int maxn = 1e4 + 50;

string k;
int d,n;
ll dp[maxn][110][2];

ll calc(int idx,int r,bool e){
	if(idx == n)return (r == 0);
	ll &ret = dp[idx][r][e];
	if(ret != -1)return ret;
	ret = 0;
	for(int i=0;i<10;i++){
		if(i > k[idx] - '0' && e)continue;
		bool q = e;
		if(i < k[idx] - '0')q = 0;
		ret = (ret + calc(idx + 1,(r + i)%d, q)) % mod;
	}
	return ret;
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>k>>d;
	n = k.size();
	cout << (calc(0,0,1) - 1 + mod)%mod << endl;
}