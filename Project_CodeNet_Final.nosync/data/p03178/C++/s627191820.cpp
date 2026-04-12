#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
char num[10010];
ll dp[10010][2][101];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>num; int len = strlen(num);
	vector<int> digit;
	for(int i=0; i<len; i++) digit.push_back(num[i]-'0');

	int D; cin>>D;
	dp[len][0][0]=dp[len][1][0] = 1ll;

	for(int idx=len-1; idx>=0; idx--)
		for(int k =0; k<2; k++)
			for(int md = 0; md<D; md++) {
				int lmt = k? digit[idx]:9;
				for(int i=0; i<=lmt; i++) {
					dp[idx][k][(md+i)%D]+=dp[idx+1][k and i==lmt][md];
					if(dp[idx][k][(md+i)%D]>=mod) dp[idx][k][(md+i)%D]-=mod;
				}
			}

	ll ans = dp[0][1][0]-1ll;
	if(ans<0ll) ans+=mod;
	cout << ans << '\n';

	return 0;
}