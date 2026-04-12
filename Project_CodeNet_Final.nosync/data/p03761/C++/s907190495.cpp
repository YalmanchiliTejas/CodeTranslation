#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()
#define INF (1<<20)
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<string> S(n);
	rep (i, n){
		cin >> S[i];
	} // end rep

	int cnt[50][26];
	memset(cnt, 0, sizeof(cnt));
	rep (i, n){
		int m = (int)S[i].length();
		rep (j, m){
			++cnt[i][(int)(S[i][j] - 'a')];
		} // end rep
	} // end rep

	int minSum[26];
	rep (i, 26) minSum[i] = INF;
	rep (j, 26){
		rep (i, n){
			minSum[j] = min(minSum[j], cnt[i][j]);
		} // end rep
	} // end rep

	string res = "";
	rep (i, 26){
		rep (j, (int)minSum[i]){
			res += (char)('a' + i);
		} // end rep
	} // end rep
	cout << res << endl;
	
	return 0;
}