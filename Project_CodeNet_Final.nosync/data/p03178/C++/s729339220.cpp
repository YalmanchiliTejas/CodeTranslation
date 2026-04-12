#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
#define keep_calm_and_become_orange ios_base::sync_with_stdio(0)
#define utochka_po_imeni_jonathan_livingston cin.tie(0)
 
using namespace std;
 
void yes() {
    cout << "YES" << endl;
}
 
void no() {
    cout << "NO" << endl;
}
 
long long bp(long long a, long long p, long long mod) {
    if (p == 0) {
        return 1ll;
    } else if (p % 2 == 1) {
        return bp(a, p - 1, mod) * a % mod;
    } else {
        long long res = bp(a, p / 2, mod);
        return res * res % mod;
    }
}

const long long mod = 1e9 + 7;

void solve(int qq) { 
    string s; int d;
    cin >> s >> d;
    int n = int(s.size());
    vector<vector<long long> > dp(d, vector<long long>(2));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        vector<vector<long long> > dp_new(d, vector<long long>(2));
        for (int sum = 0; sum < d; sum++) {
            for (int j = 0; j < 2; j++) {
                for (int last = 0; last < 10; last++) {
                    int here = s[i] - '0';
                    if (last > here and !j) break;
                    else if (last < here or j) {
                        dp_new[(sum + last) % d][1] += dp[sum][j];
                        dp_new[(sum + last) % d][1] %= mod;
                    } else {
                        dp_new[(sum + last) % d][0] += dp[sum][j];
                        dp_new[(sum + last) % d][0] %= mod;
                    }
                }
            }
        }
        for (int sum = 0; sum < d; sum++) {
            for (int j = 0; j < 2; j++) {
                dp[sum][j] = dp_new[sum][j];
            }
        }
    }
    cout << (dp[0][0] + dp[0][1] + mod - 1) % mod << endl;
}   
 
int main()
{
    keep_calm_and_become_orange;
    utochka_po_imeni_jonathan_livingston;
 
    int t; t = 1;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}