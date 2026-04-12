// OBツ嘉ッツ嘉債宿2011 Day3 C : On or Off

#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
	int R, C, M;
	int pow[50][50], on[50][50], off[50][50];
	long long cost[2][50][50], time[50][50];
	int prev[50*50];
	string mp[50];
	while(cin >> R >> C >> M){
		memset(cost, 0, sizeof(cost));
		memset(time, 0, sizeof(time));
		for(int i=0;i<R;i++) cin >> mp[i];
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++) cin >> pow[i][j];
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++) cin >> on[i][j], cost[0][i][j] = on[i][j];
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++) cin >> off[i][j], time[i][j] = -1000000007;
		int px, py, cx, cy; cin >> cx >> cy;
		int t = 0;
		for(int i=1;i<M;i++){
			px = cx, py = cy;
			cin >> cx >> cy;
			if(px==cx && py==cy) continue;
			queue< pair<int,int> > qu; qu.push(make_pair(cx, cy));
			memset(prev, -1, sizeof(prev));
			prev[cx*C+cy] = -2;
			while(!qu.empty()){
				pair<int,int> pr = qu.front(); qu.pop();
				for(int j=0;j<4;j++){
					int x = pr.first+dx[j], y = pr.second+dy[j];
					if(x<0||R<=x||y<0||C<=y||mp[x][y]=='#') continue;
					if(prev[x*C+y]==-1){
						prev[x*C+y] = pr.first*C+pr.second;
						qu.push(make_pair(x,y));
					}
				}
			}
			for(int cur=px*C+py;prev[cur]!=-2;cur=prev[cur]){
				int x = cur/C, y = cur%C;
				cost[0][x][y] = min(cost[0][x][y]+(t-time[x][y])*pow[x][y], cost[1][x][y]+on[x][y]);
				cost[1][x][y] = cost[0][x][y]+off[x][y];
				time[x][y] = t++;
			}
		}
		cost[0][cx][cy] = min(cost[0][cx][cy]+(t-time[cx][cy])*pow[cx][cy], cost[1][cx][cy]+on[cx][cy]);
		cost[1][cx][cy] = cost[0][cx][cy]+off[cx][cy];
		time[cx][cy] = t;

		int res = 0;
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++) res += cost[1][i][j];
		cout << res << endl;
	}
}