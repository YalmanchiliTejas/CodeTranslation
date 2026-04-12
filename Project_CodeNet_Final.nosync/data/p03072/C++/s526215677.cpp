#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;
const double PI=3.14159265358979323846;

int main() {
    int N;
    cin >> N;

    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int cnt = 1;
    int maxH = H[0];
    for (int i = 1; i < N; i++) {
        maxH = max(maxH, H[i - 1]);
        if (maxH <= H[i]) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
