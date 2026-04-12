#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<tuple>
#include<map>
#include<set>
#include<algorithm>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

bool edge[9][9];
int ans = 0;
int n, m;

void solve(int p, vector<bool> v, int count){
	if(count == n){
		ans++;
		return;
	}
	reppp(i, 1, n){
		if(edge[p][i] && !v[i]){
			vector<bool> w(v);
			w[i] = true;
			solve(i, w, count+1);
		}
	}
	return;
}

signed main(){
	cin >> n >> m;
	fill(edge[0], edge[9], false);
	rep(m){
		int a, b;
		cin >> a >> b;
		edge[a][b] = true;
		edge[b][a] = true;
	}
	vector<bool> v(n+1, false);
	v[1] = true;
	solve(1, v, 1);
	cout << ans;
}
