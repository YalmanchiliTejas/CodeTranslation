/**
 *      AGC 7 A
 *      author  : kyomukyomupurin
 *      created : 2018-10-11 10:22:02
**/

#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#define int64 long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int H, W; cin >> H >> W;
    string A[H] = {};
    for (auto i = 0; i < H; ++i) {
        cin >> A[i];
    }

    int cnt = 0;

    for (auto i = 0; i < H; ++i) {
        for (auto j = 0; j < W; ++j) {
            if (A[i][j] == '#') ++cnt;
        }
    }

    cnt == H + W - 1 ? cout << "Possible" << endl : cout << "Impossible" << endl;
    
    return 0;
}