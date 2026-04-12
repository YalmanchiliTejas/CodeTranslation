#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;

template <class T>
using max_heap = priority_queue<T>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <class T, class U>
void chmax(T &a, U b) {
    if (a < b) a = b;
}
template <class T, class U>
void chmin(T &a, U b) {
    if (b < a) a = b;
}

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define debug(x) cerr << #x << ": " << x << endl;
#define int ll

const ll mod = 1e9 + 7;
const ll inf = (1LL << 50);

const string YES = "Yes";
const string NO = "No";
void solve(std::string S) {

    set<char> s;
    for (auto c : S) s.insert(c);

    if (s.size() > 1) {
        cout << YES << endl;
    } else {
        cout << NO << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
