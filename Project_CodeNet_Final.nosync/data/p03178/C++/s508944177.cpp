#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define loop(i, a, b) for(lli i=a; i<b; i++)
#define loopb(i, a, b) for(lli i=a; i>=b; i--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define pb push_back
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vll;
#define umap unordered_map
#define all(x) x.begin(), x.end()
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
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
lli M = 1e9 + 7;
lli power(lli x, lli y){
    lli res = 1;
    x = x%M;
    while (y > 0) {
        if (y & 1)
            res = (res*x)%M ;
        y = y>>1;
        x = (x*x)%M ;
    }
    return res%M;
}
lli dp[10009][102][2];
lli calc(string& s, lli index, lli sum, lli e, lli d){
    lli n = s.size();
    if(sum % d == 0 && index == n)
        return 1;
    else if(index >= n)
        return 0;
    else if(dp[index][sum][e] != -1)
        return dp[index][sum][e];
    lli ans = 0;
    lli m = e == 0 ? 10 : s[index]-'0'+1;
    loop(i, 0, m){
        lli ne = e & ((s[index]-'0') == i);
        lli temp = sum;
        temp += i;
        temp %= d;
        ans += calc(s, index+1, temp, ne, d);
        ans %= M;
    }
    dp[index][sum][e] = ans;
    return ans;
}
lli solve(){
    string k;
    lli d;
    cin>>k>>d;
    memset(dp, -1, sizeof(dp));
    cout<<(calc(k, 0, 0, 1, d) - 1 + M)%M;
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
}