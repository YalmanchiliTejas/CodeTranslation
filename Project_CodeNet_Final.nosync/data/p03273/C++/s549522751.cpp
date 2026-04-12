#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

long long mod = 1000000007;

long long div(long long a, long long b, long long c) { return b / c - (a - 1) / c; }

void print_binary(long long a) {
    for (int i = 31; i >= 0; i--) {
        cout << (a >> i & 1);
    }
    cout << endl;
}
long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}
void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}

int main() {
    long long h, w;
    cin >> h >> w;
    vector<vector<char>> as(h, vector<char>(w));
    vector<vector<char>> bs;
    vector<int> badh(h);
    vector<int> badw(w);
    for (int i = 0; i < h; i++) {
        int hgood = 0;
        int wgood = 0;
        for (int j = 0; j < w; j++) {
            cin >> as[i][j];
            if (as[i][j] == '#') {
                hgood++;
            }
        }
        if (hgood == 0) {
            badh[i]++;
        }
    }
    // // cout << "hogrider" << endl;
    for (int j = 0; j < w; j++) {
        int hgood = 0;
        int wgood = 0;
        for (int i = 0; i < h; i++) {
            // cout << i << " " << j << endl;
            if (as[i][j] == '#') {
                wgood++;
            }
        }
        if (wgood == 0) {
            badw[j]++;
        }
    }
    // // cout << "hogrider" << endl;
    for (int i = 0; i < h; i++) {
        int a = 0;
        for (int j = 0; j < w; j++) {
            // cout << h << " " << w << endl;
            // cout << "hogrider" << endl;
            if (badh[i] == 0 && badw[j] == 0) {
                cout << as[i][j];
                a++;
                // cout << "hogrider" << endl;
            }
        }
        if (a > 0) {
            cout << endl;
        }
    }
    // cout << "hogrider" << endl;
    // for (int i = 0; i < bs.size(); i++) {
    //     for (int j = 0; j < bs[i].size(); j++) {
    //         cout << bs[i][j] << endl;
    //         // cout << "hogrider" << endl;
    //     }
    // }
    // cout << "hogrider" << endl;
}