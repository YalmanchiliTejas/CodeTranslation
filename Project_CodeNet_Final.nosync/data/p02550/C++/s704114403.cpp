#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>
#include <bitset>
#include <sstream>
#include <cassert>
#include <time.h>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}
void printvec (vec &v) {
    Rep (i, (ll)v.size()) {
        cout << v[i] << " \n"[i+1 == (ll)v.size()];
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, X, M;
    cin >> N >> X >> M;

    if (N <= 1000000) {
        ll ans = 0;
        Rep (i, N) {
            ans += X;
            X *= X;
            X %= M;
        }
        cout << ans << endl;
        return 0;
    }

    ll tmp = X;

    vec appear(M, -1);
    deque<ll> A;
    ll start;
    while (true) {
        if (appear[tmp] > -1) {
            start = tmp;
            break;
        }

        A.push_back(tmp);
        appear[tmp] = 1;
        tmp *= tmp;
        tmp %= M;
    }

    ll ans = 0;
    while (A.front() != start) {
        ans += A.front();
        A.pop_front();
        N--;
    }

    ll s = 0;
    for (ll e : A) {
        s += e;
    }

    ll n = A.size();
    ll div = N / n;
    ll rem = N % n;

    ans += s * div;
    Rep (i, rem) {
        ans += A[i];
    }

    cout << ans << "\n";
}