#include<iostream>
#include<iomanip>
using std::cin;
using std::cout;
constexpr int mod = 1e9 + 7;
int n, a[1000010];
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //cout << std::setiosflags(std::ios::fixed) << std::setprecision(3);
    cin >> n;
    long long sum = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ans += sum * a[i];
        ans %= mod;
        sum += a[i];
        sum %= mod;
    }
    cout << ans << '\n';
    return 0;
}
