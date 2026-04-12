#include<algorithm>
#include<iostream>
#include<cmath>
#include<string>
#define MOD 1000000007
using namespace std;
string str;
int d, f[10005][100], len, a[10005], b[10005];
long long ans;
int main() {
    cin >> str;
    cin >> d;
    len = str.size();
    a[0] = 1;
    b[0] = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < d; j++)
            for (int l = 0; l < 10; l++)
                f[i + 1][(j + l) % d] = (f[i + 1][(j + l) % d] + f[i][j]) % MOD;
        for (int j = 0; j < str[i] - '0'; j++)
            f[i + 1][(b[i] + j) % d] = (a[i] + f[i + 1][(b[i] + j) % d]) % MOD;
        a[i + 1] = a[i];
        b[i + 1] = (b[i] + str[i] - '0') % d;
    }
    ans = f[len][0] - 1;
    if (!b[len]) ans++;
    ans = (ans + MOD) % MOD;
    cout << ans;
}