#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
using ldb = long double;
using pa = pair < int, int >;
template < typename T > using index_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
template < typename T > using MinPriorityQueue = priority_queue < T, vector < T >, greater < T > >;
#define pb push_back
#define all(c) c.begin(),c.end()
#define unique_sort(x) sort(all(x)), x.resize(distance(x.begin(), unique(all(x))))
#define F  first
#define S  second
#define f(i,x,n) for(int i=x;i<n;i++) 
const int MOD = 1e9 + 7, INF = INT_MAX, N = 5e5 + 10;
const double PI = acos(-1);
const int LINF = LLONG_MAX;

struct BIT{
    int N;
    vector<int> bit;
 
    void init(int n){
        N = n;
        bit.assign(n + 1, 0);
    }
 
    void update(int idx, int val){
        while(idx <= N){
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
 
    void updateMax(int idx, int val){
        while(idx <= N){
            bit[idx] = max(bit[idx], val);
            idx += idx & -idx;
        }
    }
 
    int pref(int idx){
        int ans = 0;
        while(idx > 0){
            ans += bit[idx];
            idx -= idx & -idx;
        }
        return ans;
    }
 
    int rsum(int l, int r){
        return pref(r) - pref(l - 1);
    }
 
    int prefMax(int idx){
        int ans = -2e9;
        while(idx > 0){
            ans = max(ans, bit[idx]);
            idx -= idx & -idx;
        }
        return ans;
    }
};
int modpow(int x, int y){
    int ans=1;
    if(y==1){
        return x%MOD;
    }
    x=x % MOD;
    y=y % (MOD-1);
    while(y>0){
        if(y & 1){
            ans = (ans*x) %MOD;
        }
        x *= x;
        x = x % MOD;
        y >>= 1;
    }
    return ans;
}

int modinv(int x){
    return modpow(x,MOD-2);
}
int sub(int x, int y) {
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}
int add(int x, int y) {
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
int multiply(int a,int b){
    a %= MOD;
    b %= MOD;
    return (a*b)%MOD;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int>v(n+1);
    f(i,1,n+1){
        cin >> v[i];
    }
    BIT bt;
    bt.init(n+1);
    f(i,1,n+1){
        bt.update(i,v[i]);
    }
    int ans = 0;
    f(i,1,n+1){
        int r = bt.rsum(i+1,n);
        ans = add(ans,multiply(v[i],r));
    }
    cout << ans;
    return 0;
}
 