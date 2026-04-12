#include<bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
typedef vector <int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int mod = 1e9 + 7;
const ll inf = 3e18 + 5;

int add(int a, int b) { return (a += b) < mod? a : a - mod; }

string S;
int d, n;
ll dp[10005][101][2];

ll f(int i, int sum, bool ok){
	if(i == n) return sum % d == 0;
	if(dp[i][sum][ok] != -1) return dp[i][sum][ok];
	ll ret = 0;
	for(int k = 0; k <= (!ok ? S[i] - '0' : 9); k++){
		ret = add(ret, f(i + 1, (sum + k) % d, (k == S[i] - '0' ? ok : 1)));
	}
	return dp[i][sum][ok] = ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> S >> d;
	n = S.size();
	memset(dp, -1, sizeof dp);
	cout << (f(0, 0, 0) - 1 + mod) % mod; 
}