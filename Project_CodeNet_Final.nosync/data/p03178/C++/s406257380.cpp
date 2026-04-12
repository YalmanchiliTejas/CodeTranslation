#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

string k;
int d, n;
ll dp[100005][105][2];
const ll mod = (ll)1e9 + 7;

ll rek(int x, int sad, bool p){
	if(x == n)
		return (sad == 0);
	ll &ret = dp[x][sad][p];
	if(ret != -1)
		return ret;
	ret = 0;
	int gr = (p ? k[x] - '0' : 9);
	for(int i = 0 ; i <= gr ; ++i){
		ret = (ret + rek(x + 1, (sad + i) % d, (i == gr ? p : 0))) % mod;
	}
	return ret;
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin >> k;
cin >> d;
n = (int)k.size();
memset(dp, -1, sizeof(dp));
ll t = (rek(0, 0, 1) - 1 + mod) % mod; 
cout << t << endl;

return 0;
}

