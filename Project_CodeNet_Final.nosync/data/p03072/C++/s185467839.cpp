#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	int H[21];
	int ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> H[i];
	H[0] = 0;

	for (int i = 1; i <= N; i++) {
		bool flag = true;
		for (int j = 0; j < i && flag; j++) {
			if (H[j] > H[i]) flag = false;
		}
		if (flag) ans++;
	}

	cout << ans << endl;


	return 0;
}