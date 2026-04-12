#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long ll;

vector<int> k;
int n, d;

ll memo[10005][105];

const ll mod = 1e9 + 7;

ll dp(int pos, int curmod){
	if(pos==n and curmod%d == 0)	return 1;
	if(pos==n)	return 0;
	if(memo[pos][curmod] != -1)	return memo[pos][curmod];
	memo[pos][curmod] = 0;
	for(int i = 0; i < 10; i++){
		memo[pos][curmod] = (memo[pos][curmod]+dp(pos+1, (curmod+i)%d))%mod; 
	}
	return memo[pos][curmod];
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(memo, -1, sizeof(memo));

	string s;
	cin >> s;
	cin >> d;
	n = s.length();

	for(int i = 0; i < s.length(); i++){
		k.PB(s[i] - '0');
	}

	ll ans = 0;
	int curmod = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k[i]; j++){
			ans = (ans + dp(i+1, (curmod + j)%d))%mod;
		}
		curmod = (curmod + k[i])%d;
	}
	if(curmod == 0)	ans = (ans + 1)%mod;

	cout << (ans-1 + mod)%mod << "\n";

	return 0;
}