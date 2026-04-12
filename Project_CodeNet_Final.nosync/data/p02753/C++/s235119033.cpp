#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <memory>
#include <iomanip>
#include <type_traits>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
//constexpr long long MOD = 1e9 + 7;
//constexpr long long MAX = 1000000;

//long long MOD = 998244353;
constexpr ll INF = 1e17;
constexpr double PI = 3.141592653589793;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll h, w;
vector<ll> dx = { -1, 0, 1, 0 };
vector<ll> dy = { 0, -1, 0, 1 };


bool isInField(ll x, ll y) {
    bool f = x >= 0 && x < w && y >= 0 && y < h;
    return f;
}

bool compare_first(pair<ll, ll> x, pair<ll, ll> y)
{
    if (x.first != y.first) {
        return x.first < y.first;
    }
    else {
        return x.second < y.second;
    }
}

bool compare_second(pair<ll, ll> x, pair<ll, ll> y)
{
    if (x.second != y.second) {
        return x.second < y.second;
    }
    else {
        return x.first < y.first;
    }
}

struct {
    bool operator()(pair<string, int> x, pair<string, int> y) const
    {
        return x.second <= y.second && x.first < y.first;
    }
} compare_map;

const ll MAX = 500000000;
const ll MOD = 1000000007;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    if ((s[0] == 'A' && s[1] == 'A' && s[2] == 'A') || (s[0] == 'B' && s[1] == 'B' && s[2] == 'B')) {
        cout << "No" << "\n";
        return 0;
    }

    cout << "Yes" << "\n";
    return 0;
}

