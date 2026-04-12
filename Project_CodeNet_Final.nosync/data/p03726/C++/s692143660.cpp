//Sasayego! Sasayego! Shinzou wo Sasageyo!

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <numeric>
#include <bitset>
#include <ctime>
#define debug(x)  cerr << #x << " = " << x << endl
#define lid (id << 1)
#define rid (lid ^ 1)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

const int maxN = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int arumin[maxN];
vector <int> G[maxN];

int LEVI(int v, int p = -1){
	int cnt[3] = {0, 0, 0};
	for (int u : G[v]){
		if (u == p)
			continue;
		cnt[LEVI(u, v)]++;
	}
	if (cnt[0] > 0 || cnt[2] > 1)
		return arumin[v] = 0;
	return arumin[v] = 2 - cnt[2];
}

int main(){
	time_t START = clock();
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++){
		int u, v; scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	printf(LEVI(1) & 1 ? "Second\n" : "First\n");
	time_t FINISH = clock();
	cerr << "Execution time: " << (ld)(FINISH - START) / CLOCKS_PER_SEC * 1000.0 << " milliseconds.\n";
	return 0;
}
 
