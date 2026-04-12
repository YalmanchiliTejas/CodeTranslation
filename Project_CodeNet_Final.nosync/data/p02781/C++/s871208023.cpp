#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[101][101][2];
ll digitDp(ll pos, ll nonzero, bool islimit, string num, ll k){
    if(pos > (int)num.size()){
        return (nonzero == k) ? 1 : 0;
    }
    if(dp[pos][nonzero][islimit]!=-1) return dp[pos][nonzero][islimit];
    ll res = 0, limit = 9;
    if(islimit) limit = (num[pos-1] - '0');
    for(ll i=0;i<=limit;i++){
        if(i == limit && islimit){
            if(i > 0) res += digitDp(pos+1, nonzero+1, true, num, k);
            else      res += digitDp(pos+1, nonzero, true, num, k);
        }
        else{
            if(i > 0) res += digitDp(pos+1, nonzero+1, false, num, k);
            else      res += digitDp(pos+1, nonzero, false, num, k);
        }
    }
    return dp[pos][nonzero][islimit] = res;
}

int main(void) {
	// your
	for(ll i=0;i<101;i++) for(ll j=0;j<101;j++) for(ll k=0;k<2;k++) dp[i][j][k] = -1;
	ll  k;
	string num;
	cin >> num;
	cin >> k;
	cout << digitDp(1, 0, true, num, k);
  //  cout << num << endl;
}
