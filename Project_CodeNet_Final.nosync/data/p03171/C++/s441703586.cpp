#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define teto(a, b) ((a+b-1)/(b))
using namespace std;

const int MAX = 200010;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LLINF = 1000000000000000000;
const ld EPS = 1e-7;

// Extra
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define forne(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
//

int n;
vl v;
ll tab[3001][3001][2];

ll dp(int move, int st, int player) {
    if(move >= n) {
        return 0;
    }
    if(tab[move][st][player] != -1)
        return tab[move][st][player];
    int end = n-1 - (move-st);

    ll res = 0;
    if(player == 0) {
        ll val1 = v[st] + dp(move+1, st+1, !player);
        ll val2 = v[end] + dp(move+1, st, !player);
        res = max(val1, val2);
    }
    else {
        ll val1 = -v[st] + dp(move+1, st+1, !player);
        ll val2 = -v[end] + dp(move+1, st, !player);
        res = min(val1, val2);
    }

    return tab[move][st][player] = res;
}

int main() {
    memset(tab, -1, sizeof(tab));
    cin >> n;

    v.assign(n, 0);
    forn(i, n) {
        cin >> v[i];
    }

    cout << dp(0, 0, 0) << endl;

    return 0;
}
