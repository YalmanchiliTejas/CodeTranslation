#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int main(int argc, char **argv)
{
    string N;
    int K;
    cin >> N >> K;

    int L = N.length();

    if (L < K) {
        cout << 0 << endl;
        return 0;
    }

    ll count = 0;
    FOR(i, 1, L) {
        if (i >= K) {
            // (i - 1) C (K - 1)
            if (K == 1) {
                count += 9;
            }
            else if (K == 2) {
                count += 9 * 9 * (i - 1);
            }
            else {
                count += 9 * 81 * (i - 1) * (i - 2) / 2;
            }
        }
    }
    // L-th digit
    // N[L -1] == p
    int p = (int)(N[0] - '0');
    ll lp = 0;
    // L-th digit is less than p
    if (K == 1) lp = p - 1;
    else if (K == 2) lp = (p - 1) * 9 * (L - 1);
    else lp = (p - 1) * 81 * (L - 1) * (L - 2) / 2;

    // L-th digit is equal to p
    if (K == 1) lp += 1;
    else if (K == 2) {
        ll c = 0;
        bool f = false;
        FOR(i, 1, L) {
            if (f) {
                c += 9;
            }
            else {
                int a = (int)(N[i] - '0');
                if (a > 0) {
                    f = true;
                    c += a;
                }
            }
        }
        lp += c;
    }
    else {
        // search non-zero digit
        int d = 1;
        FOR(i, 1, L) {
            int a = (int)(N[i] - '0');
            if (a > 0) {
                d = i;
                break;
            }
        }

        int q = (int)(N[d] - '0');
        ll lq = 0;
        // d-th digit is equal to 0
        lq += 81 * (L - d - 1) * (L - d - 2) / 2;
        // d-th digit is 1 ~ q-1
        lq += (q - 1) * 9 * (L - d - 1);

        // (L-1)-th digit is equal to q
        ll c = 0;
        bool f = false;
        FOR(i, d + 1, L) {
            if (f) {
                c += 9;
            }
            else {
                int a = (int)(N[i] - '0');
                if (a > 0) {
                    f = true;
                    c += a;
                }
            }
        }
        lq += c;
        lp += lq;
    }
    cout << count + lp << endl;

    return 0;
}
