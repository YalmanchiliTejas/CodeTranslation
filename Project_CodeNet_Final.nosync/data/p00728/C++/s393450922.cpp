#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<climits>
#include<map>
#include<string>
#include<functional>
#include<iomanip>

using namespace std;
typedef long long ll;

ll n[21] = {}, s[21][101] = {}, sum[21] = {}, ans[21] = {}, num = 20;

int main() {
	for (int i = 1; i <= 20; i++) {
		cin >> n[i];
		if (n[i] == 0) {
			num = i - 1;
			break;
		}
		for (int j = 1; j <= n[i]; j++)cin >> s[i][j];
		stable_sort(s[i], s[i] + n[i] + 1);
		for (int j = 2; j < n[i]; j++)sum[i] += s[i][j];
		ans[i] = sum[i] / (n[i] - 2);
	}
	for (int i = 1; i <= num; i++)cout << ans[i] << endl;
	return 0;
}
