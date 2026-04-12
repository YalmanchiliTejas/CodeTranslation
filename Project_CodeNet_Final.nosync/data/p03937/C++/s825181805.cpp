#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (ll i = 0; i < (ll) (n); ++i)
#define sz(a) static_cast<int>((a).size())
#define pb emplace_back
#define mp make_pair
#define endl '\n'
#define f first
#define s second

#ifdef SEREZHKA
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T>
void _dbg(const char* _s, T _h) { cerr << _s << " = " << _h << "\n"; }

template<typename T, typename... Ts>
void _dbg(const char*_s, T _h, Ts... _t) {
    int _b = 0;
    
    while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',')
        cerr << *_s++;
    
    cerr << " = " << _h << ",";
    _dbg(_s + 1, _t...);
}

using ll = long long;

const ll INF = static_cast<ll>(1e9) + 7ll;
const ll LINF = INF * INF;
const int MAXN = static_cast<int>(2e5) + 17;

int n, m;
string s[MAXN];

bool read() {
    if (!(cin >> n >> m))
        return false;

    forn (i, n)
        cin >> s[i];

    return true;
}

void solve() {
    int i = 0, j = 0;

    while (i < n || j < m) {
        if (s[i][j] != '#') {
            cout << "Impossible\n";
            return ;
        }

        s[i][j] = '.';

        if (i == n - 1 && j == m - 1)
            break;

        if (i < n && s[i + 1][j] == '#')
            ++i;
        else if (j < m && s[i][j + 1] == '#')
            ++j;
        else {
            cout << "Impossible\n";
            return ;
        }
    }

    int cnt = 0;

    forn (i, n)
        cnt += count(s[i].begin(), s[i].end(), '#');

    cout << (cnt ? "Impossible" : "Possible") << endl;
}

int main() {
    cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
#ifdef SEREZHKA
    freopen("file.in", "r", stdin);
#endif
    
    while (read())
        solve();
    
    return 0;
}

