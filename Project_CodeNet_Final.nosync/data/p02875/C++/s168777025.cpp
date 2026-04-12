#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
 freopen("input","r",stdin);
 freopen("output","w",stdout);
*/

const int sz = 1E7 + 10;

ll F[sz];
ll I[sz];

ll MOD = 998244353;

ll nchoosek(ll a, ll b) {
    ll res = F[a] * I[b];
    res %= MOD;
    return (res * I[a - b]) % MOD;
}

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    F[0] = 1;
    for (int i = 1;i <= N;i++) {
        F[i] = F[i - 1] * i;
        F[i] %= MOD;
    }
    I[N] = power(F[N], MOD - 2);
    for (int i = N;i > 0;i--) {
        I[i - 1] = (I[i] * i) % MOD;
    }
    ll tol = power(3, N);
    for (int i = N / 2 + 1;i <= N;i++) {
        ll crt = nchoosek(N, i) * power(2, N - i);
        crt %= MOD;
        tol += (MOD - crt) * 2;
        tol %= MOD;
    }
    cout << tol << endl;
    return 0;
}
