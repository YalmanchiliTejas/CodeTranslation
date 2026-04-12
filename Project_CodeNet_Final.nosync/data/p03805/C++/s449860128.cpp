#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	vector<int> p(n);
	rep(i,0,n)p[i] = i;
	int g[n][n] = {};
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		--x,--y;
		g[x][y] = g[y][x] = 1;
	}
	int cnt = 0;
	do {
		bool valid = p[0] == 0;	
		rep(i,0,n-1){
			valid &= g[p[i]][p[i+1]];
		}
		cnt += valid;
	} while(next_permutation(all(p)));
	cout << cnt << '\n';
}
