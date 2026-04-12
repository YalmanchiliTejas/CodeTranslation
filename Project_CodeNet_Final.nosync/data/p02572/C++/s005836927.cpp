#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll m = 1e9 + 7;
#define MODS(a, b) ( (ll(a)%m + ll(b)%m)  % m)
#define MODM(a, b) (((ll(a)%m)*(ll(b)%m)) % m)
int main()
{
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> as = a;
    for (int i = n-2; i >= 0; i--) {
        as[i] = MODS(as[i], as[i+1]);
    }
    for (int i = 0; i < n-1; i++) {
        ans = MODS(ans, MODM(a[i], as[i+1]));
    }
    cout << ans << endl;
    return 0;
}