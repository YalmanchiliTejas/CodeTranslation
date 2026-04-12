#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	int h,w;
	cin >> h >> w;
	vector<string> grid(h);
	rep(i,h) cin >> grid[i];
	vector<bool> flagh(h), flagw(w);
	rep(i,h){
		flagh[i] = true;
		rep(j,w) {
			if(grid[i][j] == '#') {
				flagh[i] = false;
			}
		}
	}
	rep(i,w) {
		flagw[i] = true;
		rep(j,h) {
			if(grid[j][i] == '#') {
				flagw[i] = false;
			}
		}
	}
	rep(i,h) {
		rep(j,w) {
			if(flagh[i] == false && flagw[j] == false) cout << grid[i][j];
		}
		if(flagh[i] == false) cout << endl;
	}

  return 0;
}
