/*
Dear ToM,
Congratulations on your graduation!
You did a great job!
     ☆ﾟ*＠*ﾟ☆
　　(＠*｡☆｡*＠
　 /☆｡*＠ﾟ*☆
▲/／｡＠｡*☆＠*
　▼―ｰ｡*＠ﾟ*☆
*/

#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,n) for(int i=s; i<n; ++i)
#define rep(i,n) REP(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false

typedef long long ll;
typedef pair<int, int> ii;

int main(){
	ll v, e;
	cin >> v >> e;
	vector<vector<int>> g(v);
	char cs[v];
	rep(i, v){
		cin >> cs[i];
	}
	rep(i, e){
		int s, t;
		cin >> s >> t;
		g[s].push_back(t);
		g[t].push_back(s);
	}

	rep(i, v){
		if(cs[i] != '?') continue;
		vector<bool> f(26, true);
		rep(j, (int)g[i].size()){
			if(cs[g[i][j]] == '?') continue;
			f[cs[g[i][j]] - 'a'] = false;
		}
		rep(j, (int)f.size()){
			if(f[j]){
				cs[i] = char('a' + j);
				break;
			}
		}
	}

	rep(i, v) cout << cs[i];
	cout << endl;

	return 0;
}

