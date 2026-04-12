#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
const int INF = (1 << 30);
const ll INFL = (1LL << 62);
const ll MOD = 1000000007;
template <class T>
bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T gcd(T a, T b) {
    return b ? gcd(b, a % b) : a;
}
template <class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}
template <class T>
ll mod_pow(ll a, ll n, T mod) {
    mod = (ll)mod;
    ll res = 1, p = a % mod;
    while (n) {
        if (n & 1) res = res * p % mod;
        p = p * p % mod;
        n >>= 1;
    }
    return res;
}

bool check(const vector<char>& zoo, const string& s) {
    const int N = s.size();
    string SW = "SW";
    string ox = "ox";
    rep(i, N) {
        int before = ((i - 1) < 0 ? (i - 1) % N + N : (i - 1) % N),
            after = (i + 1) % N;
        int index = (zoo[i] == 'S' ? 0 : 1);
        if (zoo[before] == zoo[after]) {
            if (s[i] != ox[index]) return false;
        } else {
            if (s[i] != ox[1 - index]) return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    string s;
    cin >> s;
    vector<string> cand = {"SS", "SW", "WS", "WW"};
    rep(j, 4) {
        vector<char> zoo = {cand[j][0], cand[j][1]};
        for (int i = 1; i < N - 1; i++) {
            if (zoo[i] == 'S') {
                if (s[i] == 'o')
                    zoo.push_back(zoo[i - 1]);
                else {
                    if (zoo[i - 1] == 'S')
                        zoo.push_back('W');
                    else
                        zoo.push_back('S');
                }
            } else {
                if (s[i] == 'x')
                    zoo.push_back(zoo[i - 1]);
                else {
                    if (zoo[i - 1] == 'S')
                        zoo.push_back('W');
                    else
                        zoo.push_back('S');
                }
            }
        }
        assert((int)zoo.size() == N);
        if (check(zoo, s)) {
            rep(i, N) cout << zoo[i];
            // cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}