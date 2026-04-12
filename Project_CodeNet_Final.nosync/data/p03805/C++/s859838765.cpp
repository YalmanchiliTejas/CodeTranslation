#include "bits/stdc++.h"

using namespace std;

using ll = long long;

constexpr char endl('\n');

#define FOR(i,l,r) for(size_t i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)

size_t smaller_count(size_t pos, vector<size_t> & v) {
    size_t k = v.at(pos);
    size_t ret = 0;
    FOR(i, pos + 1, v.size()) {
        if (k > v.at(i)) ++ret;
    }
    return ret;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;

    vector<size_t> v(n);
    REP(i, n) {
        v.at(i) = i + 1;
    }
    unordered_multimap<size_t, size_t> h;
    REP(i, m) {
        size_t a, b;
        cin >> a >> b;
        h.emplace(a, b);
        h.emplace(b, a);
    }
    size_t ret = 0;

    do {
        bool found = true;
        REP(i, n - 1) {
            auto p = h.equal_range(v.at(i));
            auto it = find_if(p.first, p.second, [&](auto pair) {return pair.second == v.at(i + 1); });
            if (it == p.second) {
                found = false;
                break;
            }
        }
        if (found) ++ret;
    } while (next_permutation(v.begin()+1, v.end()));
    cout << ret << ::endl;


    return 0;
}
