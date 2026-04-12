#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<unordered_map>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
bool ok; char ch;
void read(int& x) {
	for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
	for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if (ok) x = -x;
}
void write(int x)
{
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
	return;
}
string s;
int fuc(int n, int k) {
	if (n < k)return 0;
	if (k == 0)return 1;
	if (k == 3) {
		int ans = 0;
		for (int i = 3; i <= n; i++) {
			for (int j = 2; j < i; j++) {
				for (int k = 1; k < j; k++) {
					ans += 9 * 9 * 9;
				}
			}
		}
		return ans;
	}
	if (k == 2)return n * (n - 1) * 81 / 2;
	/*if (k == 2) {
		int ans = 0;
		for (int j = 2; j < n; j++) {
			for (int k = 1; k < j; k++) {
				ans += 9 * 9 ;
			}
		}
		return ans;
	}*/
	return 9 * n;
}
int dp(int i, int k) {
	while (s[i] == '0')i++;
	if (i >= (signed)s.size()) {
		return 0;
		//return k ? 0 : 1;
	}
	if (k <= 0)return 0;
	//if ((signed)s.size() - i - 1 < k)return 0;
	return dp(i + 1, k - 1) + (s[i] - '1') * fuc((signed)s.size() - i - 1, k - 1) + fuc((signed)s.size() - i - 1, k) + (k == 1);
}
int main() {

	cin >> s;
	int k;
	cin >> k;
	cout << dp(0, k);
	return 0;
}