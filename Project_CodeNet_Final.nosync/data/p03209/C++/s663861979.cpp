#include "bits/stdc++.h"
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vp;
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;
const int DIV = 1e9+7;

ll n, x;
vl width;
vl paty;

ll get_tabeta(int rank, ll taberu) {
    ll tabeta = 1;
    ll w = width[rank];
    // cout << rank << " " << taberu << endl;
    if (rank == 0) {
        if (taberu == 1) return 1;
        else {
            exit(1);
        }
    }
    if (taberu == 1) {
        return 0;
    } else if (taberu == (w / 2L) + 1L) {
        return 1L + paty[rank - 1];
    } else if (taberu == w) {
        return 1L + (2L * paty[rank - 1]);
    } else {
        if (taberu < (w / 2L) + 1L) {
            return get_tabeta(rank - 1L, taberu - 1L);
        } else {
            return 1L + paty[rank - 1] + get_tabeta(rank - 1L, taberu - 1L - width[rank - 1] - 1L);
        }
    }
    return tabeta;
}

int main() {
    cin >> n >> x;
    width.resize(n+1); paty.resize(n+1);
    paty[0] = 1; width[0] = 1;
    for (int i = 1; i <= n; i++) {
        width[i] = 3 + (2 * width[i - 1]);
        paty[i] = 1 + (2 * paty[i - 1]);
    }
    // rep(i, n+1) cout << i << " " << paty[i] << " " << width[i] << endl;
    // cout << "+++++++++++++" <<endl;
    cout << get_tabeta(n, x) << endl;

}
