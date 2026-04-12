#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
constexpr int MOD = 1000000007;
constexpr int INF = numeric_limits<int>::max() / 2;
typedef pair<int,int> P;
using Graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int H, W;
	cin >> H >> W;
	char c[H][W];
	int ans = 0;
	rep(i,H){
		rep(j,W){
			cin >> c[i][j];
			if(c[i][j] == '#') ++ans;
		}
	}
	if(ans == H+W-1) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}