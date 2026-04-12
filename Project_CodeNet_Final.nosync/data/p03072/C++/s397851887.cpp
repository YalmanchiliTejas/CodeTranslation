//author Eterna
#define Hello the_cruel_world!
#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<cmath>
#include<climits>
#include<deque>
#include<functional>
#include<numeric>
#define max(x,y) ((x) > (y) ? (x) : (y))
#define min(x,y) ((x) < (y) ? (x) : (y))
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
#define pb(x) push_back(x)
#define lowbit(x) ((x) & (-(x)))
#define FRIN freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\in.txt", "r", stdin)
#define FROUT freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\out.txt", "w", stdout)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define outd(x) printf("%d\n", x)
#define outld(x) printf("%I64d\n", x)
#define memset0(arr) memset(arr, 0, sizeof(arr))
#define il inline
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int maxn = 20;
const int INF = 0x7fffffff;
const int mod = 1e9 + 7;
const double eps = 1e-7;
const double Pi = acos(-1.0);
inline int read_int() {
	char c;
	int ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
inline ll read_ll() {
	char c;
	ll ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
int arr[maxn + 5], n, res = 1, now;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> arr[i];
	now = arr[1];
	for (int i = 2; i <= n; ++i) {
		if (arr[i] >= now) {
			now = arr[i];
			++res;
		}
	}
	cout << res << endl;
	//system("pause");
	return 0;
}