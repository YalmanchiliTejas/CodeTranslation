#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int n, k, h[maxn];
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n) {
        int H = 0, ans = 0;
        for(int i = 0; i < n; ++i) {
            cin >> h[i];
            H = max(h[i], H);
            if(h[i] >= H) ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}
