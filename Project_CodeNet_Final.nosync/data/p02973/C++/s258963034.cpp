#include <iomanip>
#include <limits>
#include <thread>
#include <utility>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <numeric>
#include <cassert>
#include <random>
#include <chrono>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <list>
#include <functional>
#include <bitset>
#include <complex>
#include <tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double D;
typedef complex<D> P;
const ll E = 1e18 + 7;
const ll MOD = 1000000007;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fill(x, y) memset(x, y, sizeof(x))
#define pcnt __builtin_popcount
#define buli(x) __builtin_popcountll(x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
template <class... A>
void prints() { cout << endl; }
template <class... A>
void prints_rest() { cout << endl; }
template <class T, class... A>
void prints_rest(const T &first, const A &... rest) { cout << " " << first; prints_rest(rest...); }
template <class T, class... A>
void prints(const T &first, const A &... rest) { cout << first; prints_rest(rest...); }

template <class T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A, maxV;
    int a;
    rep(_, N) { 
        cin >> a;
        
        auto it = lower_bound(all(maxV), a);
        if (it == maxV.begin()) {
            maxV.insert(maxV.begin(), a);
        }
        else {
            *(--it) = a;
        }
    }

    prints(sz(maxV));    

    return 0;
}

