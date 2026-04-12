#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

int A,B,val[11][11], mn[11][11];
vector<pair<pi,string>> ed;

void edge(int x, int y, string z) {
    ed.pb({{x,y},z});
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B;
    FOR(i,1,A+1) FOR(j,1,B+1) {
        cin >> val[i][j];
        mn[i][j] = MOD;
    }
    F0R(i,100) edge(i+1,i+2,"X"); // 1 to 101 
    F0R(i,100) edge(i+102,i+103,"Y"); // 102 to 202
    F0R(x,101) F0R(y,101) {
        int z = 0;
        FOR(i,1,A+1) FOR(j,1,B+1) z = max(z,val[i][j]-x*i-y*j);
        FOR(i,1,A+1) FOR(j,1,B+1) mn[i][j] = min(mn[i][j],z+x*i+y*j);
        edge(1+x,202-y,to_string(z));
    }
    FOR(i,1,A+1) FOR(j,1,B+1) if (mn[i][j] != val[i][j]) {
        cout << "Impossible";
        exit(0);
    }
    cout << "Possible\n";
    cout << "202 " << sz(ed) << "\n";
    for (auto a: ed) cout << a.f.f << " " << a.f.s << " " << a.s << "\n";
    cout << "1 202";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS