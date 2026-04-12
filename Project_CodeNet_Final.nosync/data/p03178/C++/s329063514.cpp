#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

// http://luzhiled.hatenablog.com/entry/2017/12/03/124453
string N;
int D;
int dp[10002][2][102];
int rec(int k = 0, bool tight = true, int sum = 0){
	if(k==N.size())return sum%D==0;
	int x = N[k] - '0';
	int r = (tight ? x:9);
	int &res = dp[k][tight][sum];
	if(~res) return res;
	res = 0;
	for(int i=0;i<=r;++i){
		(res += rec(k+1,tight&&i==r,(sum+i)%D) ) %= MOD;
	}
	return res;
}

int main(){
	cin >> N >> D;
	memset(dp, -1, sizeof(dp));
	cout << (rec()-1+MOD)%MOD << endl;
}
