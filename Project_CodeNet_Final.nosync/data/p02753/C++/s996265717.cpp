#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <utility>
#include <queue>
#include <tuple>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;
constexpr ll INF = 1000000007;

int main() {
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
    }
    return 0;
}