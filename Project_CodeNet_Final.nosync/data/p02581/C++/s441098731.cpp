#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;

struct DP{
    ll allmax;
    vector<ll> maxval;
    vector<vector<ll>> dp;

    vector<array<ll, 3>> toset;

    DP(ll n, ll a0, ll a1) : allmax(0), maxval(n, - n - 1), dp(n, vector<ll>(n, - n - 1)) {
        dp[a0][a1] = 0;
        dp[a1][a0] = 0;
        maxval[a0] = 0;
        maxval[a1] = 0;
    }

    void set(ll x, ll y, ll v){
        if(x >= dp.size() || x < 0 || y >= dp.size() || y < 0){ return; }
        toset.push_back({x, y, v});
    }

    void apply(){
        for(const auto& arr : toset){
            const ll x = arr[0], y = arr[1], v = arr[2];
            dp[x][y] = max(dp[x][y], v);
            dp[y][x] = dp[x][y];
            allmax = max(allmax, dp[x][y]);
            maxval[x] = max(maxval[x], dp[x][y]);
            maxval[y] = max(maxval[y], dp[x][y]);
        }
        toset.clear();
    }
};


int main(){
    ll n;
    cin >> n;
    vector<ll> a(3 * n);
    REP(i, 3 * n){
        cin >> a.at(i);
        a.at(i)--;
    }

    a.push_back(n);
    a.push_back(n + 1);


    DP dp(n + 2, a.at(0), a.at(1));
    ll base = 0;
    for(ll i = 2; i < a.size(); i += 3){
        vector<ll> tmp;
        REP(j, 3){ tmp.push_back(a.at(i + j)); }
        sort(ALL(tmp));
        if(tmp[0] == tmp[1] && tmp[1] == tmp[2]){
            base++;
        }else{
            const ll a = tmp[0], b = tmp[1], c = tmp[2];

            dp.set(b, c, dp.dp[a][a] + 1); // a で揃えられる
            dp.set(a, c, dp.dp[b][b] + 1); // b で揃えられる
            dp.set(a, b, dp.dp[c][c] + 1); // c で揃えられる

            // a, b, c から 2 つ選んで残す
            dp.set(a, b, dp.allmax);
            dp.set(a, c, dp.allmax);
            dp.set(b, c, dp.allmax);

            // a, b, c から 1 つ、x, y から 1 つ選ぶ
            REP(x, n){
                dp.set(a, x, dp.maxval[x]);
                dp.set(b, x, dp.maxval[x]);
                dp.set(c, x, dp.maxval[x]);
            }

            if(a == b){
                REP(x, n){
                    dp.set(c, x, dp.dp[a][x] + 1);
                }
            }
            if(b == c){
                REP(x, n){
                    dp.set(a, x, dp.dp[b][x] + 1);
                }
            }
            dp.apply();

        // }else if(tmp[0] == tmp[1] || tmp[1] == tmp[2]){
        //     ll a, b;
        //     if(tmp[0] == tmp[1]){
        //         a = tmp[0];
        //         b = tmp[2];
        //     }else{
        //         assert(tmp[1] == tmp[2]);
        //         a = tmp[1];
        //         b = tmp[0];
        //     }

        //     REP(x, n){
        //         // a で 3 つ揃える
        //         dp.set(b, x, dp.dp[a][x] + 1);
        //         // b で 3 つ揃える
        //         dp.set(a, x, dp.dp[b][b] + 1);
        //     }
        //     dp.apply();
        // }else{
        //     // all different
        //     assert(tmp[0] != tmp[1] && tmp[1] != tmp[2]);
        //     const ll a = tmp[0], b = tmp[1], c = tmp[2];
        //     // a, b, c, x, y

        //     dp.set(b, c, dp.dp[a][a] + 1); // a で揃えられる
        //     dp.set(a, c, dp.dp[b][b] + 1); // b で揃えられる
        //     dp.set(a, b, dp.dp[c][c] + 1); // c で揃えられる

        //     // a, b, c から 2 つ選んで残す
        //     dp.set(a, b, dp.allmax);
        //     dp.set(a, c, dp.allmax);
        //     dp.set(b, c, dp.allmax);

        //     // a, b, c から 1 つ、x, y から 1 つ選ぶ
        //     REP(x, n){
        //         dp.set(a, x, dp.maxval[x]);
        //         dp.set(b, x, dp.maxval[x]);
        //         dp.set(c, x, dp.maxval[x]);
        //     }
        //     dp.apply();
        }
    }

    cout << base + dp.allmax << endl;
    return 0;
}
