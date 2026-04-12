#include<bits/stdc++.h>
using namespace std;

int N;

int compress(vector<int> &ox, vector<int>& nx){
	vector<int> x;
	for(auto v : ox){
		x.push_back(v - 1);
		x.push_back(v);
		x.push_back(v + 1);
	}

	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	nx.resize(ox.size());
	for(int i = 0; i < ox.size(); i++){
		nx[i] = (lower_bound(x.begin(), x.end(), ox[i]) - x.begin());
	}
	return x.size();
}

int field[500][500];
int DX[] = {1, 0, -1, 0};
int DY[] = {0, 1, 0, -1};
int W;
int H;

void dfs(int x, int y){
	if(0 <= x && x < W && 0 <= y && y < H){
		if(field[y][x] != 0) return;
		field[y][x] = 2;
		for(int i = 0; i < 4; i++){
			dfs(x + DX[i], y + DY[i]);
		}
		return;
	}
}

int main(){
	vector<int> x, cx;
	vector<int> y, cy;

	while(cin >> N, N){
		x.clear();
		cx.clear();
		cy.clear();
		y.clear();

		for(int i = 0; i < N; i++){
			int l, t, r, b;
			cin >> l >> t >> r >> b;
			l *= 2;
			t *= 2;
			r *= 2;
			b *= 2;
			x.push_back(l);
			x.push_back(r);
			y.push_back(t);
			y.push_back(b);
		}

		W = compress(x, cx);
		H = compress(y, cy);
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				field[i][j] = 0;
			}
		}
		for(int i = 0; i < N; i++){
			int l = cx[i * 2];
			int r = cx[i * 2 + 1];
			int t = cy[i * 2];
			int b = cy[i * 2 + 1];
			for(int j = l; j <= r; j++){
				field[t][j] = 1;
				field[b][j] = 1;
			}
			for(int j = b; j <= t; j++){
				field[j][l] = 1;
				field[j][r] = 1;
			}
		}
		int ans = 0;
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				if(field[i][j] == 0){
					dfs(j, i);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}

}