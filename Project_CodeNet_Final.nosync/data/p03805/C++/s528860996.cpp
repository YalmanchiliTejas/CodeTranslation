// https://atcoder.jp/contests/abc054/tasks/abc054_c

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct C {
    vector<ll> src_{};
    vector<ll> tgt_{};
    ll N_{};
    vector<vector<ll>> e_{};

    void visit(vector<ll>& visited, ll next, ll& count) {
        visited.emplace_back(next);
        if (visited.size() == N_) {
            ++count;
            visited.pop_back();
            return;
        }
        for(auto c : e_[next]) {
            if (std::find(visited.begin(), visited.end(), c) != visited.end()) {
                continue;
            }
            visit(visited, c, count);
        }
        visited.pop_back();
    }
    explicit C(vector<ll> src, vector<ll> tgt, ll N) : src_(move(src)), tgt_(move(tgt)), N_(N){}
    ll resolve() {
        ll M = src_.size();
        e_.resize(N_+1);
        for(int i=0; i < M; ++i) {
            e_[src_[i]].emplace_back(tgt_[i]);
            e_[tgt_[i]].emplace_back(src_[i]);
        }
        vector<ll> visited{};
        ll cur = 1;
        ll count = 0;
        visit(visited, 1, count);
        return count;
    }
};

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> src{};
    vector<ll> tgt{};
    for (int i=0; i < M; ++i) {
        ll x,y ;
        cin >> x >> y;
        src.emplace_back(x);
        tgt.emplace_back(y);
    }
    C c{move(src), move(tgt), N};
    cout << c.resolve() << endl;
    return 0;
}
