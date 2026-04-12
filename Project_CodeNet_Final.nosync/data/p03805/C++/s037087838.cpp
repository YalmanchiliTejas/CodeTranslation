#include<string>
#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<functional>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include <string.h>
using ll = long long;

#define rep(i, n) for(ll i = 0; i < (int)(n); i++)
#define reps(i,x) for(ll i=1;i<=(int)(x);i++)
#define rrep(i,x) for(ll i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(ll i=((int)(x) - 1 * 100);i>0;i--)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
#define vll vector<ll>
#define vi vector<int>
#define mp make_pair
#define vpll vector<pair<ll,ll>>
#define vpi vector<pair<int,int>>
using namespace std;
ll n, m;
ll grp[9][9];
ll a, b;
ll ans = 0;

ll dfs(int v, ll visited[9]) {
	bool f = true;
	rep(i, n) {
		if (!visited[i]) {
			f = false;
			break;
		}
	}
	if (f) {
		return 1;
	}
	ll ans = 0;
	rep(i, n) {
		if (visited[i]) continue;
		if (!grp[v][i]) continue;
		visited[i] = 1;
		ans+=dfs(i, visited);
		visited[i] = 0;
	}
	return ans;
}
int main() {
	cin >> n >> m;
	rep(i, m) {
		cin >> a >> b;
		grp[a-1][b - 1] = grp[b - 1][a - 1] = 1;
	}
	ll visited[9];
	m0(visited);
	visited[0] = 1;
	cout << dfs(0, visited) << endl;
	return 0;
}