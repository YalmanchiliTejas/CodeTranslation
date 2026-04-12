#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n;
int p[200];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
        cin >> p[i];
	}
	vector<int> ans;
	for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            ans.push_back(1);
            if (p[j - 1] > p[j]) {
                ans.push_back(n - 1);
                swap(p[j - 1], p[j]);
            }
        }
        ans.push_back(1);
	}
	printf("%d\n", (int)ans.size());
	for (int i : ans) {
        printf("%d\n", i);
	}
	return 0;
}
