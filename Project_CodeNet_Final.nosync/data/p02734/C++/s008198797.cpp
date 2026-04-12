#include <iostream>

using namespace std;

typedef long long ll;
#define x first
#define y second
#define mp make_pair

const int MAXN = 3000;
const ll mod = 998244353LL;
int n, s, a[MAXN + 5];
ll dp[MAXN + 5];

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin >> n >> s;
ll sol = 0;
for(int i = 1 ; i <= n ; ++i){
	int x;
	cin >> x;
	if(x > s)
		continue;
	dp[0] = i;
	sol = (sol + (dp[s - x] * (ll)(n - i + 1)) % mod) % mod;
	for(int j = s ; j >= x ; --j){
		dp[j] = (dp[j] + dp[j - x]) % mod;
	}
}
cout << sol << endl;

return 0;
}

