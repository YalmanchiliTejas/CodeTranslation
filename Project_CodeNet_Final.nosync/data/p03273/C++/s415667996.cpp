# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;

int n, m;
string s[105];
bool used[105];

int main(int argc, const char * argv[]) {
    #ifdef __APPLE__
        freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
        //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    for (int j = 0; j < m; ++j) {
        bool t = false;
        for (int i = 1; i <= n; ++i)
            if (s[i][j] == '#') {
                t = true;
                break;
            }
        if (!t) used[j] = true;
    }
    for (int i = 1; i <= n; ++i) {
        bool t = false;
        for (int j = 0; j < m; ++j)
            if (s[i][j] == '#') {
                t = true;
                break;
            }
        if (!t) continue;
        for (int j = 0; j < m; ++j)
            if (!used[j]) cout << s[i][j];
        cout << '\n';
    }
    return 0;
    
}

