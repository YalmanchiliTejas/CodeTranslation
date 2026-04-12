#include <bits/stdc++.h>

#define CEIL(a,b) ((a) / (b) + ((a) % (b) == 0 ? 0 : 1))

using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int MOD = int(1e9 + 7);
constexpr int INF = int(1e9 + 1);
constexpr ll LLINF = ll(4 * 1e18 + 1);
// constexpr int INF = 2147483647; // 2 * 1e9
// constexpr ll LLINF = 9223372036854775807; // 9 * 1e18

const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }
    int ans = 0, ma = 0;
    for(int i = 0; i < n; ++i){
        if(h[i] >= ma) ++ans;
        ma = max(ma, h[i]);
    }
    cout << ans << "\n";
    return 0;
}