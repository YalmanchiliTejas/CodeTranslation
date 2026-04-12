#include<bits/stdc++.h>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

string s[50];
int cnt[50][26];
int Min[26];
signed main() {
	int n; scanf("%d", &n);
	memset(Min, 0x3f, sizeof(Min));
	rep(i, n) {
		cin >> s[i];
		for (char c : s[i])cnt[i][c - 'a']++;
		rep(j, 26)Min[j] = min(Min[j], cnt[i][j]);
	}
	rep(i, 26)cout << string(Min[i], 'a' + i);
	cout << endl;
}