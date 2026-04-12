#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX_N = 1e5;

int main(){
    ll n, res=0, s[MAX_N]={}, used[MAX_N]={};

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (int c = 1; c <= n - 2; ++c) {
        ll f = 0;
        for (int mc = 0; c < n - 1 - mc; mc += c) {
            used[mc] = c;
            if (used[n - 1 - mc] >= c) break;
            f += s[mc] + s[n - 1 - mc];
            res = max(res, f);
        }
    }

    cout << res << endl;
    return 0;
}