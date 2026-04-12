#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define int         int64_t
#define ii          pair<int,int>
#define dd          pair<double,double>
#define vi          vector<int>
#define pb          push_back
#define all(x)      (x).begin(), (x).end()
#define checkBit(v, p)      (v&(1LL << p))
#define loop(i,a,b) for(int i = a;i < int(b);i++)
#define x           first
#define y           second
using namespace std;
int inf = 4e18, mod = 1e9 + 7;
int n,a,b,c,d,sum = 0;
vector<vi> dp;
vi fact, ifact;

int power(int b, int e){
    if(e == 0) return 1;
    if(e == 1) return b;
    int cur = power(b, e/2);
    return cur * cur % mod * (e%2?b:1) % mod;
}

int rec(int sz, int num){
    if(sz == a-1) return num == 0;
    if(dp[sz][num] != -1) return dp[sz][num];
    dp[sz][num] = rec(sz-1, num);
    for(int i=c;i<=d;i++){
        if(num - sz * i < 0) break;
        int cho = fact[num] * ifact[i*sz] % mod * ifact[num - i*sz] % mod;
        dp[sz][num] = (dp[sz][num] + cho * rec(sz-1, num - i * sz) % mod * fact[sz * i] % mod * power(ifact[sz], i) % mod * ifact[i] % mod) % mod;
    }
    return dp[sz][num];
}

void first_n_inverses(int n, int mod, vi &inv) // assign inv[i] for i=0,...,n
{
    inv.resize(n + 1);
    inv[0] = inv[1] = 1;
    for(int i=2;i<=n;i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
}


int32_t main()
{
    ios_base::sync_with_stdio(false); cout << fixed <<setprecision(0);
    cin >> n >> a >> b >> c >> d;
    dp.resize(b+1,vi(n+1,-1));
    fact.resize(n+1);
    first_n_inverses(n,mod, ifact);
    fact[0] = 1;
    for(int i = 1;i<=n;i++) fact[i] = fact[i-1] * i % mod, ifact[i] = ifact[i-1] * ifact[i] % mod;
    cout << rec(b,n)<<endl;
    return 0;
}
