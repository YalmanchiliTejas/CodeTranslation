#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) std::cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) std::cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) std::cout << x << endl;
#define println(x) std::cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n;
    cin >> n;
    vector<ll> A(3 * n);
    rep(i, 3 * n) {
        cin >> A[i];
        A[i]--;
    }

    ll INF = 1e18;
    vector<vector<ll> > dp(n+1, vector<ll>(n+1, -INF));
    vector<ll> ma(n+1, -INF);
    dp[A[0]][A[1]] = 0;
    ma[A[0]] = 0;
    ma[A[1]] = 0;

    ll score = 0;
    rep(i, n-1) {
        sort(A.begin() + 2 + 3 * i, A.begin() + 2 + 3 * i + 3);
        ll x = A[2 + 3 * i];
        ll y = A[2 + 3 * i + 1];
        ll z = A[2 + 3 * i + 2];

        // a, b, x, y, zで並んでいる


        // x==y==z
        if (x == z) {
            score++;
            continue;
        }

        vector<vector<ll> > cand;
        if (x == y) {
            rep(p, n) {
                cand.push_back({
                    z,
                    p,
                    max(dp[x][p], dp[p][x]) + 1,
                });
            }
        }
        if (z == y) {
            rep(p, n) {
                cand.push_back({
                    x,
                    p,
                    max(dp[z][p], dp[p][z]) + 1,
                });
            }
        }

        rep(p, n) cand.push_back({ p, x, ma[p] });
        rep(p, n) cand.push_back({ p, y, ma[p] });
        rep(p, n) cand.push_back({ p, z, ma[p] });

        // 左２つがxyzのどれかと等しい場合
        cand.push_back({ x, y, dp[z][z] + 1});
        cand.push_back({ x, z, dp[y][y] + 1});
        cand.push_back({ y, z, dp[x][x] + 1});

        // 右3つのどれかを残す時、とにかく前回で一番成績が良いものを選ぶ
        ll tmp = -1;
        rep(p, n) tmp = max(ma[p], tmp);
        cand.push_back({ x, y, tmp});
        cand.push_back({ x, z, tmp});
        cand.push_back({ y, z, tmp});

        for (auto& c: cand) {
            dp[c[0]][c[1]] = max(dp[c[0]][c[1]], c[2]);
            ma[c[0]] = max(ma[c[0]], c[2]);
            ma[c[1]] = max(ma[c[1]], c[2]);
        }
    }

    ll res = max(0LL, *max_element(all(ma)));
    res = max(res, dp[A[3 * n - 1]][A[3 * n - 1]] + 1);    //
    res += score;

    put(res);
}
signed main(){ Main();return 0;}