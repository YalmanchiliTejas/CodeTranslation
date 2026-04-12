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
#define YES(i) cout << ((i) ? "Yes" : "No") << endl;
constexpr auto INF = 1000000000;
constexpr auto LLINF = 9223372036854775807;
constexpr auto mod = 1000000007;

int main() {

	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if (x < y) {
		swap(a, b);
		swap(x, y);
	}

	c *= 2;
	if (c < a + b) {
		int ans = 0;
		ans += c * y;
		x -= y;
		if (c < a)ans += c * x;
		else ans += a * x;
		cout << ans << endl;
	}
	else cout << a * x + b * y << endl;

	return 0;
}
