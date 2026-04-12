/*
    Author: Nguyen Tan Bao
    Status:
    Idea:
*/
 
#include <bits/stdc++.h>
#define FI first
#define SE second
#define EPS 1e-9
#define ALL(a) a.begin(),a.end()
#define SZ(a) int((a).size())
#define MS(s, n) memset(s, n, sizeof(s))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
//__builtin_ffs(x) return 1 + index of least significant 1-bit of x
//__builtin_clz(x) return number of leading zeros of x
//__builtin_ctz(x) return number of trailing zeros of x
 
using namespace std;
using ll = long long;
using ld = double;
typedef pair<int, int> II;
typedef pair<II, int> III;
typedef complex<ld> cd;
typedef vector<cd> vcd;
 
const ll MODBASE = 1000000007LL;
const int MAXN = 110;
const int MAXM = 1000;
const int MAXK = 16;
const int MAXQ = 200010;

string a;
int K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> a >> K;
    int n = SZ(a);
    int res = 0;
    FOR(len,K,n) {
        if (len < n) {
            if (K == 1) {
                res += 9;
            }
            else if (K == 2) {
                FOR(j,2,len) res += 9 * 9;
            }
            else {
                FOR(j,2,len)
                    FOR(k,j+1,len) res += 9 * 9 * 9;
            }
        }
        else {
            if (K == 1) {
                res += a[0] - '0' - 1;
            }
            else if (K == 2) {
                FOR(j,2,len) res += (a[0] - '0' - 1) * 9;
            }
            else {
                FOR(j,2,len)
                    FOR(k,j+1,len) res += (a[0] - '0' - 1) * 9 * 9;
            }
            
            if (K == 1) res++;

            if (K == 2) {
                bool hasBigger = false;
                FOR(j,2,len) {
                    if (hasBigger) res += 9;
                    else {
                        if (a[j-1] > '0') {
                            res += a[j-1] - '0';
                            hasBigger = true;
                        }
                    }
                }
            }

            if (K == 3) {
                bool hasBigger = false;
                FOR(j,2,len) {
                    if (hasBigger) {
                        FOR(k,j+1,len) res += 9 * 9;
                    }
                    else {
                        if (a[j-1] > '0') {
                            bool hasBigger2 = false;
                            FOR(k,j+1,len) {
                                if (hasBigger2) res += (a[j-1] - '0') * 9;
                                else {
                                    if (a[k-1] > '0') {
                                        res += (a[j-1] - '0' - 1) * 9 + (a[k-1] - '0');
                                        hasBigger2 = true;
                                    }
                                }
                            }
                            hasBigger = true;
                        }
                    }
                }
            }
        }
    }
    cout << res;
    return 0;
}
