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
        int n;
        cin >> n;
        if(!n) break;
        vector<int> s(n);
        for(int i = 0; i < n; ++i){
            cin >> s[i];
        }
        cout << (accumulate(s.begin(), s.end(), 0) - *max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end())) / (n-2) << "\n";
    }
    return 0;
}

