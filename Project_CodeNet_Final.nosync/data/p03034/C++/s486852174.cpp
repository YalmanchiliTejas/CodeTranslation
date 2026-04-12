#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<ll> v(n, 0);
    for(int i = 0; i < n; i ++)
        cin >> v[i];

    vector<vector<ll>> fromleft(n);
    vector<vector<ll>> fromright(n);
    for(int step = 1; step < n; step ++) {
        for(int i = 0; i < n; i += step) {
            if(fromleft[step].size() == 0)
                fromleft[step].push_back(0);
            else
                fromleft[step].push_back(fromleft[step].back());
            fromleft[step].back() += v[i];
        }

        for(int i = n - 1; i >= 0; i -= step) {
            if(fromright[step].size() == 0)
                fromright[step].push_back(0);
            else
                fromright[step].push_back(fromright[step].back());
            fromright[step].back() += v[i];
        }
    }

    ll ans = 0; /// cazul cand sar direct din 0 in n - 1
    for(int dif = 1; dif <= n - 3; dif ++) {
        for(int multiple = dif; multiple <= n - 3; multiple += dif) {
            int a = n - 1 - multiple;
            int b = a - dif;

            if(a > b && b > 0 & a > 0 && (n - 1 < 2 * a || a % (a - b))) {
                ll l = fromleft[dif][multiple / dif];
                ll r = fromright[dif][multiple / dif];
                ans = max(ans, r + l);

                //cout << a << " " << b << " " << multiple / dif << endl;
            }
        }
    }
    cout << ans;


    return 0;
}
