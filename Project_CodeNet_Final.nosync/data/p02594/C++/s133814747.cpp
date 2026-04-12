#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <cassert>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <chrono>
#include <ctime>

using namespace std;

#define en '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) int((x).size())

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;
const ll INFLL = 1e18;
const double EPS = 1e-9;
const double PI = 3.1415926535897932384626433832795;
const int MAX_SIZE = 5e5;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

bool IS_ONE_TEST = 1;
ld START_TIME, TIME;

void fast_in_out() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int n;
    cin >> n;
    cout << (n >= 30 ? "Yes" : "No") << en;
    
}

int main() {
    START_TIME = clock();
    fast_in_out();
    int TESTS = 1;
    if (!IS_ONE_TEST) cin >> TESTS;
    while (TESTS--) { solve(); }
#ifdef __APPLE__
    TIME = (clock() - START_TIME) / CLOCKS_PER_SEC;
    cerr << en << TIME * 1000 << " ms." << en;
#endif
    return 0;
}

/*
     ▄▀▀▀▄
▄███▀░◐░░░▌
    ▌░░░░░▐
    ▐░░░░░▐
    ▌░░░░░▐▄▄
    ▌░░░░▄▀▒▒▀▀▀▀▄
   ▐░░░░▐▒▒▒▒▒▒▒▒▀▀▄
   ▐░░░░▐▄▒▒▒▒▒▒▒▒▒▒▀▄
    ▀▄░░░░▀▄▒▒▒▒▒▒▒▒▒▒▀▄
      ▀▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▀▄
           ▌▌░▌▌
           ▌▌░▌▌
         ▄▄▌▌▄▌▌        */
