#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using vint = vector<int>;
using vll = vector<ll>;
template<typename T> using uset = unordered_set<T>;
template<typename T1, typename T2> using umap = unordered_map<T1, T2>;

constexpr int INF = (1 << 30) - 1;
constexpr ll LLINF = 1LL << 60;
constexpr int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr char el = '\n';
constexpr int mod = 1000000007;

template<typename T> T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }
template<typename T> T lcm(T a, T b) { return (a / gcd(a, b) * b); }
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

int main() {
        int N;
        Pl pp[200005];
        ll maxv = -LLINF;
        ll minv = LLINF;
        ll minr = LLINF;

        multiset<ll>st; 
        cin >> N;
        for (int i = 0; i < N; i++) {
                cin >> pp[i].first >> pp[i].second;
                if (pp[i].first > pp[i].second) swap(pp[i].first, pp[i].second);
                maxv = max(maxv, pp[i].second);
                minv = min(minv, pp[i].first);
                minr = min(minr, pp[i].second);
                st.insert(pp[i].first);
        }

        sort(pp, pp + N);
        ll ans = LLINF;
        for (int i = 0; i < N; i++) {
                st.erase(st.find(pp[i].first));
                st.insert(pp[i].second);
                ans = min(ans, (*st.rbegin() - *st.begin()) * (maxv - minv));
        }
        cout << min(ans, (pp[N - 1].first - pp[0].first) * (maxv - minr)) << endl;
    return (0);
}
