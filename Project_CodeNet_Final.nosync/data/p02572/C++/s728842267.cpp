#include<iostream>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
constexpr auto mod = 1000000000 + 7;
constexpr auto maxn = 200000 + 5;
ll a[maxn];
void exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }

    exgcd(b, a % b, y, x);
    y -= a / b * x;
}
int main() {
    ll n, sum = 0, sum1 = 0,x,y;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++) {
        sum1 = (sum1 + (sum - a[i]) %mod * a[i] ) % mod;
    }
    exgcd(2, mod, x, y) ;
    cout << ((x+mod)%mod)*sum1%mod;
    return 0;
}