#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
#define endl "\n"
#define pi 3.14159265358979
using namespace std;
using ll = long long;

ll PowIterative(ll a, ll b) {
    ll res = 1;
    for (; b > 0; b >>= 1, a = a * a ) {
        if (b % 2 == 1) {
            res = res * a;
        }
    }
    return res;
}

ll recursion(ll level, ll pos, ll cur) {
    if (level == 0) {
        if (pos == 1) {
            return cur + 1;
        }
        else {
            cerr << "ERROR POS" << endl;
        }
    }
    else {
        ll K = PowIterative(2, level + 1) - 3;
        ll R = PowIterative(2, level) - 1;

        if (pos == 1) {
            return cur;
        }
        else if (pos < K + 2) {
            return recursion(--level, pos - 1, cur);
        }
        else if (pos == K + 2) {
            return cur + R + 1;
        }
        else if (pos < 2 * K + 3) {
            return recursion(--level, pos - 2 - K, cur + R + 1);
        }
        else if (pos == 2 * K + 3) {
            return cur + 2 * R + 1;
        }
        else {
            cerr << "ERROR IF CLAUSE" << endl;
        }
    }

    return -1;
}
int main() {
    ll N, X; cin >> N >> X;

   
    ll ans = recursion(N, X, 0);

    cout << ans << endl;
}