#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>

#pragma GCC optimize("O3")

using namespace std;
using ll = long long;

#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define repd(i, n) for(ll i = (n) - 1; i >= 0; --i)
#define FOR(i, a, b) for(ll i = a; i <= ll(b); ++i)
#define FORD(i, a, b) for(ll i = a; i >= ll(b); --i)
#define loop while(true)
#define asort(array, size) std::sort(array, array + size)
#define cauto const auto&
#define bit(n) (1LL << (n))

int main()
{
    int X;
    cin >> X;
    if (X >= 30) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
