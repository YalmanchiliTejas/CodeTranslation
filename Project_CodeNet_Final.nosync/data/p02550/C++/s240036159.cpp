#include<bits/stdc++.h>

using namespace std;
using   ll=long long;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define pb          	push_back
#define mp          	make_pair
#define F           	first
#define S           	second
#define pll				pair<int , int>
#define int             long long int
#define endl            "\n"

#define ALL(v)      	v.begin(),v.end()
#define ALLR(v)     	v.rbegin(),v.rend()
#define pii         	3.14159265358979323
#define inf     		LLONG_MAX
#define ones(x)     	__builtin_popcount(x)
#define fill(a,b)   	memset(a,b,sizeof(a))
#define mod 			998244353

ll mod_pow(ll a,ll b,ll m)
{
    ll res = 1;
    while(b)
    {
        if(b&1)
        {
        	res=(res*a) % m;
        }
        a=(a*a) % m;
        b>>=1;
    }
    return res;
}

ll mod_inverse(int a , int m)
{
	return mod_pow(a , m - 2 , m);
}

const int maxn = 5e5 + 5;

void solve() {
	
	int n , x , m;
	
	cin >> n >> x >> m;
	
	map< int , int> f;
	
	int dp[maxn] {};
	int tot = 0;
	int pre = 1;
	
	for(int i = 1; i <= n; ++i) {
		if(i != 1) {
			pre = (pre * pre) % m;
		}
		else {
			pre = x % m;
		}
		
		if(f.find(pre) != f.end()) {
			int rem = n - i + 1;
			
			int p = i - f[pre];
			int tm = rem / p;
			int u = rem % p;
			
			for(int j = f[pre]; j < i; ++j) {
				tot += tm*dp[j];
			}
			
			for(int j = f[pre]; j < i; ++j) {
				if(u > 0) {
					tot += dp[j];
					u--;
				}
				else {
					break;
				}
			}
			
			break;
		}
		else {
			f[pre] = i;
			tot += pre;
			dp[i] = pre;
		}
	}
	
	cout << tot;
}

signed main() {
	fast;
   
    int t = 1;

	//cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
