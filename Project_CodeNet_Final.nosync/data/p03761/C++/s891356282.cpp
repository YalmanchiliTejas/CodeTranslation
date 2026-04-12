#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
	int n;
	cin >> n;
	string s[n];
	REP(i,n) cin >> s[i];
	int cnt[n][26] = {};
	REP(i,n) REP(j,s[i].length()) cnt[i][s[i][j] - 'a']++;
	int ans[26];
	REP(i,26) ans[i] = INF;
	REP(i,n) REP(j,26) ans[j] = min(ans[j], cnt[i][j]);
	string res;
	REP(i,26) REP(j,ans[i]) res += 'a' + i;
	cout << res << endl;
}