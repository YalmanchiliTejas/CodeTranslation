// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;

bool can(vector<ll> D) {
    int N = D.size();
    vector<ll> imos(N + 1);
    imos[0] = 1; imos[1] = -1;

    for(int i=0; i+1<N; i++) {
        if(imos[i] > 0) {
            int x = D[i] / 10;
            // fprintf(stderr, "i = %d, x = %d\n", i, x);
            if(x > 0) {
                int l = i + 1, r = min(N, i + x + 1);
                imos[l]++; imos[r]--;
            }
        }
        imos[i+1] += imos[i];
    }
    return imos[N-1] > 0;
}

int main() {
    int N; cin >> N;
    vector<ll> D(N);
    for(int i=0; i<N; i++) cin >> D[i];

    bool ok = true;
    ok &= can(D);
    reverse(D.begin(), D.end());
    ok &= can(D);
    cout << (ok ? "yes" : "no") << endl;
    return 0;
}

