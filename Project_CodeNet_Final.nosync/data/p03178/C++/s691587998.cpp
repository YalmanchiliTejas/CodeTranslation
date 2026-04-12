#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pi> vp;
typedef vector<pl> vpl;

const int mod = 1e9 + 7;

void f(int& x){
    x += 2 * mod;
    if (x >= mod)
        x %= mod;
}

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 
    cerr.tie(nullptr);    

    string k;
    cin >> k;

    int d;
    cin >> d;

    int n = k.length();

    vector<vi> dp(d, vi(2, 0));
    //dp[i][j] - broj nacina da napravimo sumu i ako jesmo/nismo (j=0v1) uzeli manju cifru do sad

    dp[0][0] = 1;
    for (int i = 0; i < n; ++i){
        vector<vi> new_dp(d, vi(2, 0));
        for (int suma = 0; suma < d; ++suma){
            for (int j = 0; j < 2; ++j){
                for (int b = 0; b < 10; ++b){
                    if (b > k[i] - '0' && !j) break;
                    new_dp[(suma + b) % d][j || (b < k[i] - '0')] += dp[suma][j];
                    f(new_dp[(suma + b) % d][j || (b < k[i] - '0')]);
                }
            }
        }
        dp = new_dp;
    }

    int sol = (dp[0][0] + dp[0][1]) % mod;
    --sol;
    if (sol == -1)
        sol = mod - 1;
    cout << sol << '\n';
}