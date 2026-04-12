#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i].first;
        x[i].second = i;
    }
    sort(x.begin(), x.end());
    vector<int> ord(n);
    for (int i = 0; i < n; i++) {
        ord[x[i].second] = i;
    }

    int med1 = x[n / 2 - 1].first, med2 = x[n / 2].first;

    for (int i = 0; i < n; i++) {
        int ret = 0;
        if (ord[i] <= n / 2 - 1) {
            ret = med2;
        } else {
            ret = med1;
        }
        cout << ret << endl;
    }

    return 0;
}
