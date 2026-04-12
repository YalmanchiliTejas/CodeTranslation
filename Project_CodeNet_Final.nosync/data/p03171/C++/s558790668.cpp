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
lli solve(){
	lli n;
	cin>>n;
	vll a(n);
	loop(i, 0, n)	cin>>a[i];
	vector<vector<pii> > dp(n, vector<pii> (n, {0, 0}));
	loop(len, 1, n+1){
		loop(j, len-1, n){
			lli i = j - (len-1);
			if(len == 1)
				dp[i][j] = {a[i], 0};
			else{
				pii t1 = {dp[i+1][j].s + a[i], dp[i+1][j].f};
				pii t2 = {dp[i][j-1].s + a[j], dp[i][j-1].f};
				if(t1.f == t2.f){
					if(t1.s <= t2.s)
						dp[i][j] = t1;
					else
						dp[i][j] = t2;
				}
				else{
					if(t1.f <= t2.f)
						dp[i][j] = t2;
					else
						dp[i][j] = t1;
				}
			}
//			cout<<"("<<dp[i][j].f<<" "<<dp[i][j].s<<") ";
		}
//		cout<<"\n";
	}
	cout<<(dp[0][n-1].f - dp[0][n-1].s)<<"\n";
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