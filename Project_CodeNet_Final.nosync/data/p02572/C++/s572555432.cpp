#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, a[200005];
long long p[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = n; i >= 1; i--) {
        p[i] = (p[i + 1] + a[i]) % mod;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + a[i] * p[i + 1]) % mod;
    }

    cout << ans << '\n';

    return 0;
}
