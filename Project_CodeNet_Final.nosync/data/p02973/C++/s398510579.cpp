#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n;
    cin >> n;
    multiset<int> s;
    rep(i,n) {
        int a;
        cin >> a;
        auto iter = s.lower_bound(a);
        if (iter != s.begin()) s.erase(--iter);
        s.insert(a);
    }
    int ans = s.size();
    cout << ans << endl;
    return 0;
}