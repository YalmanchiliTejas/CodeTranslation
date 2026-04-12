#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

int n;
ll a[3005], dp[3005][3005];
const ll inf = 1e15;

ll rek(int l, int r){
	if(l > r)
		return 0;
	ll &ret = dp[l][r];
	if(ret != -1)
		return ret;
	ret = (((r - l + 1) & 1) == (n & 1) ? max(rek(l + 1, r) + a[l], rek(l, r - 1) + a[r]) : min(rek(l + 1, r) - a[l], rek(l, r - 1) - a[r]));
	return ret;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin >> n;
for(int i = 1 ; i <= n ; ++i){
	cin >> a[i];
}
memset(dp, -1, sizeof(dp));
cout << rek(1, n) << endl;

return 0;
}

