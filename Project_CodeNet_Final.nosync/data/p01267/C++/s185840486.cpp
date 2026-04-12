#include <bits/stdc++.h>

#define CEIL(a,b) ((a) / (b) + ((a) % (b) == 0 ? 0 : 1))

using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int MOD = 1'000'000'007;
constexpr int INF = 1'000'000'001;
constexpr ll LLINF = 4'000'000'000'000'000'001;
// constexpr int INF = 2147483647; // 2 * 1e9
// constexpr ll LLINF = 9223372036854775807; // 9 * 1e18

const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    while(true){
        int n, a, b, c, x;
        cin >> n >> a >> b >> c >> x;
        if(n == 0) break;
        vector<int> y(n);
        for(int i = 0; i < n; ++i){
            cin >> y[i];
        }
        int ans = 0, r = x;
        for(int i = 0; i < n; ++i){
            while(y[i] != r){
                if(ans > 10000) break;
                r = (r * a + b) % c;
                ++ans;
            }
            if(i != n-1){
                r = (r * a + b) % c;
                ++ans;
            }
        }
        if(ans > 10000) ans = -1;
        cout << ans << "\n";
    }
    return 0;
}
