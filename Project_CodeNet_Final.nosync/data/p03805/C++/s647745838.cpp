#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>
using namespace std;

#define rep(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define SZ(x) ((int) (x).size())
typedef long long ll;

const int N = 10 + 5;
bool f[N];
vector<int> G[N];
int ans, n, m;
void dfs(int u) {
	f[u] = 1;
	bool last = 1;
	rep(i,0,SZ(G[u])) {
		int v = G[u][i];
		if(!f[v]) dfs(v), last = 0;
	}
	if(last && accumulate(f, f + n, 0) == n) ans++;
	f[u] = 0;
}
int main(){
	cin >> n >> m;
	ans = 0;
	rep(i,0,m) {
		int a, b;
		cin >> a >> b;
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
	}
	memset(f, 0, sizeof(f));
	dfs(0);
	cout << ans << endl;
    return 0;
}
