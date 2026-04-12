#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <fstream>
#include <cassert>
#include <unordered_map>
#include <cstring>
using namespace std;
#pragma warning(disable : 4996)
typedef long long ll;

int main() {
#ifdef _DEBUG
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	int kk;
	cin >> s >> kk;
	ll ans = 0;
	int n = s.size();
	if (kk == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= 9; j++) {
				string cur = "";
				for (int k = 0; k < i; k++) {
					cur += to_string(0);
				}
				cur += to_string(j);
				for (int k = i + 1; k < n; k++) {
					cur += to_string(0);
				}
				if (cur <= s)ans++;
			}
		}
		cout << ans;
	}
	else if (kk == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				for (int num1 = 1; num1 <= 9; num1++) {
					for (int num2 = 1; num2 <= 9; num2++) {
						if (j != 0)ans++;
						else {
							string cur = to_string(num2);
							for (int k = 1; k < i; k++) {
								cur += to_string(0);
							}
							cur += to_string(num1);
							for (int k = i + 1; k < n; k++) {
								cur += to_string(0);
							}
							if (cur <= s)ans++;
						}
					}
				}
			}
		}
		cout << ans;
	}
	else if (kk == 3) {
		if(n > 3)ans = max(0, (n - 1) * (n - 2) * (n - 3) / 6) * 9 * 9 * 9;
		if(n > 2)ans += max(0, (s[0] - '0' - 1) * 81 * (n - 1) * (n - 2) / 2);
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < i; j++) {
				for (int num2 = 1; num2 <= 9; num2++) {
					for (int num3 = 1; num3 <= 9; num3++) {
						string cur = to_string(s[0] - '0');
						for (int k = 1; k < j; k++) {
							cur += '0';
						}
						cur += to_string(num2);
						for (int k = j + 1; k < i; k++) {
							cur += '0';
						}
						cur += to_string(num3);
						for (int k = i + 1; k < n; k++) {
							cur += '0';
						}
						//cout << cur << "\n";
						if (cur <= s)ans++;
					}
				}
			}
		}
		cout << ans;
	}
}

