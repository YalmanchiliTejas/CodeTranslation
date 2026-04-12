#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pii pair <int, int>
#define F first
#define S second
#define ll long long
#define io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define M_PI 3.14159265358979323846
const int N = 200005;
const int mod = 1e9 + 7;
ll pre[N];
int main() {
    io;
    int n, a[N];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pre[i] = a[i];
        if(i) pre[i] += pre[i - 1];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += (pre[i] - a[i]) % mod * a[i] % mod;
        ans %= mod;
    }
    cout << ans << endl;
}
