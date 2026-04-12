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

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int X;

void input() {
    cin >> X;
}

bool solve() {
    return X == 7 or X == 5 or X == 3;
}


int main() {
    input();
    cout << (solve() ? "YES" : "NO") << endl;;
    
    return 0;
}

