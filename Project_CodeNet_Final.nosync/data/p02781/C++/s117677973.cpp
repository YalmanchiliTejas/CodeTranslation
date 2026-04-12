#include <bits/stdc++.h>
//#include <ext/numeric>


using namespace std;
//using namespace __gnu_cxx;

const int MAXN = (int)1e3 + 5;
const int MAXM = (int)1e4 + 5;

const int MOD = 1000000007;

long long mul(long long a , long long b) {
    return a * b % MOD;
}

long long power(long long a , long long b) {
    if (!b) return 1;
    long long r = power(a , b / 2);
    r = mul(r , r);
    if (b&1) return mul(r , a);
    return r;
}

long long mod_inv(long long x) {
    return power(x , MOD - 2);
}



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0), cout.precision(10), cout << fixed;

    string str;
    int k;
    cin >> str >> k;
    int n = (int) str.size();
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        if (k == 1)
            ans += 9;
        else if (k == 2) {
            for (int j = 2; j <= i; ++j) {
                ans += 81;
            }
        } else {
            for (int j = 2; j <= i; ++j) {
                for (int jj = j + 1; jj <= i; ++jj) {
                    ans += 81 * 9;
                }
            }
        }
    }

    if (k == 1)
        ans += str[0] - '0';
    else if (k == 2) {
        for (int i = 1; i <= str[0] - '0'; ++i) {
            bool f = i == str[0] - '0';
            for (int j = 1; j < n; ++j) {
                if (!f)
                    ans += 9;
                else
                    ans += str[j] - '0';
                f &= str[j] - '0' == 0;
            }
        }
    } else {
        for (int i = 1; i <= str[0] - '0'; ++i) {
            bool f = i == str[0] - '0';
            for (int j = 1; j < n; ++j) {
                for (int a = 1; a <= (f ? str[j] - '0' : 9); ++a) {
                    bool ff = f;
                    ff &= a == str[j] - '0';
                    for (int jj = j + 1; jj < n; ++jj) {
                        if (!ff)
                            ans += 9;
                        else
                            ans += str[jj] - '0';
                        ff &= str[jj] == '0';
                    }
                }
                f &= str[j] - '0' == 0;
            }
        }
    }


    cout << ans << '\n';


    return 0;
}