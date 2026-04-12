#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
bool check(vector <ii> p, int n, int m) {
    if (p[0] != mp(0, 0))
        return 0;
    if (p.back() != mp(n - 1, m - 1))
        return 0;
    for (int i = 0; i + 1 < p.size(); ++i) {
        if (p[i + 1] != mp(p[i].f + 1, p[i].s) && p[i + 1] != mp(p[i].f, p[i].s + 1))
            return 0;
    }   
    return 1;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    vector <ii> p;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            if (c == '#')
                p.app(mp(i, j));
        }   
    }   
    if (check(p, n, m))
        cout << "Possible" << endl;
    else 
        cout << "Impossible" << endl;
}