#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define llint long long
#define inf (llint)1e18

using namespace std;
typedef pair<llint, llint> P;

int n;
llint a[100005];
P dp[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], a[i] *= -1;
	
	for(llint i = 1; i <= n; i++) dp[i] = make_pair(inf, inf);
	dp[0] = make_pair(-inf, -inf);
	for(llint i = 1; i <= n; i++){
		*lower_bound(dp, dp+n+1, make_pair(a[i], i)) = make_pair(a[i], i);
	}
	cout << lower_bound(dp, dp+n+1, make_pair(inf, 0LL)) - dp - 1 << endl;
	//for(int i = 0; i <= n; i++) cout << dp[i] << " "; cout << endl;
	
	return 0;
}