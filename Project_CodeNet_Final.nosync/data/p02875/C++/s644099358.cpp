#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#define pb push_back
#define mp make_pair
#define taskname "A"

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,int> ii;
typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int maxn = 1e7 + 5;
const int mod = 998244353;
int n;
int r[maxn] , fac[maxn] , rfac[maxn];
int P[maxn];

int nCk(int n , int k){
    return (ll)fac[n] * rfac[n - k] % mod * rfac[k] % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    cin >> n;
    r[1] = 1;
    for(int i = 2; i <= n ; ++i){
        r[i] = (mod - (ll)(mod / i) * r[mod % i] % mod);
    }
    P[0] = fac[0] = rfac[0] = 1;
    int res = 1;
    for(int i = 1 ; i <= n ; ++i){
        P[i] = P[i - 1] * 2 % mod;
        fac[i] = (ll)fac[i - 1] * i % mod;
        rfac[i] = (ll)rfac[i - 1] * r[i] % mod;
        res = (ll)res * 3 % mod;
    }
    for(int i = n / 2 + 1 ; i <= n ; ++i){
        res -= 2ll * nCk(n , i) * P[n - i] % mod;
        if(res < 0)res += mod;
    }
    cout << res;
}
