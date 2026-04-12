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
#define vunique(v) v.erase(unique(v.begin(), v.end()), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

#define MAX_V 1000000

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;

	bool graph[N][N];
	memset(graph, false, sizeof(graph));
	rep(i, 0, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		graph[a][b] = graph[b][a] = true;
	}

	vector<int> v;
	rep(i, 0, N) v.push_back(i);

	int rsl = 0;
	do {
		bool flag = true;
		rep(i, 0, N - 1) {
			if(i == 0 and v[i] != 0) {
				flag = false;
				break;
			}
			if(graph[v[i]][v[i + 1]]) continue;
			flag = false;
			break;
		}
		if(flag) rsl++;
	} while(next_permutation(v.begin(), v.end()));
	cout << rsl << endl;
}
