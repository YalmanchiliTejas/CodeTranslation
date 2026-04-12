#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
//DP用
template<class T> inline bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
const long long INF = 1LL << 60;

int main() {
    int x;
    cin >> x;
    if(x == 7 || x == 5 || x == 3) {
        cout << "YES";
    }else {
        cout << "NO";
    }
    return 0;
}

