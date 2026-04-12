#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF 100000000
#define EPS 1e-10
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;

int dr[4] = {1,0,-1,0};
int dc[4] = {0,1,0,-1};

int r, c, m;
vector<int> t[50][50];
char brd[50][50];
int x[3][50][50];


queue<P> que;
int dist[50][50];

int main(){
	cin >> r >> c >> m;
	rep(i,r) rep(j,c){
		cin >> brd[i][j];
	}
	rep(i,3) rep(j,r) rep(k,c) cin >> x[i][j][k];
	P st;
	int ti = 0;
	rep(i,m){
		P en;
		cin >> en.first >> en.second;
		if(i == 0){
			st = en;
			t[st.first][st.second].push_back(ti);
			continue;
		}
		rep(j,r) rep(k,c) dist[j][k] = INF;
		dist[st.first][st.second] = 0;
		que.push(st);
		while(true){
			if(que.size() == 0) break;
			P q = que.front();
			que.pop();
			rep(i,4){
				if(0>q.first+dr[i]||q.first+dr[i]>=r) continue;
				if(0>q.second+dc[i]||q.second+dc[i]>=c) continue;
				if(brd[q.first+dr[i]][q.second+dc[i]] == '#') continue;
				if(dist[q.first+dr[i]][q.second+dc[i]] != INF) continue;
				dist[q.first+dr[i]][q.second+dc[i]] = dist[q.first][q.second]+1;
				que.push(P(q.first+dr[i],q.second+dc[i]));
			}
		}
		int rr = en.first, cc = en.second;
		while(true){
			if(dist[rr][cc] == 0) break;
			t[rr][cc].push_back(ti+dist[rr][cc]);
			rep(i,4){
				if(0>rr+dr[i]||rr+dr[i]>=r) continue;
				if(0>cc+dc[i]||cc+dc[i]>=c) continue;
				if(dist[rr+dr[i]][cc+dc[i]] == dist[rr][cc]-1){
					rr += dr[i];
					cc += dc[i];
					break;
				}
			}
		}
		ti += dist[en.first][en.second];
		st = en;
	}
	long long ans = 0;
	long long dp[2][1000];
	rep(i,r) rep(j,c){
		if(t[i][j].size() == 0) continue;
		if(t[i][j].size() == 1){
			ans += x[1][i][j]+x[2][i][j];
			continue;
		}
		rep(k,2) rep(u,1000) dp[k][u] = INF;
		rep(k,t[i][j].size()){
			if(k == 0){
				dp[0][0] = x[1][i][j]+x[2][i][j];
				dp[1][0] = x[1][i][j]+x[0][i][j]*(t[i][j][1]-t[i][j][0]);
				continue;
			}
			dp[0][k] = min(dp[0][k-1]+x[1][i][j]+x[2][i][j],dp[1][k-1]+x[2][i][j]);
			if(k != t[i][j].size()-1) dp[1][k] = min(dp[0][k-1]+x[1][i][j],dp[1][k-1])+x[0][i][j]*(t[i][j][k+1]-t[i][j][k]); 
		}
		ans += dp[0][t[i][j].size()-1];
	}
	cout << ans << endl;
}