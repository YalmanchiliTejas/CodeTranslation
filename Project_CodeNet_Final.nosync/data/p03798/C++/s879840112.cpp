#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const int INF = 1 << 28;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // SS
    auto check = [&](string &ret) {
        if ((s[0] == 'o') ^ (ret[0] == 'W') ^ (ret[1] == 'W'))
            ret[n - 1] = 'S';
        else
            ret[n - 1] = 'W';

        for (int i = 1; i < n - 2; ++i) {
            if ((s[i] == 'o') ^ (ret[i] == 'W') ^ (ret[i - 1] == 'W'))
                ret[i + 1] = 'S';
            else
                ret[i + 1] = 'W';
        }
        if ((s[n - 2] == 'o') ^ (ret[n - 2] == 'W') ^ (ret[n - 3] == 'W') ^
            (ret[n - 1] == 'W')) {
            if ((s[n - 1] == 'o') ^ (ret[n - 1] == 'W') ^ (ret[n - 2] == 'W') ^
                (ret[0] == 'W')) {
                cout << ret << "\n";
                return true;
            }
        }
        return false;
    };
    string ret(n, 'S');
    if (check(ret))
        return 0;
    ret[0] = 'S';
    ret[1] = 'W';
    if (check(ret))
        return 0;
    ret[0] = 'W';
    ret[1] = 'S';
    if (check(ret))
        return 0;
    ret[0] = 'W';
    ret[1] = 'W';
    if (check(ret))
        return 0;

    cout << -1 << "\n";
    return 0;
}