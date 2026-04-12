#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> data(h);
    for (int i = 0; i < h; i++) {
        cin >> data[i];
    }
    set<int> ex_h, ex_w;
    for (int i = 0; i < h; i++) {
        bool ok = false;
        for (int j = 0; j < w; j++) {
            if (data[i][j] == '#')
                ok = true;
        }
        if (!ok) {
            ex_h.insert(i);
        }
    }

    for (int j = 0; j < w; j++) {
        bool ok = false;
        for (int i = 0; i < h; i++) {
            if (data[i][j] == '#')
                ok = true;
        }
        if (!ok)
            ex_w.insert(j);
    }

    for (int i = 0; i < h; i++) {
        if (ex_h.count(i))
            continue;
        for (int j = 0; j < w; j++) {
            if (ex_w.count(j))
                continue;
            cout << data[i][j];
        }
        cout << endl;
    }

    return 0;
}