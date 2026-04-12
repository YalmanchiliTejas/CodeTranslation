#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define loop(i, a, b) for(lli i=a; i<b; i++)
#define loopb(i, a, b) for(lli i=a; i>=b; i--)
#define pb push_back
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vll;
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
lli dp[2][10005][105];
lli M = 1e9 + 7 ;
lli d;
string k;
lli calc(lli e, lli dig, lli sum){
	lli n = k.length();
	if(dig <= 0)
		return sum == 0;
	if(dp[e][dig][sum] != -1)
		return dp[e][dig][sum];
	lli res = 0;
	lli c = (e == 1 ? k[n-dig]-'0' + 1: 10);
	loop(i, 0, c){
		lli ne = (e & (i == k[n-dig]-'0'));
		res += calc(ne, dig-1, (sum+i)%d);
		res = res%M;
	}
	res = res%M;
	dp[e][dig][sum] = res;
	return res;
}
lli solve(){
	cin>>k>>d;
	lli n = k.length();
	lli res = 0;
	memset(dp, -1, sizeof(dp));
	calc(1, n, 0);
	cout<<(dp[1][n][0] - 1 + M)%M<<"\n";
	return 0;
}
int main(){
	fastio;
	lli t;
//	cin>>t;
	t = 1;
	while(t>0){
		t--;
		solve();
	}
}