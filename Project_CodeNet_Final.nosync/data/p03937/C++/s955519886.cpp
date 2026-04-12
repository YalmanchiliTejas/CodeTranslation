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
	vector<vector<char>> a(h+1, vector<char>(w+1, '.'));
	rep(i,h)rep(j,w) cin >> a[i][j];
	queue<P> que;
	que.push(P(0, 0));
	while(!que.empty()){
		P p = que.front();
		que.pop();
		a[p.first][p.second] = '.';
		int ny = p.first + 1, nx = p.second;
		if(ny < h && a[ny][nx] == '#'){
			que.push(P(ny, nx));
			continue;
		}
		ny = p.first; nx = p.second + 1;
		if(nx < w && a[ny][nx] == '#'){
			que.push(P(ny, nx));
		}
	}
	rep(i,h)rep(j,w){
		if(a[i][j] == '#'){
			cout << "Impossible" << endl;
			return 0;
		}
	}
	cout << "Possible" << endl;
	return 0;
}