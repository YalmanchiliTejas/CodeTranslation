#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<climits>
#include<map>
#include<string>
#include<functional>

using namespace std;
typedef long long ll;

ll N, H;
ll ans = 0, highest = 0;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> H;
		if (H >= highest)ans++;
		highest = max(highest, H);
	}
	cout << ans << endl;
	return 0;
}