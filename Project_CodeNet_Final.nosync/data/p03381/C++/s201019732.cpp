#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll, lint;
typedef long double ldouble;

#define sz(v) ((int) (v).size())
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define For(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define all(v) (v).begin(), (v).end()

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

template<class T>
string to_string(T arr, int len = 1e9) {
    stringstream ss;
    int i = 0;
    for (auto item : arr) {
        ss << item << ' ';
        if (++i == len)
            break;
    }
    return ss.str();
}

#ifdef LOCAL
    #define dbg(expr) cout << "[line " << __LINE__ << "] " << (#expr) << ": " << (expr) << endl;
#else
    #define dbg(expr) (void) 0;
#endif


int main() {
#ifndef LOCAL
    cin.tie(0);
    ios_base::sync_with_stdio(false);
#endif

    int n;
    cin >> n;
    vector<pair<lint, int>> values;
    For (i, n) {
        int x;
        cin >> x;
        values.emplace_back(x, i);
    }
    auto base = values;
    sort(all(values));

    lint lm = values[n / 2 - 1].first;
    lint rm = values[n / 2].first;
    for (auto e : base) {
        if (e.first <= lm)
            cout << rm << endl;
        else
            cout << lm << endl;
    }
}