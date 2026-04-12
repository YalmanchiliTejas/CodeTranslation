#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;

using ll = long long;

int H[10000];
int N;
int ans = 0;
int maxh = 0;

int main() {
	cin >> N;
	H[0] = 0;
	for (int i = 1; i < N + 1; i++) {
		cin >> H[i];
		if (H[i] >= maxh) {
			ans++;
			maxh = H[i];
		}
	}
	cout << ans;
	return 0;
}