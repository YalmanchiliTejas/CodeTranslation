#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <math.h>
#include <set>
#include <stack>
#include <bitset>
#include <map>
#include <queue>
#include <random>
#include <unordered_set>
#include <unordered_map>
#define DEBUG
#define fi first
#define se second
#define pqueue priority_queue
#define pb(x) push_back(x)
#define endl '\n'
#define all(x) x.begin(), x.end()
#define int long long
#define mk(a, b) make_pair(a, b)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ull> vull;
typedef vector<ll> vll;
// typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vpii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector< vector<int> > vvi;
typedef vector<char> vc;

const int INF = 1e9;
const ll INFLL = 1e16;
const int MOD = 1000000007;
const int MAXN = 3e5;
//const ld eps = 1e-6;
const ld eps2 = 1e-9;
const int MOD2 = 998244353;
const int dosz = 5e5;
const int SZ = (1<<18);
const ld PI = atan2l(0, -1);


void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef DEBUG
        // freopen("a.in", "r",stdin);
#else
       // freopen("substrcmp.in", "r", stdin);
       // freopen("substrcmp.out", "w", stdout);
#endif
}

void solve(){
    string s;
    cin >> s;
    if(s=="AAA" || s == "BBB"){
        cout << "No";
    } else{
        cout << "Yes";
    }

}

signed main() {
    fast_io();
    int q = 1;
    // cout << fixed << setprecision(6);
    // cin >> q;
    // cout << 1 << endl;
    while(q--){
        solve();
    }
    return 0;
}
