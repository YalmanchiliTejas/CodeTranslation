#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <random>
#include <cstdio>
#include <cstring>
#include <cmath>

// for i in f..<t { as swift
#define forin(i, f, t) for(auto i = f; i < t; i++)

using namespace std;
using ll = long long;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    auto cache = 0;
    auto s = max(x, y), t = min(x, y);
    if (a + b > c * 2) {
        cache += t * c * 2;
    } else {
        cache += (a + b) * t;
    }
    if (x > y) {
        if (a > c * 2) {
            cache += (s - t) * c * 2;
        } else {
            cache += (s - t) * a;
        }
    } else {
        if (b > c * 2) {
            cache += (s - t) * c * 2;
        } else {
            cache += (s - t) * b;
        }
    }
    cout << cache << endl;
}

