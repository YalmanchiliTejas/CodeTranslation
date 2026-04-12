#include <bits/stdc++.h>
using namespace std;
#define FOR(i, o, n) for (auto i = (o); (i) < (n); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (auto i = (n)-1; (i) >= 0; --i)
#define REPI(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define REPIR(itr, v) for (auto itr = v.rbegin(); itr != v.rend(); ++itr)
#define fi first
#define se second
#define ll long long
#define V2(name, h, w) vector<vector<int> > name((h), vector<int>(w));
int main(){
	int H, W; cin >> H >> W;
	string S[H]; 
	REP(i,H) cin >> S[i];

	vector<bool> vh(H), vw(W);
	REP(i,H){
		REP(j,W){
			if(S[i][j] == '#') vh[i] = true, vw[j] = true;
		}
	}

	REP(i,H){
		if(vh[i]){
			REP(j,W){
				if(vw[j]){
					cout << S[i][j];
				}
			}cout << endl;
		}
	}
}
