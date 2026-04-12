#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
#define FOR(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR1(i,n) for(int (i)=1;(i)<(n);(i)++)
#define eFOR(i,n) for(int (i)=0;(i)<=(n);(i)++)
#define eFOR1(i,n) for(int (i)=1;(i)<=(n);(i)++)
#define SORT(i) sort((i).begin(),(i).end())
#define rSORT(i) sort((i).begin(),(i).end(), greater<int>());
#define F first
#define S second
constexpr auto INF = 1000000000;
constexpr auto LLINF = 9223372036854775807;
constexpr auto mod = 1000000007;
int main() {

	int n, m;
	cin >> n >> m;
	bool ab[8][8] = {};
	FOR(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		ab[a][b] = 1;
		ab[b][a] = 1;
	}
	VI g(n);
	FOR(i, n)g[i] = i;

	int ans = 0;
	do {
		if (g[0] == 0) {
			bool ok = 1;
			FOR(i, g.size() - 1) {
				if (!ab[g[i]][g[i + 1]])ok = 0;
			}
			if (ok)ans++;
		}
	} while (next_permutation(g.begin(), g.end()));
	
	cout << ans << endl;

	return 0;
}
