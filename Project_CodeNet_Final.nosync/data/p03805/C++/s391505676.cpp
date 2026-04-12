#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) unique(v.begin(), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

int n, m;
vector<int> v[8];
int used[8];
int ans = 0;

void dfs(int current, int t) {
	if(t == 0) {
		bool flag = true;
		rep(i, 0, n) {
			if(!used[i]) flag = false;
		}
		if(flag) ans++;
		used[current]--;
		return;
	}

	rep(i, 0, v[current].size()) {
		used[v[current][i]]++;
		dfs(v[current][i], t - 1);
	}

	used[current]--;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	rep(i, 0, 8) used[i] = 0;
	used[0] = 1;
	dfs(0, n - 1);
	cout << ans << endl;

}
