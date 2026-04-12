//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
    vector<int> Ais;
    for (int i = 0; i < N; i++) {
        int Ai;
        cin >> Ai;
        Ais.push_back(Ai);
    }
    vector<int> vals;
    for (int ai : Ais) {
        if (vals.empty()) {
            vals.push_back(ai);
            continue;
        }
        auto it = partition_point(vals.begin(), vals.end(), [ai](int val) { return val >= ai; });
        if (it == vals.end()) {
            vals.push_back(ai);
        } else {
            *it = ai;
        }
    }
    cout << vals.size() << endl;
}

