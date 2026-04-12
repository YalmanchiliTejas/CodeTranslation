#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <chrono>
#include <queue>
#include <functional>

using namespace std;

typedef long long ll;

int main() {
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int ans = 0;
    vector<int> b(N);
    vector<int> h(N);
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;

        h[i] = t;

        if (i > 0) {
            b[i] = max(b[i - 1], t);
            if (t >= b[i - 1]) ++ans;
        }
        else {
            b[i] = t;
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}