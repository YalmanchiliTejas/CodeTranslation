#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define loop(i, a, b) for(lli i=a; i<b; i++)
#define loopb(i, a, b) for(lli i=a; i>=b; i--)
#define pb push_back
#define umap unordered_map
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vll;
typedef pair<lli, pii> ppi;
typedef tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// use to avoid collision
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// for pair in unordered_map
struct hash_pair {
    static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
    }
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const{
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        uint64_t x = hash1 ^ hash2;
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
lli M = 1e9 + 7;
lli power(lli x, lli y){
    lli res = 1;
    x = x ;
    while (y > 0) {
        if (y & 1)
            res = (res*x) ;
        y = y>>1;
        x = (x*x);
    }
    return res;
}
lli dp[2][105][4];
string s;
lli calc(lli e, lli index, lli k){
    lli n = s.length();
    if(index == n && k != 0)
        return 0;
    else if(k < 0)
        return 0;
    else if(k == 0)
        return 1;
    else if(dp[e][index][k] != -1)
        return dp[e][index][k];
    lli ans = 0;
    lli c;
    if(e == 1)
        c = s[index]-'0'+1;
    else
        c = 10;
    loop(i, 0, c){
        lli ne;
        if(e & (s[index]-'0' == i))
            ne = 1;
        else
            ne = 0;
        if(i == 0)
            ans += calc(ne, index+1, k);
        else{
            ans += calc(ne, index+1, k-1);
        }
    }
    dp[e][index][k] = ans;
    return ans;
}
lli solve(){
    cin>>s;
    lli k;
    cin>>k;
    lli n = s.length();
    memset(dp, -1, sizeof(dp));
    lli ans = calc(1, 0, k);
    cout<<ans<<"\n";
    return 0;
}   
int main(){
    fastio;
    lli t;
    // cin>>t;
    t = 1;
    while(t>0){
        t--;
        solve();
    }
    return 0;
}
