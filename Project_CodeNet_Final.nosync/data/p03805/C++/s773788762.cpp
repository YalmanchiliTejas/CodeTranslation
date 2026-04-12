#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<climits>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<iomanip>
using namespace std;

#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define rep2(i,j,n) for(int i=(j);i<=(n);i++)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define INF 1e9

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pi;
typedef long long i64;
typedef vector<long long int> vll;

int n, m;
vi a, b;
vi k;
int ans = 0;

void dfs(int x) {
	if (k[x]) return;
	k[x] = true;
	if (count(all(k), true) == n) {
		ans++;
		k[x] = false;
		return;
	}
	rep(i, 0, m) {
		if (a[i] == x) dfs(b[i]);
		else if (b[i] == x) dfs(a[i]);
	}
	k[x] = false;
}

int main() {
	cin >> n >> m;
	a.resize(m);
	b.resize(m);
	k.resize(n + 1, false);
	rep(i, 0, m) {
		cin >> a[i] >> b[i];
	}
	dfs(1);
	cout << ans << endl;
}