#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
	int n; cin >> n;
	string S[n];
	rep(i, n) cin >> S[i];
	int cnt[n][26] = {};
	rep(i, n) {
		rep(j, S[i].length()) {
			cnt[i][S[i][j] - 'a']++;
		}
	}
	rep(i, 26) {
		int tmp = 1000;
		rep(j, n) {
			tmp = min(tmp, cnt[j][i]);
		}
		while (tmp--) cout << (char)('a' + i);
	}
	cout << endl;


    return 0;
}
