#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

constexpr ll INF = 1e18;

int main() {
    ll N, M, W, T;
    cin >> N >> M >> W >> T;
    map<string, int> idx;
    vector<ll> w(M), p(M);
    for(int i=0; i<M; ++i) {
        string s;
        cin >> s >> w[i] >> p[i];
        idx[s] = i;
    }

    vector<vector<pii>> value(N);
    vector<ll> x(N), y(N);
    for(int i=0; i<N; ++i) {
        int L;
        cin >> L >> x[i] >> y[i];
        for(int j=0; j<L; ++j) {
            string R;
            ll Q;
            cin >> R >> Q;
            int id = idx[R];
            value[i].emplace_back(w[id], p[id] - Q);
        }
    }

    vector<pii> cand;
    for(int S=0; S<1<<N; ++S) {
        vector<pii> used;
        vector<pii> pos;
        for(int i=0; i<N; ++i) {
            if((S >> i) & 1) {
                for(auto& p : value[i]) {
                    used.push_back(p);
                }
                pos.emplace_back(x[i], y[i]);
            }
        }
        ll d = INF;
        sort(pos.begin(), pos.end());
        do {
            ll t = 0;
            pii now = make_pair(0, 0);
            for(int i=0; i<pos.size(); ++i) {
                t += abs(now.first - pos[i].first) + abs(now.second - pos[i].second);
                now = pos[i];
            }
            t += abs(now.first) + abs(now.second);
            d = min(d, t);
        } while(next_permutation(pos.begin(), pos.end()));
        vector<ll> dp2(W+1, -1);
        dp2[0] = 0;
        ll max_v = 0;
        for(int i=0; i<used.size(); ++i) {
            ll w = used[i].first;
            ll v = used[i].second;
            for(int j=0; j+w<=W; ++j) {
                if(dp2[j] == -1) {
                    continue;
                }
                dp2[j+w] = max(dp2[j+w], dp2[j] + v);
                max_v = max(max_v, dp2[j+w]);
            }
        }
        if(d <= T) {
            cand.emplace_back(d, max_v);
        }
    }
    vector<ll> dp(T+1, -1);
    dp[0] = 0;
    for(int i=0; i<cand.size(); ++i) {
        ll t = cand[i].first;
        for(int j=0; j+t<=T; ++j) {
            if(dp[j] == -1) {
                continue;
            }
            dp[j+t] = max(dp[j+t], dp[j] + cand[i].second);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}
