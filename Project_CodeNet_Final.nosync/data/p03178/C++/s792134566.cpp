#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <string>
#include <cstring>
#include <functional>
using namespace std;

const int mo = 1e9 + 7;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, d;
    string s;
    cin >> s >> d;
	
    n = s.length();
    if (n == 1) {
        int tmp = (s[0] - '0' >= d) ? 1 : 0;
        cout << tmp << endl;
        return 0;
    }

    vector<int> lim(n);
    for (int i = 0; i < n; ++i)
        lim[i] = s[i] - '0';

    vector<vector<int> > f(n, vector<int>(d));
    for (int i = 0; i < lim[0]; ++i)
        ++f[0][i % d];

    int sum = 0;

    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < d; ++j)
            if (f[i][j] != 0) {
                for (int t = 0; t < 10; ++t) {
                    int k = (j + t) % d;
                    f[i+1][k] = (f[i+1][k] + f[i][j]) % mo;
                }
            }

        sum = (sum + lim[i]) % d;
        for (int t = 0; t < lim[i+1]; ++t) {
            int k = (sum + t) % d;
            f[i+1][k] = (f[i+1][k] + 1) % mo;
        }
    }

    int res = (f[n-1][0] - 1 + mo) % mo;

    sum = (sum + lim[n-1]) % d;
    if (sum == 0)
        res = (res + 1) % mo;

    cout << res << endl;
	return 0;
}