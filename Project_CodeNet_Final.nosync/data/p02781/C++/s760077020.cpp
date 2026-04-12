#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string N;
int K, l;
ll d[105][4][2]{};

int main() {

    cin >> N >> K;
    l = N.length();

    d[1][0][1] = 1;
    d[1][1][0] = 1;
    d[1][1][1] = N[0] - '0' - 1;
    for (int i = 1; i < l; i++) {
        ll s = N[i] - '0';
        if (s == 0) {
            for (int j = 0; j <= 3; j++) {
                d[i + 1][j][0] = d[i][j][0];
            }
            for (int j = 0; j < 4; j++) {
                d[i + 1][j][1] = d[i][j][1];
            }
            for (int j = 0; j < 3; j++) {
                d[i + 1][j + 1][1] += d[i][j][1] * 9ll;
            }
        } else {
            for (int j = 0; j < 3; j++) {
                d[i + 1][j + 1][0] = d[i][j][0];
            }
            for (int j = 0; j < 4; j++) {
                d[i + 1][j][1] = d[i][j][1] + d[i][j][0];
            }
            for (int j = 0; j < 3; j++) {
                d[i + 1][j + 1][1] += d[i][j][1] * 9ll + d[i][j][0] * (N[i] - '0' - 1);
            }
        }

        
    }
    ll ans = 0;
    cout << d[l][K][0] + d[l][K][1] << "\n";
    return 0;
}