#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> ans;
    vector<bool> visit(m, false);
    while(1) {
        if (visit[x]) {
            ans.push_back(x);
            break;
        }
        visit[x] = true;
        ans.push_back(x);
        x = x * x % m;
    }
    bool herasu = true;
    ll mae = 0;
    ll sum = 0;
    ll roopsize = 0;
    int roopstart;
    rep(i, ans.size() - 1) {
        if (ans[ans.size() - 1] == ans[i]) {
            roopstart = i;
            herasu = false;
        }
        if (herasu) {
            mae += ans[i];
            n--;
        }
        else {
            sum += ans[i];
            roopsize++;
        }
    }
    mae += n / roopsize * sum;
    n %= roopsize;
    for (int i = roopstart; i < roopstart + n; i++) {
        mae += ans[i];
    }
    cout << mae << endl;
    return 0;
}
