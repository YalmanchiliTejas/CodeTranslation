#include <iostream>
#include <algorithm>
#include <cstdio>
#include <regex>
#include <cmath>
#include <vector>
#include <queue>
#include <functional>
#include <numeric>
#include <iomanip>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <cstdint>
#include <chrono>
const long long MOD = (long long)1e9+7;
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
const long long INF = INT64_MAX;


ll patty(ll lv, ll x) {
    if(lv == 0) return 1;
    if(x <= 1) {
        return 0;
    }else if (x >= 2 && x <= pow(2, lv + 1) - 2) {
        return patty(lv - 1, x - 1);
    }else if (x == pow(2, lv + 1) - 1) {
        return pow(2, lv);
    }else if (x >= pow(2, lv + 1) && x <= pow(2, lv + 2) - 4) {
        return pow(2, lv) + patty(lv - 1, x - (pow(2, lv + 1) - 1));
    }else {
        return pow(2, lv + 1) - 1;
    }
}

int main () {
    ll N, X;
    cin >> N >> X;
    cout << patty(N, X) << endl;
}
