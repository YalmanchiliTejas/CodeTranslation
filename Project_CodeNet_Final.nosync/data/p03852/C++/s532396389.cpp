#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <queue>

//#define INF 1000000000;
#define MOD 1000000007;
#define LIMIT 1000000000000000000;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> P;
#define int long long

struct Setup {
    Setup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} SETUP;

template<class T>
bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const int INF = 1LL << 60;


signed main() {
    char c; cin >> c;
    string ans = "consonant";
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
        ans = "vowel";
    }
    cout << ans << endl;
}