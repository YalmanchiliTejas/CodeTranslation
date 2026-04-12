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
    int n;
    cin >> n;
    vector<int> a(n);
    int m = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<int> tp;
    tp.push_back(a[0]);
    for(int i = 1; i < n; ++i){
        auto aa = lower_bound(rbegin(tp), rend(tp), a[i]) - tp.rbegin();
        if(lower_bound(rbegin(tp), rend(tp), a[i]) == tp.rbegin() && *rbegin(tp) >= a[i]){
            tp.push_back(a[i]);
        }
        else{
            for(int j = 0; j < tp.size(); ++j)
            {
                if(tp[j] < a[i]){
                    tp[j] = a[i];
                    break;
                }
            }
        }
    }
    cout << tp.size() << "\n";
    return 0;
}