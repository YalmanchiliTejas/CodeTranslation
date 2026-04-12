#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 10;
int a[N];
long long f[N][N];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i]; 

    for(int st = n; st >= 1; st--)
        for(int en = st; en <= n; en++) 
            f[st][en] = max(a[st] - f[st + 1][en], a[en] - f[st][en - 1]);
    cout << f[1][n];
}
