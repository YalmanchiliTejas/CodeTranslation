#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    int n;
    while(cin >> n, n) {
        vector<pii> pos;
        int res = 0;
        for(int i = 0; i < n; ++i) {
            int s; cin >> s;
            if(i & 1) {
                int now = i;
                while(!pos.empty() && pos.back().first != s) {
                    int nxt = pos.back().second;
                    res += (s == 0 ? now - nxt : nxt - now);
                    now = nxt;
                    pos.pop_back();
                }
                if(pos.empty()) {
                    res += (s == 0 ? now : -now);
                }
            }
            res += s == 0;
            pos.emplace_back(s, i);
        }
        cout << res << endl;
    }
}
