#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;
typedef pair<P, llint> E;

llint n;
llint a[6005];
llint dp[2005][2005];
llint rmax[2005], cmax[2005], gmax;
vector<E> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= 3*n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = -inf;
		}
	}
	dp[a[1]][a[2]] = 0;
	
	for(int i = 1; i <= n; i++) rmax[i] = cmax[i] = -inf;
	rmax[a[1]] = cmax[a[2]] = 0;
	
	llint add = 0;
	for(int i = 1; i <= n-1; i++){
		
		llint b[3] = {a[i*3], a[i*3+1], a[i*3+2]};
		vec.clear();
		
		if(b[0] == b[1] && b[1] == b[2]){
			add++;
			continue;
		}
		
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				if(j == k) continue;
				vec.push_back(E(P(b[j], b[k]), gmax));
				vec.push_back(E(P(b[j], b[k]), dp[b[3-(j+k)]][b[3-(j+k)]] + 1));
			}
		}
		
		for(int j = 1; j <= n; j++){
			for(int k = 0; k < 3; k++){
				vector<llint> tmp;
				for(int l = 0; l < 3; l++){
					if(k != l) tmp.push_back(b[l]);
				}
				vec.push_back(E(P(j, b[k]), rmax[j]));
				if(tmp[0] == tmp[1]) vec.push_back(E(P(j, b[k]), dp[j][tmp[0]] + 1));
			}
		}
		for(int j = 1; j <= n; j++){
			for(int k = 0; k < 3; k++){
				vector<llint> tmp;
				for(int l = 0; l < 3; l++){
					if(k != l) tmp.push_back(b[l]);
				}
				vec.push_back(E(P(b[k], j), cmax[j]));
				if(tmp[0] == tmp[1]) vec.push_back(E(P(b[k], j), dp[tmp[0]][j] + 1));
			}
		}
		
		for(int i = 0; i < vec.size(); i++){
			llint r = vec[i].first.first, c = vec[i].first.second, x = vec[i].second;
			chmax(dp[r][c], x), chmax(rmax[r], x), chmax(cmax[c], x), chmax(gmax, x);
		}
	}
	dp[a[3*n]][a[3*n]]++;
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			ans = max(ans, dp[i][j]);
		}
	}
	ans += add;
	cout << ans << endl;
	
	return 0;
}