#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long ll;

int main ()
{
    ll N; cin >> N;
    vector < ll > a(N);
    REP(i,N) cin >> a[i];

    ll ans = 0;
    while (true) {
        sort(a.begin(), a.end());
        if (a.back() < N) break; 
        ll minus = a.back() / N * N;
        a.back() -= minus;
        ans += minus / N;
        REP(i,a.size() - 1) a[i] += minus / N;
    }

    cout << ans << endl;

    return 0;
}
