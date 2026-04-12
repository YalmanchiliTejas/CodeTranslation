#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int h, w;
	cin >> h >> w;

	string a[h];
	rep(i, h) cin >> a[i];

	bool b[h][w];
	rep(i, h) rep(j, w) b[i][j] = true;

	rep(i, h){
		bool flg = true;
		rep(j, w){
			if(a[i][j] == '#') {
				flg = false;
				// cout << i << "," << j << endl;
				break;
			}
		}

		if(flg){
			rep(j, w) b[i][j] = false;
		}
	}

	rep(j, w){
		bool flg = true;
		rep(i, h){
			if(a[i][j] == '#') {
				flg = false;
				break;
			}
		}

		if(flg){
			rep(i, h) b[i][j] = false;
		}
	}

	// rep(i, h) rep(j, w) cout << b[i][j] << (j == w-1 ? "\n": "");

	rep(i, h){
		bool flg = false;
		rep(j, w){
			if(b[i][j]) {
				flg = true;
				cout << (""s + a[i][j]);
			}
		}
		if(flg) cout << endl;
	}
}