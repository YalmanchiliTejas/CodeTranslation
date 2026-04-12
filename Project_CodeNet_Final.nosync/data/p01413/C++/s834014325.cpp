#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

template <typename T>
bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll N, M, T, W;
map<string, int> mp;
ll V[8], P[8];
ll L[7], X[7], Y[7];
string R[8][8];
ll Q[8][8];

void input() {
    cin >> N >> M >> W >> T;
    for(int i = 0; i < M; i++) {
        string s;
        cin >> s;
        mp[s] = i;
        cin >> V[i] >> P[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> L[i] >> X[i] >> Y[i];
        for(int j = 0; j < L[i]; j++) {
            cin >> R[i][j] >> Q[i][j];
        }
    }
}

ll dp[10500];
vector<l_l> Query;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    input();
    for(int bits = 1; bits < (1 << N); bits++) {
        ll dist = 1e18;
        vector<ll> v;
        for(int j = 0; j < N; j++) {
            if(bits & (1 << j)) v.push_back(j);
        }
        do {
            ll now = 0;
            now += abs(X[v[0]]) + abs(Y[v[0]]);
            for(int i = 1; i < v.size(); i++) {
                now += abs(X[v[i]] - X[v[i-1]]);
                now += abs(Y[v[i]] - Y[v[i-1]]);
            }
            now += abs(X[v.back()]) + abs(Y[v.back()]);
            chmin(dist, now);
        } while(next_permutation(v.begin(), v.end()));
        //cerr << bits << " " << dist << endl;
        for(int i = 0; i <= W; i++) dp[i] = 0;
        for(int i = 0; i < N; i++) {
            if(!(bits & (1 << i))) continue;
            for(int j = 0; j < L[i]; j++) {
                ll val = P[mp[R[i][j]]] - Q[i][j];
                ll w = V[mp[R[i][j]]];
                for(int k = 0; k <= W; k++) {
                    if(k + w <= W) {
                        chmax(dp[k+w], dp[k] + val);
                    }
                }
            }
        }
        ll maxval = 0;
        for(int i = 0; i <= W; i++) {
            chmax(maxval, dp[i]);
        }
        Query.push_back({dist, maxval});
        //cerr << bits << " " << maxval << endl;
    }
    for(int i = 0; i <= T; i++) dp[i] = 0;
    for(auto tmp : Query) {
        for(int i = 0; i <= T; i++) {
            if(i + tmp.first <= T) {
                chmax(dp[i+tmp.first], dp[i] + tmp.second);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= T; i++) {
        chmax(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
