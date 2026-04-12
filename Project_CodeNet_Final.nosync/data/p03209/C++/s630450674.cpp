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

ll Paty[100];
ll Cnt[100];

ll dfs (ll L, ll Left) 
{
    if (L == 0) {
        return 1;
    }

    if (Left == 1) return 0;
    if (Left <= 1 + Cnt[L - 1]) {
        return 0 + dfs(L - 1, Left - 1);
    }
    if (Left == 2 + Cnt[L - 1]) {
        return 1 + Paty[L - 1];
    }
    if (Left <= 2 + Cnt[L - 1] * 2) {
        return 1 + Paty[L - 1] + dfs(L - 1, Left - 2 - Cnt[L - 1]);
    }
    return 1 + Paty[L - 1] * 2;
}

int main ()
{
    ll N,X;
    cin >> N >> X;

    ll cnt = 1;
    ll pcnt = 1;
    for (ll i = 0; i < 100; i++) {
        Cnt[i] = cnt;
        Paty[i] = pcnt;
        cnt = cnt * 2 + 3;
        pcnt = pcnt * 2 + 1;
    }

    cout << dfs(N, X) << endl;

    return 0;
}
