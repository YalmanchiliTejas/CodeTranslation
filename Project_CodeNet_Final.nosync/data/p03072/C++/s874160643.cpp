#include <iostream>
#include <cstdio>

#include <algorithm>
#include <cmath>
#include <functional>

#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <list>

#define ll long long int

using namespace std;

int main(int argc, char const* argv[]) {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i != n; ++i) {
        cin >> h[i];
    }

    int max_h = 0;
    int ans = 0;

    for (int i = 0; i != n; ++i) {
        if (h[i] >= max_h) {
            max_h = h[i];
            ans += 1;
        }
    }

    cout << ans << endl;
    return 0;
}
