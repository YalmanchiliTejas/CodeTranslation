#include <iostream>
#include <map>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

const int inf = 1e6;

typedef long long ll;

int n, m, w, t;
map<string, int> s;
int v[7];
int p[7];
int x[8];
int y[8];
int q[7][7];
int ptrl[1 << 7];
int dpw[1 << 7][8][10001];
ll dpt[(1 << 7) + 1][10001];

int dist(int i, int j){
	int dx = x[i] - x[j];
	int dy = y[i] - y[j];
	return abs(dx) + abs(dy);
}

void patrol(int i, int d, int v){
	if(i == n && v & 1 << i){
		int w = v - (1 << i);
		ptrl[w] = min(d, ptrl[w]);
		return;
	}
	rep(j, n + 1){
		if(!(v & 1 << j)){
			patrol(j, d + dist(i, j), v + (1 << j));
		}
	}
}

void knapsack_weight(){
	for(int i = 0; i < 1 << n; ++i){
		int mp[7];
		fill_n(mp, m, 0);
		rep(j, n){
			if(!(i & 1 << j)){
				continue;
			}
			rep(k, m){
				mp[k] = max(q[j][k], mp[k]);
			}
		}

		for(int j = 1; j <= m; ++j){
			rep(k, w + 1){
				dpw[i][j][k] = dpw[i][j - 1][k];
				if(k >= v[j - 1]){
					dpw[i][j][k] = max(dpw[i][j][k - v[j - 1]] + mp[j - 1], dpw[i][j][k]);
				}
			}
		}
	}
}

void knapsack_time(){
	for(int i = 1; i <= 1 << n; ++i){
		rep(j, t + 1){
			dpt[i][j] = dpt[i - 1][j];
			if(j >= ptrl[i - 1]){
				dpt[i][j] = max(dpt[i][j - ptrl[i - 1]] + dpw[i - 1][m][w], dpt[i][j]);
			}
		}
	}
}

int main(){
	cin >> n >> m >> w >> t;
	rep(i, m){
		string k;
		cin >> k >> v[i] >> p[i];
		s[k] = i;
	}
	rep(i, n){
		fill_n(q[i], m, 0);
		int l;
		cin >> l >> x[i] >> y[i];
		rep(j, l){
			string r;
			int x;
			cin >> r >> x;
			int k = s[r];
			q[i][k] = p[k] - x;
		}
	}

	fill_n(ptrl, 1 << n, inf);
	patrol(n, 0, 0);
	
	knapsack_weight();
	knapsack_time();

	cout << dpt[1 << n][t] << endl;
	return 0;
}