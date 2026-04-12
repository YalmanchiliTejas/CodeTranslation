#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <sstream>
#include <deque>

#define REP(i, n) for ( int i = 0; i < n; i++ )

using namespace std;

int main() {
    int n;

    while(cin >> n, n) {
        vector<int> judge(n);
        int sum = 0;

        REP(i, n) {
            cin >> judge[i];
        }
        sort(judge.begin(), judge.end());

        REP(i, n-2) {
            // cout << judge[i+1] << endl;
            sum += judge[i+1];
        }
        cout << (sum/(n-2)) << endl;

    }

    return 0;
}