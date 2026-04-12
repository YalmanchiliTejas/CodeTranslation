#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int mod = 1e9 + 7;

string k;
int n, d, f[N][2][2][105];

void add (int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> k >> d; n = k.length(); k = "#" + k;
    f[0][1][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int ok = 0; ok < 2; ok++) {
            for (int app = 0; app < 2; app++) {
                for (int rem = 0; rem < d; rem++) {
                    if (f[i][ok][app][rem]) {
                        for (int nxt = 0; nxt <= (ok ? k[i + 1] - '0' : 9); nxt++) {
                            int nok = ok && (nxt == k[i + 1] - '0');
                            int napp = app || (nxt > 0);
                            int nrem = (rem + nxt) % d;
                            add(f[i + 1][nok][napp][nrem], f[i][ok][app][rem]);
                        }
                    }
                }
            }
        }
    }
    
    cout << (f[n][0][1][0] + f[n][1][1][0]) % mod;
    return 0;
}