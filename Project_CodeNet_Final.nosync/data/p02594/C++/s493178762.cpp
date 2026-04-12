#include <bits/stdc++.h>

using namespace std;

#define boost                         \
    ios_base::sync_with_stdio(false); \
    fin.tie(NULL);                    \
    fout.tie(NULL);
#define ll long long int
// #define int ll
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<ll, ll>
#define vii vector<pii>
#define pb push_back
#define B begin()
#define E end()
#define sz(A) (ll)(A).size()
#define F first
#define S second
#define loop(z, v) for (auto &z : v)
#define sp << ' ' <<
#define sps << ' '
#define nl "\n"
// #define nl endl
#define fat 1000000007
// #define fat 998244353
#define PI_2 1.57079632679489661923

int main()
{
    // boost;
    // ifstream fin;
    // fin.open("./fb_d1.txt");
    // ofstream fout;
    // fout.open("./d1_out.txt");

    time_t tic, toc;
    ll tt = 1, n, m, k = 0, i, j, p, q;
    ll a, b, c, h, w, u, v, x, y, t;
    ll l = 0, r = 0;
    ll ans = 0;

    bool poss = true;

    string s;

    // cin >> tt;
    tic = clock();
    for(int _ = 1; _ <= tt; _++){
        // cout << "Case #" << _ << ": ";
        cin >> n;
        
        cout << (n >= 30?"Yes":"No") << nl;
    }
    // fin.close();
    // fout.close();
    // cerr << (clock() - tic*1.0) / CLOCKS_PER_SEC << nl;
    return 0;
}
