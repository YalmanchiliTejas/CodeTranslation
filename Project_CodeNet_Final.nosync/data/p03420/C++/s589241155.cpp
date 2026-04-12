#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 998244353;
const double e = exp(1);

void go() {
    int n, k;
    cin >> n >> k;
    ll ans = 1LL * n * n;
    for (int i = 1 ; i <= n ; i++) {
        int cnt = n / i * (min(i,k));
        cnt += min(max(0,k-1),n % i);
        ans -= cnt;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
}
