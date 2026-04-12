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

int N, M;
vector<int> G[8];
int reached[8];
int res = 0;

void dfs(int current, int t) {
	if(t == 0) {
		bool flag = true;
		rep(i, 0, N) {
			if(reached[i] == 0) flag = false;
		}
		if(flag) res++;
		reached[current]--;
		return;
	}

	rep(i, 0, G[current].size()) {
		reached[G[current][i]]++;
		dfs(G[current][i], t - 1);
	}
	reached[current]--;
}
		


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	rep(i, 0, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	memset(reached, 0, sizeof(reached));
	reached[0] = 1;
	dfs(0, N - 1);
	cout << res << endl;
}
