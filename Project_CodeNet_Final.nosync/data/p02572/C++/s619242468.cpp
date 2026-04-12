#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <set>
#include <map>
#include <string>
#include <math.h>

using namespace std;

#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define swap2(x, y) x=x^y; y=x^y; x=x^y;
#define print(x) if (false) {cout << "[" << #x << " = " << x << "] ";}
#define printNL() if (false) {cout << endl;}

const int BASE = 1e9 + 7;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<long long> prefix(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        prefix[i] = a[i];
    }
    for (int i = 1; i < n; ++i) prefix[i] += prefix[i-1];

    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += (prefix[i-1] % BASE) * a[i] % BASE;
        ans %= BASE;
    }
    cout << ans << endl;

    return 0;
}
