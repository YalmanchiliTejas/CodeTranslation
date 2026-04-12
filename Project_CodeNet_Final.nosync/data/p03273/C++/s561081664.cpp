#pragma GCC optimize("O3")

/****Author: Barish Namazov****/
#include <bits/stdc++.h>

using namespace std;

/***TEMPLATE***/
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define F first
#define S second
#define pb push_back

#define endl '\n'

const int max4 = 10004;
const int maxx = 100005;
const int max6 = 1000006;
const int lg5 = 17;

const int INF = 2 * 1000000007;
const long long INFLL = 4LL * 1000000000 * 1000000000;

/***************/

int powmod (int a, int b, int mod) {
    int res = 1; a %= mod;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = 1LL * res * a % mod;
        }
        a = 1LL * a * a % mod;
    }
    return res;
}

int gcd (int a, int b) {
    while (b > 0) {
        int t = a % b;
        a = b, b = t;
    }
    return a;
}

int lcm (int a, int b) {
    return (a / gcd (a, b)) * b;
}

int is_prime (int n) {
    if (n <= 1 || n > 3 && (n % 2 == 0 || n % 3 == 0))
        return 0;
    for (int i = 5, t = 2; i * i <= n; i += t, t = 6 - t)
        if (n % i == 0)
            return 0;
    return 1;
}

/******Don't forget to use long long when needed!!******/

char arr[105][105];
int col[105], row[105];
int main() {
    //freopen("262144.in","r",stdin);
    //freopen("262144.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        int ok = 1;
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == '#') {
                ok = 0;
                break;
            }
        }
        if (ok == 1) {
            col[i] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        int ok = 1;
        for (int j = 1; j <= n; j++) {
            if (arr[j][i] == '#') {
                ok = 0;break;
            }
        }
        if (ok == 1) {
            row[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (col[i] == 1) continue;
        for (int j = 1; j <= m; j++) {
            if (row[j] == 1) continue;
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}
