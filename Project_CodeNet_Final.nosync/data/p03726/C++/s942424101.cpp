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

int N;
set<int> adj[MX];
bool pa[MX];
queue<int> todo;

void rEdge(int a, int b) {
    adj[a].erase(b), adj[b].erase(a);
}

void makePa(int x, int y) {
    pa[x] = pa[y] = 1;
    rEdge(x,y);
    for (int i: adj[y]) {
        rEdge(y,i);
        if (sz(adj[i]) == 1) todo.push(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    F0R(i,N-1) {
        int a,b; cin >> a >> b;
        adj[a].insert(b), adj[b].insert(a);
    }
    
    FOR(i,1,N+1) if (sz(adj[i]) == 1) todo.push(i);
    while (sz(todo)) {
        int x = todo.front(); todo.pop();
        if (pa[x]) continue;
        if (sz(adj[x]) == 0) {
            cout << "First";
            exit(0);
        }
        int y = *adj[x].begin();
        makePa(x,y);
    }
    
    FOR(i,1,N+1) if (!pa[i]) {
        cout << "First";
        exit(0);
    }
    
    cout << "Second";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS