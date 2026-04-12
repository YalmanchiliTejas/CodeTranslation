#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <functional>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <array>
#include <tuple>
#include <utility>
#include <numeric>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <assert.h>
#include <cstdlib>
#include <list>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {
    return s << "(" << p.first << ", " << p.second << ")";
}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
    s << "[";
    for (int i = 0; i < v.size(); i++) s << (i == 0 ? "" : ", ") << v[i];
    s << "]";
    return s;
}

#define ALL(a) (a).begin(), (a).end()

int main() {
    string S;
    cin >> S;

    for (int i = 0; i < S.size() - 1; i++) {
        if (S.substr(i, 2) == "AC") {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
