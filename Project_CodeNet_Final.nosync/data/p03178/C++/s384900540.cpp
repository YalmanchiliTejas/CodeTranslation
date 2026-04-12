#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define sz size()
#define eps 0.000001
#define oo 2000000007
#define endl '\n'
#define bg begin()
#define nd end()
#define up upper_bound
#define lw lower_bound
#define debug(x) #x << " = " << x << "; "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

string s;
int D, N, MOD = 1e9+7;
const int MAX = 10e4+3;
int dp[MAX][101][2];

int f(int i, int mod, bool menor){
	if(i == N) return (mod == 0);
	int &ans = dp[i][mod][menor];
	if(ans != -1) return ans;
	ans = 0;
	if(menor){
		for(int d = 0; d < 10; d++){
			ans = (ans + f(i + 1, (mod + d)%D, menor)%MOD)%MOD;
		}
	}else{
		int p = s[i] - '0';
		for(int d = 0; d < p; d++){
			ans = (ans + f(i + 1, (mod + d)%D, !menor)%MOD)%MOD;
		}
		ans = (ans + f(i + 1, (mod + p)%D, menor)%MOD)%MOD;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> D;
	N = s.size();
	memset(dp, -1, sizeof(dp));
	int ans = f(0, 0, 0);
	cout << (ans - 1 + MOD)%MOD << endl;
}