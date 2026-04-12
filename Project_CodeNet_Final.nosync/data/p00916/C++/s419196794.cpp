#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF 100000000
#define EPS 1e-10
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;
vector<int> x, y;
int l[50], t[50], r[50], b[50];
int used[500][500];

void solve(){
	x.clear(); y.clear();
	rep(i,500) rep(j,500) used[i][j] = 0;
	rep(i,n){
		cin >> l[i] >> t[i] >> r[i] >> b[i];
		x.push_back(l[i]); x.push_back(r[i]);
		y.push_back(t[i]); y.push_back(b[i]);
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	x.erase(unique(x.begin(),x.end()),x.end());
	y.erase(unique(y.begin(),y.end()),y.end());
	rep(i,n){
		rep(j,x.size()){
			if(l[i] == x[j]){
				l[i] = j;
				break;
			}
		}
		rep(j,x.size()){
			if(r[i] == x[j]){
				r[i] = j;
				break;
			}
		}
		rep(j,y.size()){
			if(t[i] == y[j]){
				t[i] = j;
				break;
			}
		}
		rep(j,y.size()){
			if(b[i] == y[j]){
				b[i] = j;
				break;
			}
		}
	}
	rep(i,n){
		l[i] *= 2; l[i] += 10;
		r[i] *= 2; r[i] += 10;
		t[i] *= 2; t[i] += 10;
		b[i] *= 2; b[i] += 10;
		for(int j = l[i]; j <= r[i]; j++) used[j][t[i]] = -1;
		for(int j = l[i]; j <= r[i]; j++) used[j][b[i]] = -1;
		for(int j = b[i]; j <= t[i]; j++) used[l[i]][j] = -1;
		for(int j = b[i]; j <= t[i]; j++) used[r[i]][j] = -1;
	}
	int cnt = 0;
	queue<P> que;
	rep(i,500) rep(j,500){
		if(used[i][j] != 0) continue;
		cnt++;
		used[i][j] = cnt;
		que.push(P(i,j));
		while(true){
			if(que.size() == 0) break;
			P q = que.front();
			que.pop();
			rep(k,4){
				if(0>q.first+dx[k]||q.first+dx[k]>=500) continue;
				if(0>q.second+dy[k]||q.second+dy[k]>=500) continue;
				if(used[q.first+dx[k]][q.second+dy[k]] != 0) continue;
				used[q.first+dx[k]][q.second+dy[k]] = cnt;
				que.push(P(q.first+dx[k],q.second+dy[k]));
			}
		}
	}
	/*
	rep(i,100){
		rep(j,100){
			if(used[i][j] == -1) cout << "Z";
			else cout << used[i][j];
		}
		cout << endl;
	}
	*/
	cout << cnt << endl;
}

int main(){
	while(cin >> n){
		if(n == 0) break;
		solve();
	}
}