#include <cstdio>
#include <cmath>
#include <limits>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdint>
#include <functional>
#define rep(i, s, g) for (i = s; i < g; i++)
using namespace std;
using ll = long long;
const ll mod = 1000000000 + 7; //10^9

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N + 1);
    B[0] = 0;
    for (ll i = 0; i < N; i++)
    {
        cin >> A[i];
        B[i + 1] = (A[i] + B[i]) % mod;
    }
    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        ans += A[i] * ((B[N] - B[i + 1] + mod) % mod) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}