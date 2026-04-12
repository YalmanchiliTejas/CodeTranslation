#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int vis[10010][110];
long long dp[10010][110];
string s;
int d;

long long dfs(int len, int mod, int pd){
//	cout << "  " << len << " " << mod << " " << pd << endl;
	if (len == -1) return mod == 0;
	if (!pd && vis[len][mod]) return dp[len][mod];
	long long cnt = 0;
	int maxj = pd ? s[len] - '0' : 9;
//	cout << "    " << (int)s[len] - '0' << endl;
	for (int i = 0; i <= maxj; i++){
//		cout << "    " << i << endl;
		cnt = (cnt + dfs(len - 1, (mod + i) % d, pd && i == maxj)) % MOD;
	}
	if (!pd) dp[len][mod] = cnt, vis[len][mod] = 1;
	return cnt;
}

char buf[10010];

int main(){
	scanf("%s", buf);
	s = buf;
	scanf("%d", &d);
	reverse(s.begin(), s.end());
//	cout << "s:" << s << endl;
//	cout << "  " << s[1] << endl;
//	cout << "  s.length():" << s.length() << endl;
	printf("%d\n", (dfs(s.length() - 1, 0, 1) - 1 + MOD) % MOD);
	return 0;
}