#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

// http://luzhiled.hatenablog.com/entry/2017/12/03/124453
string N;
int K;
int dp[10002][2][5];

// k桁目
int rec(int k = 0, bool tight = true, int num = 0){
	if(num>K)return 0LL;
	if(k==N.size())return num==K;
	int x = N[k] - '0';
	int r = (tight ? x:9);
	int &res = dp[k][tight][num];
	if(~res) return res;
	res = 0;
	for(int i=0;i<=r;++i){
		(res += rec(k+1,tight&&i==r,(num+(i!=0))) ) %= MOD;
	}
	return res;
}

int main(){
	cin >> N >> K;
	memset(dp, -1, sizeof(dp));
	cout << rec() << endl;
}
