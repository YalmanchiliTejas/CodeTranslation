#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
#include <unordered_map> 
#include <map> 
#include <numeric>
#include <limits>
#include <utility>
#include <queue>
#include <random>
#include <bitset>
#include <memory>
#include <complex>
using namespace std;
typedef long long LL;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<LL>> num(n, vector<LL>(26,0));
    for (int i = 0; i < n; i++) {
        string h;
        cin >> h;
        s[i] = h;
        for (int j = 0; j < s[i].size(); j++) {
            num[i][h[j] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        LL mi = 1000000;
        for (int j = 0; j < n; j++) {
            mi = min(mi, num[j][i]);
        }
        for (int k = 0; k < mi; k++) {
            cout << (char)('a' + i);
        }
    }
    cout << endl;



    return 0;
}
