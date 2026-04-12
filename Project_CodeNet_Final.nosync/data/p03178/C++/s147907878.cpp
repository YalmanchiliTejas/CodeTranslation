#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

int memo[10010][110][2], n, d; // pos, sum, even

string k;

int dp(int pos, int sum, int even) {
	if(pos == n) return (sum ? 0 : 1);	
	int& p = memo[pos][sum][even];
	if(p != -1) return p;
	
	int ret = 0;
	if(even) {
		for(int i=0; i <= (k[pos] - '0'); i++) {
			if(i == k[pos]-'0') 
				ret = (ret + dp(pos+1, (sum + i) % d, 1)) % MOD;
			else 
				ret = (ret + dp(pos+1, (sum + i) % d, 0)) % MOD;
		}
	}
	else {
		for(int i=0; i<10; i++)
			ret = (ret + dp(pos+1, (sum + i) % d, 0)) % MOD;
	}

	return p = ret;
}

int main(){ _

	cin >> k >> d;

	n = k.size();

	memset(memo, -1, sizeof memo);

	cout << ((dp(0, 0, 1)-1) % MOD + MOD ) % MOD << endl;

	return 0;
}
