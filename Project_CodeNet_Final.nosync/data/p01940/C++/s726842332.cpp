#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using i64 = int64_t;

const string YES = "yes";
const string NO  = "no";

string T, P;
int N, M;

int main() {
    cin >> T >> P;
    N = T.size(); M = P.size();

    int pi = M;
    bool flag = true;
    for (int j = N-1; j >= 0; --j) {
        if (pi > 0 && T[j] == P[pi-1]) {
            --pi;
        } else if (pi < M && T[j] == P[pi]) {
            flag = false;
        }
    }
    cout << (pi == 0 && flag ? YES : NO) << endl;
    return 0;
}