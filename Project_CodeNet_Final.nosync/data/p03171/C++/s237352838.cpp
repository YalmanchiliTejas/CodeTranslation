#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 100;

void doc() {
    freopen("OB.inp","r",stdin);
    freopen("OB.out","w",stdout);
    ///cerr << "OK" << '\n';
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    long long f[n][n][2];
    memset(f, 0, sizeof(f));
    for(int i = 0; i < n - 1; i++){
        f[i][i + 1][0] = - abs(a[i] - a[i + 1]);
        f[i][i + 1][1] = -f[i][i + 1][0];

        f[i][i][0] = -a[i];
        f[i][i][1] = a[i];
    }
    f[n - 1][n - 1][0] = -a[n - 1];
    f[n - 1][n - 1][1] = a[n - 1];
    for(int k = 2; k < n; k++)
    for(int i = 0; i + k < n; i++){
        int j = i + k;
        f[i][j][1] = max(f[i + 1][j][0] + a[i], f[i][j - 1][0] + a[j]);
        f[i][j][0] = min(f[i + 1][j][1] - a[i], f[i][j - 1][1] - a[j]);
        //cout << i << " " << j << " " << f[i][i + 1][0] << " " << f[i][i + 1][1] << '\n';
    }
    cout << f[0][n - 1][1];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
   /// doc();
    solve();
}

