#include <bits/stdc++.h>
#include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
using namespace atcoder;

int op(int a, int b) { return max(a, b); }
int e() { return -1; }
int target;
bool f(int v) { return v < target; }
void Main()
{
    int n, Q;
    cin >> n >> Q;

    vector<int> A(n);
    rep(i, n) cin >> A[i];
    
    segtree<int, op, e> seg(A);

    rep(i, Q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, v;
            cin >> x >> v;
            x--;
            seg.set(x, v);
        }
        else if (t == 2) {
            int l, r;
            cin >> l >> r;
            l--;
            put(seg.prod(l, r));
        }
        else {
            int p;
            cin >> p >> target;
            p--;
            // p以上でfがfalseになる最小のインデックスを返す
            put(seg.max_right<f>(p) + 1);
        }
    }
}
signed main(){ Main();return 0;}