#include <iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include <string>
#include <set>
#include <bitset>

using namespace std;
#define ff(i,n,m) for(int i=n;i<m;i++)
#define i64 int64_t
#define tos(x) to_string(x)

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> per(n);
	vector<pair<int, int>> route(m);
	int ans = 0;
	ff(i, 0, m) {
		int a, b;
		cin >> a >> b;
		route.at(i).first = a;
		route.at(i).second = b;
	}
	ff(i, 0, n) {
		per.at(i) = i + 1;
	}
	do {
		int go = 0;
		ff(i, 0, n-1) {
			ff(j, 0, m) {
				if (per.at(i) == route.at(j).first ||
					per.at(i) == route.at(j).second) {
					if (per.at(i+1) == route.at(j).first ||
						per.at(i+1) == route.at(j).second) {
						go++;
					}
				}
			}
		}
		if (go == n - 1&&per.at(0)==1) {
			ans++;
		}

	} while (next_permutation(per.begin(), per.end()));
	cout << ans << endl;
	return 0;
}