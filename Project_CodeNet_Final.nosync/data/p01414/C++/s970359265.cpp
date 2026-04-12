#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int i = (s);i <= (e);i++)

int n;
vector<int> h,w;

vector<vector<int>> fie(4,vector<int>(4));

vector<int> dist(1 << 16,-1);

int main(){
	cin >> n;
	h.resize(n);
	w.resize(n);
	rep(i,0,n - 1) cin >> h[i] >> w[i];
	rep(i,0,3)rep(j,0,3){
		char c;
		cin >> c;
		if(c == 'R') fie[i][j] = 0;
		if(c == 'G') fie[i][j] = 1;
		if(c == 'B') fie[i][j] = 2;
	}
	queue<int> que;
	que.push(0);
	dist[0] = 0;

	while(!que.empty()){
		int v = que.front();
		que.pop();
		if(v == (1 << 16) - 1)
		{
			cout << dist[v] << endl;
			return 0;
		}
		rep(c,0,2) rep(s,0,n - 1){
			rep(i,-h[s] + 1,3) rep(j,-w[s] + 1,3){
				int u = v;
				rep(x,max(i,0),min(i + h[s] - 1,3)) rep(y,max(j,0),min(j + w[s] - 1,3)){
					int index = (x * 4 + y);
					if(u & (1 << index)){
						if(fie[x][y] != c) u ^= (1 << index);
					}
					else{
						if(fie[x][y] == c) u ^= (1 << index);
					}
				}
				if(dist[u] == -1){
					dist[u] = dist[v] + 1;
					que.push(u);
				}
			}
		}
	}
}

