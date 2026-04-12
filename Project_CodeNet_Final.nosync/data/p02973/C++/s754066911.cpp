#pragma GCC optimize("O3,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("avx")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <random>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++) //0から
#define REP(i, n) for (int j = i; j < n; j++) //iから
#define in(a) cin >> a
#define out(a) cout << a << endl
typedef long long ll;

//cout<<fixed<<setprecision(10);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), end;
    rep(i, n) {
        cin >> a[i];
    }

    end.push_back(a[0]);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < end.size(); j++) {
            if (a[i] > end[j]) {
                end[j] = a[i];
                a[i] = -1;
                break;
            }
        }
        if (a[i] != -1) {
            end.push_back(a[i]);
        }
    }

    ans = end.size();

    cout << ans << '\n';

    return 0;
}
