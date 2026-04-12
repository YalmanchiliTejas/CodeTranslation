#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;
ll N, M;
string S;

ll beki(ll a, ll b) {
    if(b == 0) return 1;
    ll ans = beki(a, b / 2);
    ans = ans * ans % mod;
    if(b % 2 == 1) ans = ans * a % mod;
    return ans;
}

struct SegmentTree {
private:
    int n;
    vector<ll> node;
 
public:
    SegmentTree() {
        int sz = 200050;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }
 
    void update(int x, ll val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = (node[2*x+1] + node[2*x+2]) % mod;
        }
    }
    // hannkaikukann 
    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return (vl + vr) % mod;
    }
};

int main() {
    //cout.precision(10);
    cin >> N >> M;
    cin >> S;
    if(S[0] == 'B') {
        for(int i = 0; i < M; i++) {
            if(S[i] == 'B') S[i] = 'R';
            else S[i] = 'B';
        }
    }
    bool all = true;
    for(int i = 0; i < M; i++) {
        if(S[i] == 'B') all = false;
    }
    ll Rlen = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == 'R') Rlen++;
        else break;
    }
    //Rlen = Rlen * 2 + 1;
    if(Rlen % 2 == 0) {
        Rlen = Rlen  + 1;
    } else {
        Rlen = Rlen;
    }
    ll Rnow = -INF;
    for(int i = 0; i < S.size(); i++) {
        //cerr << Rnow << endl;
        if(S[i] == 'R') {
            Rnow++;
            continue;
        }
        if(Rnow < 0) {
            Rnow = 0;
            continue;
        }
        if(Rnow % 2 == 0) {
            Rnow = 0;
            continue;
        }
        Rlen = min(Rlen, Rnow);
        Rnow = 0;
    }
    if(all) {
        SegmentTree seg;
        seg.update(1, 1);
        for(int i = 2; i <= N + 1; i++) {
            ll val = seg.getsum(1, i - 1);
            seg.update(i, val);
        }
        ll ans = 0;
        for(ll now = 1; now <= N - 1; now++) {
            ans += now * seg.getsum(N - now, N - now + 1);
            ans %= mod;
        }
        ans += seg.getsum(N+1, N+2);
        ans += 1;
        ans %= mod;
        cout << ans << endl;
        return 0;
    }
    SegmentTree seg;
    seg.update(1, 1);
    cerr << Rlen << endl;
    //Rlen = 5;
    for(int i = 3; i <= N + 2; i += 2) {
        ll val = seg.getsum(max((ll)0, i - 1 - Rlen), i);
        seg.update(i, val);
        //cerr << i << " " << val << endl;
    }
    ll ans = 0;
    if(N % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    for(ll now = 1; now <= min(N, Rlen); now += 2) {
        ans += now * seg.getsum(N - now, N - now + 1);
        ans %= mod;
    }
    ans += seg.getsum(N + 1, N + 2);
    ans %= mod;
    cout << ans << endl;
    return 0;
}
