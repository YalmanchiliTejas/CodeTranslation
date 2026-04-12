#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

vector<int> G[200];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	rep (i, 200) G[i].clear();
	int N; cin >> N;

	rep (i, N){
		for (int j = i + 1; j < N; ++j){
			string s(N, '0');
			s[i] = '1'; s[j] = '1';
			cout << "? " << s << endl;
			int d; cin >> d;
			if (d == 1){
				G[i].push_back(j);
			} // end if
		} // end for
	} // end rep
	
	vector<P> ans; ans.clear();
	rep (i, 200){
		if (G[i].empty()) continue;
		rep (j, (int)G[i].size()){
			ans.push_back(P(i, G[i][j]));
		} // end rep
	} // end rep

	cout << "! ";
	int m = (int)ans.size();
	rep (i,m){
		cout << '(' << ans[i].first << ',' << ans[i].second << ')' << (i != m - 1 ? ' ' : '\n');
	} // end rep
		
	return 0;
}