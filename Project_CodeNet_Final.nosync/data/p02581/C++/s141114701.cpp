#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	Int n; cin >> n;
	vector<Int> a(3*n);
	for(auto &i:a) cin >> i;
	for(auto &i:a) --i;
	vector<vector<Int>> dp(n, vector<Int>(n, -1e9));
	Int m = -1e9;
	vector<Int> mx(n, -1e9);
	vector<Int> my(n, -1e9);

	dp[a[0]][a[1]] = 0;
	m = 0;
	mx[a[0]] = 0;
	my[a[1]] = 0;
	Int ans = 0;
	for(int i=0; i<n-1; ++i){
		queue<tuple<Int, Int, Int>> qu;
		Int p = a[3*i+2], q = a[3*i+3], r = a[3*i+4];

		if(p==q && q==r){
			++ans;
			continue;
		}

		qu.push(make_tuple(p, q, max({dp[p][q], dp[r][r] + 1, m})));
		qu.push(make_tuple(q, p, max({dp[q][p], dp[r][r] + 1, m})));
		qu.push(make_tuple(q, r, max({dp[q][r], dp[p][p] + 1, m})));
		qu.push(make_tuple(r, q, max({dp[r][q], dp[p][p] + 1, m})));
		qu.push(make_tuple(r, p, max({dp[r][p], dp[q][q] + 1, m})));
		qu.push(make_tuple(p, r, max({dp[p][r], dp[q][q] + 1, m})));

		for(int x=0; x<n; ++x){
			if(q == r){
				qu.push(make_tuple(x, p, max(dp[x][p], dp[x][q] + 1)));
				qu.push(make_tuple(p, x, max(dp[p][x], dp[x][q] + 1)));
			}
			if(r == p){
				qu.push(make_tuple(x, q, max(dp[x][q], dp[x][r] + 1)));
				qu.push(make_tuple(q, x, max(dp[q][x], dp[x][r] + 1)));
			}
			if(p == q){
				qu.push(make_tuple(x, r, max(dp[x][r], dp[x][p] + 1)));
				qu.push(make_tuple(r, x, max(dp[r][x], dp[x][p] + 1)));
			}
			qu.push(make_tuple(x, p, mx[x]));
			qu.push(make_tuple(p, x, mx[x]));
			qu.push(make_tuple(x, q, mx[x]));
			qu.push(make_tuple(q, x, mx[x]));
			qu.push(make_tuple(x, r, mx[x]));
			qu.push(make_tuple(r, x, mx[x]));
		}
		for(int y=0; y<n; ++y){
			if(q == r){
				qu.push(make_tuple(y, p, max(dp[y][p], dp[q][y] + 1)));
				qu.push(make_tuple(p, y, max(dp[p][y], dp[q][y] + 1)));
			}
			if(r == p){
				qu.push(make_tuple(y, q, max(dp[y][q], dp[r][y] + 1)));
				qu.push(make_tuple(q, y, max(dp[q][y], dp[r][y] + 1)));
			}
			if(p == q){
				qu.push(make_tuple(y, r, max(dp[y][r], dp[p][y] + 1)));
				qu.push(make_tuple(r, y, max(dp[r][y], dp[p][y] + 1)));
			}
			qu.push(make_tuple(y, p, my[y]));
			qu.push(make_tuple(p, y, my[y]));
			qu.push(make_tuple(y, q, my[y]));
			qu.push(make_tuple(q, y, my[y]));
			qu.push(make_tuple(y, r, my[y]));
			qu.push(make_tuple(r, y, my[y]));
		}

		while(!qu.empty()){
			tuple<Int, Int, Int> t = qu.front();
			qu.pop();
			dp[get<0>(t)][get<1>(t)] = max(dp[get<0>(t)][get<1>(t)], get<2>(t));
			m = max(m, dp[get<0>(t)][get<1>(t)]);
			mx[get<0>(t)] = max(mx[get<0>(t)], dp[get<0>(t)][get<1>(t)]);
			my[get<1>(t)] = max(my[get<1>(t)], dp[get<0>(t)][get<1>(t)]);
		}
	}

	Int ma = 0;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			ma = max(ma, dp[i][j] + (i==j && j==a[3*n-1]));
	ans += ma;
	cout << ans << "\n";
}