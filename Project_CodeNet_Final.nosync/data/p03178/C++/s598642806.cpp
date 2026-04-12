#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <cassert>
#include <bitset>
#include <cmath>
#include <iomanip>

using namespace std;

using int64 = long long;

/////////////////////
// Code starts here//
/////////////////////
const int MOD = 1000000007;

void add (int & a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string K;
    int D, N;

    cin >> K;
    cin >> D;
    N = K.size();

    vector<vector<int>> exact(N + 1, vector<int>(D));
    vector<vector<int>> smaller(N + 1, vector<int>(D));    

    exact[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        int dig = K[i-1] - '0';

        for (int j = 0; j < D; j++) {
            add(exact[i][(j + dig) % D], exact[i-1][j]);

            for (int k = 0; k <= 9; k++) {
                add(smaller[i][(j + k) % D], smaller[i-1][j]);
                if (k < dig)
                    add(smaller[i][(j + k) % D], exact[i-1][j]);
            } 
        }

        // for (int j = 0; j < D; j++) {
        //     if (exact[i][j]) {
        //         cerr << i << " " << j << " = " << exact[i][j] << "\n";
        //     }
        //     if (smaller[i][j]) {
        //         cerr << "sm " << i << " " << j << " = " << smaller[i][j] << "\n";
        //     }
        // }
    }

    int res = (exact[N][0] + smaller[N][0]) % MOD;
    res = (res + MOD - 1) % MOD;
    cout << res << "\n"; 

    return 0;
}
