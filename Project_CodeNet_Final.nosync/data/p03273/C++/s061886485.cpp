#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, w;
	cin >> h >> w;
	vector<vector<char>> c(h, vector<char>(w));
	rep(i,h)rep(j,w) cin >> c[i][j];
	vector<bool> tate(h, false), yoko(w, false);
	rep(i,h){
		bool none = true;
		rep(j,w){
			if(c[i][j] == '#') none = false;
		}
		if(none) tate[i] = true;
	}
	rep(j,w){
		bool none = true;
		rep(i,h){
			if(c[i][j] == '#') none = false;
		}
		if(none) yoko[j] = true;
	}
	rep(i,h){
		if(tate[i]) continue;
		rep(j,w){
			if(yoko[j]) continue;
			cout << c[i][j];
		}
		cout << endl;
	}
	return 0;
}