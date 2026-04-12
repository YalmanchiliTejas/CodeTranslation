#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int r, g, b; cin >> r >> g >> b;
    
    int n = r * 100 + g * 10 + b;
    cout << ((n % 4 == 0) ? "YES" : "NO") << endl;
    return 0;
}
