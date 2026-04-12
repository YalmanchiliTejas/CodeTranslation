#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
#define pii pair<ll, ll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
 
const int N = 3e6 + 5;
const int mod = 1e9+7;
const ll INF = (ll)4e18 + 5;

inline int mul(int a, int b){
    return ((ll)a * b) % mod;
}

// inline int add(int a, int b){
//     int ans = a + b;
//     if(ans >= mod) ans -= mod;
//     return ans; 
// }

bool isprime(ll n){
    if(n<2) return false;
    for(ll i=2;i*i*i<=n;++i) if(n%i==0) return false;
    for(int it=0;it<1e2;++it){
        ll i = rand()%(n-1)+1;
        if(__gcd(i,n)!=1) return false;
        // if(mpow(i,n-1,n)!=1) return false;
    }
    return true;
}

ll fast_pow(ll a, ll b){
    ll ans = 1;
    a %= mod;
    while(b){
        if(b&1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

struct Matrix{
    vector<vector<ll>> m;
    int r, c;

    Matrix(int x){
        r = c = x;
        m.resize(x, vector<ll>(x, 0));
        // for(int j = 0; j < x; j++) m[j][j] = 1;
    }

    Matrix mult(Matrix& l, Matrix& r){
        Matrix ans(l.r);
        for(int j = 0; j < l.r; j++)
            for(int i = 0; i < r.c; i ++){
                ll &cur = ans.m[j][i];
                cur = 0;
                for(int k  = 0; k < l.c; k ++)
                    cur = (cur + (l.m[j][k] * r.m[k][i]) % mod) % mod;
            }
        return ans;
    }
};

// Matrix fast_mat_pow(Matrix& a, ll b){
//     Matrix ans;
//     while(b){
//         if(b&1) ans = ans.mult(ans, a);
//         a = a.mult(a, a);
//         b /= 2;
//     }
//     return ans;
// }

struct seg_tree{
    vector<ll> seg, lzy;
    int n;

    seg_tree(int x) : n(x) {
        seg.resize(4*n);
        lzy.resize(4*n);
    }

    void update_lzy(int l, int r, int i) {
        if (!lzy[i]) return;
        if (l != r) {
            lzy[i*2+1] += lzy[i];
            lzy[i*2+2] += lzy[i];
        }
        seg[i] += lzy[i];
        lzy[i] = 0;
    }

    void update(int x, int y, ll val, int l = 0, int r = -1, int i = 0){
        if (x > y) return;

        if (r == -1) r += n;
        update_lzy(l, r, i);
        if (r < x || l > y) return;
        if (l >= x && r <= y) {
            lzy[i] = val;
            return update_lzy(l, r, i);
        }
        int m = (l+r) >> 1;
        update(x, y, val, l, m, i*2+1);
        update(x, y, val, m+1, r, i*2+2);
        seg[i] = max(seg[i*2+1], seg[i*2+2]);
    }

    ll query (int x, int y, int l = 0, int r = -1, int i = 0) {
        if (x > y) return -1e18;

        if (r == -1) r += n;
        update_lzy(l, r, i);
        if (r < x || l > y) return -1e18;
        if (l >= x && r <= y) return seg[i];
        int m = (l+r) >> 1;
        return max(query(x, y, l, m, i*2+1), query(x, y, m+1, r, i*2+2));
    }
};

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    // srand(unsigned(time(0)));
    // vector<int> prime;
    // vector<int> seive(N, 0);
    // seive[0] = seive[1] = 1;
    // for(int j = 4; j < N; j+=2) seive[j] = 2;
    // for(int j = 3; j*j < N; j += 2) if(!seive[j])
    //     for(int k = j*j; k < N; k += j+j) if(!seive[k]) seive[k] = j;

    // for(int j = 2; j < N; j++)
    //     if(seive[j] == 0) prime.pb(j);

    // cout << prime.size() << endl;
    // for(int j = 0; j < 10; j ++) cout << prime[j] << " "; cout << endl;

    int n, m;
    cin >> n >> m;
    map<int, vector<pii>> started;
    map<int, vector<pii>> ended;

    while (m --) {
        int l, r, cost;
        cin >> l >> r >> cost;
        started[l].pb({r, cost});
        ended[r].pb({l, cost});
    }

    seg_tree seg(n+1);
    vector<ll> dp(n+1, 0);
    for (int j = 1; j <= n; j ++) {
        for (auto i : started[j]) {
            seg.update(0, j-1, i.S);
        }
        
        // put a '1' here 
        // Just check where should be put 1 previous to this. Suppose that index is 'i'
        // So, our cur_profit = {dp[i] + [profit of all the ranges [L, R] such that L <= i and R >= j]} for all 'i'
        // So, we update our node of tree to include this profit value
        // To make that we add profit of all such range [L, R] which started before 'j' and ends after 'j'
        //      to all the tree nodes in range [0, L-1].
        //      Because in 'cur_profit' while using dp[i] those ranges are add in the second term of above formula

        // Now, suppose a range ends before the current index i.e. 'j'. So, if we put '1' in the current index then
        //      the cost of that range is not included as it is out of range for any [L, R] such that R < j
        //      So, if a range ends here we should remove it's contribution from all the dp[i] to which we added previously
        //      So, we subtract that cost in the same range

        // Now, after doing all this for all j in [1, n]. We would have removed the contribution of each and every interval
        // so, only the dp[i] values remains at node 'i', which denotes that what is the cost if we put last 1 at 'i' index.
        // So, final answer will be the max of all such dp[i].

        dp[j] = seg.query(0, j-1);
        seg.update(j, j, dp[j]);

        for (auto i : ended[j]) {
            seg.update(0, i.F-1, -i.S);
        }
    }

    cout << seg.query(0, n) << endl;
    return 0;
}