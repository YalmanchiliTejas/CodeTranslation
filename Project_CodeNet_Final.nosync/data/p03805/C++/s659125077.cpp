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
#define all(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, M;
	cin >> N >> M;
	int G[N][N];
	memset(G, 0, sizeof(G));
	vector<int> v;
	rep(i, 0, M) {
		int tmp_a, tmp_b;
		cin >> tmp_a >> tmp_b;
		tmp_a--; tmp_b--;

		G[tmp_a][tmp_b] = 1;
		G[tmp_b][tmp_a] = 1;
	}

	rep(i, 1, N) v.push_back(i);

	int rsl = 0;
	do {
		if(G[0][v[0]] != 1) continue;
		bool flag = true;
		rep(i, 0, v.size() - 1) {
			if(G[v[i]][v[i + 1]]) continue;
			flag = false;
		}
		if(flag) rsl++;

	} while(next_permutation(v.begin(), v.end()));

	cout << rsl << endl;

}
