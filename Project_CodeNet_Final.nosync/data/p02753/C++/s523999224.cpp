#include <iostream>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

using ll = long long;

#define MOD 1000000007

#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)

ll gcd(ll a, ll b) { if (a < b) { a ^= b; b ^= a; a ^= b; } return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main() {
    string S;
    cin >> S;
    
    ll ans = S[0] + S[1] + S[2] - 'A' * 3;

    cout << (ans == 1 || ans == 2 ? "Yes" : "No") << endl;

    return 0;
}
