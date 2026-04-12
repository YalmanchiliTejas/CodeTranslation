#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mod 1000000007
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define repc(i, a, b, c) for (ll i = a; (c > 0 ? i < b : i > b) and c != 0; i += c)
#define mp make_pair
#define pb push_back
#define all(name) (name.begin(), name.end())
#define fact(n) rep(i, 1, n+1)ft.pb((ft[i-1]*i)%mod);
#define mod_in(a) power(a, mod-2)
#define ncr(n, r) ((ft[n]*mod_in((ft[r]*ft[(n)-(r)])%mod))%mod)
#define deb(x) cout << #x << " " << x << endl;

class Dsu {
	vector<int> drr;
	vector<int> size_arr;
	public :
	Dsu (int n) {
		rep(i, 0, n+1){
			drr.pb(i);
			size_arr.pb(1);
		}
	}

	int f_p (int a) {
		return drr[a] == a ? a : f_p(drr[a]);
	}

	ll size (int a) {
		return (ll)size_arr[f_p(a)];
	}

	void uni(int a, int b) {
		int ap = f_p(a);
		int bp = f_p(b);
		if(ap == bp)return;
		if(!size_arr[ap] > size_arr[bp])swap(ap,bp);
		drr[bp] = ap;
		size_arr[ap] += size_arr[bp];
	}
};



vector<ll> ft(1, 1LL);
vector<bool> is_prime(1000000, 1);

void sieve();
ll power(ll x, ll y);

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int t = 1;
	// cin >> t;
	while(t--)
	{
		ll n, d, in1, in2;
		string s;
		cin >> s >> d;
		reverse(s.begin(), s.end());
		ll dp[s.size()+12][d+5][2];
        rep(i, 0, s.size()+1){
				rep(k, 0, d){
                    dp[i][k][0] = dp[i][k][1] = 0;
				}
			}
        rep(i, 1, 10) {
            if(s[0] - '0' >= i)dp[1][i%d][1]++;
            dp[1][i%d][0]++;
        }
        dp[1][0][1]++, dp[1][0][0]++;
		rep(i, 1, s.size()){
			rep(j, 0, 10){
				rep(k, 0, d){
					if(s[i] - '0' > j)dp[i+1][(k+j)%d][1] += dp[i][k][0], dp[i+1][(k+j)%d][1] %= mod;
					if(s[i] - '0' == j)dp[i+1][(k+j)%d][1] += dp[i][k][1], dp[i+1][(k+j)%d][1] %= mod;
					dp[i+1][(k+j)%d][0] += dp[i][k][0], dp[i+1][(k+j)%d][0] %= mod;
				}
			}
		}
        cout << (dp[s.size()][0][1]-1+mod)%mod << endl;
	}
}
//
//
//
//
//
//important funct
ll power(ll x, ll y) {
    ll res = 1;x %= mod;
    while (y > 0) {
        if (y & 1)res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res%mod;
}
void sieve(){
	is_prime[0] = is_prime[1] = 0;
	for(int i = 2; i*i <= 1000000; i++)
		if(is_prime[i])
			repc(j, i*i, 1000000, i)is_prime[j] = 0;
}