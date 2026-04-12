//EDPC S
#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

string k;
int d;
ll dp[10001][2][101];

ll rec(int digit, bool tight, int sum){
    if(dp[digit][tight][sum] != -1){
        return dp[digit][tight][sum];
    }
	if(digit == k.size()){
		return sum == 0;
	}
	int x = k[digit] - '0';
	int lim = (tight ? x : 9);
	ll res = 0;
	for(int i = 0; i <= lim; i++){
		res += rec(digit + 1, tight && i == lim, (sum + i) % d);
		res %= MOD;
	}
	return dp[digit][tight][sum] = res;
}

signed main(){
	cin >> k;
    cin >> d;
    memset(dp, -1, sizeof(dp));
	cout << (rec(0, 1, 0) - 1 + MOD) % MOD << endl;
	return 0;
}