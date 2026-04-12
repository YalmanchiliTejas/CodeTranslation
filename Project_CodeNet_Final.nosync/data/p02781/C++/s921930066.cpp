#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

string n;
int k;
ll dp[101][2][4];

ll rec(int digit, bool tight, int sum){
    if(dp[digit][tight][sum] != -1){
        return dp[digit][tight][sum];
    }
	if(digit == n.size()){
		return sum == 0;
	}
	int x = n[digit] - '0';
	int lim = (tight ? x : 9);
	ll res = 0;
	for(int i = 0; i <= lim; i++){
        if(i == 0){
            res += rec(digit + 1, tight && i == lim, sum);
        }else{
            if(sum - 1 < 0) continue;
            res += rec(digit + 1, tight && i == lim, sum - 1);
        }
	}
	return dp[digit][tight][sum] = res;
}

signed main(){
    cin >> n;
    cin >> k;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, k) << endl;
    return 0;
}