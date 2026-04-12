/*
 *
 * Author: r3gz3n
 * 
 * 3b 13 12 9 56 4e
 * 6 56 a a 5f f
 * 6 56 47 18 56 d
 * 13 46 14 1f 13 27
 * 52 52 a 5a 47 1
 * 1d 13 b 1b 49 17
 *
 */


#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;


#define ll long long


#define rep(i, a, b, k) for(__typeof(a) i = a;i < b;i += k)
#define repi(i, a, b, k) for(__typeof(a) i = a;i > b;i -= k)


#define endl '\n'


class Solution {
public:
    const static int MOD = 998244353;
    const static int MAX = 3005;
    int a[MAX];
    ll dp[MAX];
    void solve(std::istream& in, std::ostream& out) {
        int n, s;
        ll ans = 0;
        in >> n >> s;
        rep(i, 0, n ,1) in >> a[i];
        memset(dp, 0, sizeof(dp));
        rep(i, 0, n, 1) {
            (dp[0] += 1) %= MOD;
            repi(j, s, a[i]-1, 1) {
                (dp[j] += dp[j-a[i]]) %= MOD;
            }
            (ans += dp[s]) %= MOD;
        }
        out << ans << endl;
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}


#include <fstream>
#include <iostream>


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}

