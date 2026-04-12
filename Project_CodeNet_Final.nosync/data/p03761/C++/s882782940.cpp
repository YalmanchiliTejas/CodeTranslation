#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
string s[55];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	string ans = "";
	for (char c = 'a'; c <= 'z'; c++) {
		ll mi = inf;
		ll count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < s[i].size(); j++) {
				if (s[i][j] == c) {
					count++;
				}
			}
			mi = min(mi, count);
			count = 0;
		}
		for (int k = 0; k < mi; k++) {
			ans += c;
		}
	}
	cout << ans << endl;
	return 0;
}