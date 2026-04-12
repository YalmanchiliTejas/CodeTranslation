#include "iostream"
#include "algorithm"
#include "string"
#include "set"
#include "vector"
#include "climits"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K >> H >> W;
	int box = min(H, W);
	long long int ans = min(N*box + M * box, K*box * 2);
	H -= box;
	W -= box;
	if (H) {
		ans += min(N*H, K*H * 2);
	}
	else {
		ans += min(M*W, K*W * 2);
	}
	cout << ans << endl;
	return 0;
}