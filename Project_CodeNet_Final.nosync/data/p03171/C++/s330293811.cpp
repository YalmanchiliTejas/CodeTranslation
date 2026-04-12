/**
 * @author      : Luis Miguel Baez <es.luismiguelbaez@gmail.com>
 * @created     : Wednesday August 19, 2020
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ms(arr, value) memset(arr, value, sizeof(arr))
#define finally(value) {cout << value << '\n'; return;}
#define ll    int64_t

const int oo = int(1e9);
const ll lloo  = (ll)(1e18);
const int N_MAX = int(3001);

class Task {
public:
    int N;
    vector<int> A;

    ll dp[N_MAX][N_MAX];

    ll go(int l, int r, bool player) {
        if(l > r || l > N || r < 0) return 0LL;
        ll &ans = dp[l][r];
        if(ans != -1LL) return ans;
        ll sign = player?1LL:-1LL;
        ll first = A[l]*sign + go(l+1, r, !player);
        ll second = A[r]*sign + go(l, r-1, !player);
        ans = 0;
        if(player) ans = max(first, second);
        else ans = min(first, second);
        return ans;
    }

    void solveOne(istream &in, ostream &out) {
        in >> N;
        A.resize(N+1);
        for(int i = 1; i <= N; ++i){
            in >> A[i];
        }
        ms(dp, -1LL);
        ll ans = go(1, N, true);
        finally(ans);
    }
    
    void solve(istream &in, ostream &out) {
        int t=1;
        while(t--) solveOne(in, out);
    }
};

auto main() -> int {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Task solver;
    istream &in(cin);
    ostream &out(cout);
    solver.solve(in, out);
    return 0;
}
