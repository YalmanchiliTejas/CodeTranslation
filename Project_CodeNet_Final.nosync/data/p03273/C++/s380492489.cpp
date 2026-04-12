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
#include <iomanip>
#include <ctype.h>

using namespace std;
using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

#define rep(i,N) for(int i=0;i<(int)N;++i)

ll GCD(ll x, ll y) {
    if (y == 0) return x;
    else return GCD(y, x % y);
}

bool my_compare(pair<string, int> a, pair<string, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }

    if (a.second != b.second) {
        return a.second > b.second;
    }
    else {
        return true;
    }
}

int main()
{
    int H, W;
    cin >> H >> W;

    vector<vector<char> > A(H, vector<char>(W));
    vector<vector<int> > B(H, vector<int>(W));

    rep(i, H) rep(j, W) cin >> A[i][j];

    rep(i, H) rep(j, W) {
        if (A[i][j] == '.') { B[i][j] = 1; }
        else { B[i][j] = 0; }
    }

    int p;

    deque<int> C,D;

    rep(i, H) {
        p = 1;
        rep(j, W) {
            p = p * B[i][j];
        }
        if (p != 1) { C.push_back(i); }
    }

    rep(j, W) {
        p = 1;
        rep(i, H) {
            p = p * B[i][j];
        }
        if (p != 1) { D.push_back(j); }
    }

    int s = C.size();
    int t = D.size();

    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < t; ++j) {
            cout << A[C[i]][D[j]];
        }
        cout << endl;
    }

}