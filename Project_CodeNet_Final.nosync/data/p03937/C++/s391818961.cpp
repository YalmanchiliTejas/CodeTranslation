#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 60)

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int h , w;
string s[10];
void solve(){
	cin >> h >> w;
	for(int i = 0; i < h; i++){
		cin >> s[i];
	}
	
	int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
	queue<P> q;
	q.push(P(0,0));
	bool used[20][20] = {0};
	while(!q.empty()){
		P p = q.front(); q.pop();
		int x = p.first, y = p.second;
		int cnt = 0;
		used[x][y] = 1;
		for(int i = 0; i < 2; i++){
			int nx = x+dx[i], ny = y+dy[i];
			if(nx >= h || ny >= w) continue;
			if(s[nx][ny] == '#'){
				cnt++;
				q.push(P(nx,ny));
			}
			if(cnt > 1){
				cout << "Impossible" << endl;
				return;
			}
		}
	}
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(s[i][j] == '.') continue;
			if(used[i][j]) continue;
			cout << "Impossible" << endl;
			return;
		}
	}
	
	cout << "Possible" << endl;
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
