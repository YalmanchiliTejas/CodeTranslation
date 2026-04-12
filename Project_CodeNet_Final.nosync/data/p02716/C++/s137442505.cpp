#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <istream>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <time.h>
#include <chrono>
#include <cstdio>
#include <fstream>
using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin() , x.end()
#define deb(z) cout << #z << ' ' << z << '\n';
#define pb push_back
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("test.txt" , "r" , stdin);
    //freopen("jump.out" , "w" , stdout);
    ll n;
    cin >> n;
    vector <ll> p(n);
    for(auto &x : p) {
        cin >> x;
    }
    vector <ll> dp(n - n % 2);
    dp[0] = p[0];
    dp[1] = p[1];
    for(int i = 2; i < dp.size(); i++) {
        if(i % 2) {
            dp[i] = p[i] + max(dp[i - 2] , dp[i - 3]);
        } else {
            dp[i] = p[i] + dp[i - 2];
        }
    }
    ll ans = max(dp[dp.size() - 1] , dp[dp.size() - 2]);
    if(n % 2) {
        ll tmp = 0;
        for (int i = dp.size() - 1; i >= 0; i -= 2) {
            ans = max(ans, p.back() + tmp + (i - 2 >= 0 ? dp[i - 2] : 0));
            tmp += p[i - 1];
        }
    }
    cout << ans;
    return 0;
}