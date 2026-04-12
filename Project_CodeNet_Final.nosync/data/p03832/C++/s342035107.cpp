#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1010;

ll pw(ll x, ll y) {
    ll res=1;
    while (y) {
	if (y%2) {
	    res=res*x;
	    res%=mod;
	}
	x=x*x;
	x%=mod;
	y=y/2;
    }
    
    res%=mod;
    res+=mod;
    return res%mod;
}

ll add(ll x, ll y) {
    x %= mod;
    y %= mod;
    x += y;
    x %= mod;
    return x;
}


ll C[maxn][maxn];
ll fac[maxn*maxn], ifac[maxn*maxn], inv[maxn*maxn];

int n,a,b,c,d;


ll nck(int n, int k) {
    if (n<k) return 0;
    return C[n][k];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    //idk why my code doesn't work

    for (int i=0; i<=1000; i++) {
	C[i][0] = C[i][i] = 1;
	for (int j=1; j<i; j++) {
	    C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
	}
    }
    assert(C[4][2]==6);

    fac[0]=ifac[0]=1;
    for (int i=1; i<=1000000; i++) {
	fac[i]=fac[i-1]*i%mod;
    }
    
    inv[1]=1;
    for (int i=2; i<=1000000; i++) {
	inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
    }

    for (int i=1; i<=1000000; i++) {
	ifac[i] = ifac[i-1]*inv[i]%mod;
    }
    assert(ifac[1] == 1);
    assert(inv[6] == ifac[3]);
    assert(inv[47] == pw(47, mod-2));



    cin>>n>>a>>b>>c>>d;

    vector<ll> dp(n+1, 0);//num ways to use j ppl at the current iteration
    dp[0] = 1;

    //iterate over group size
    for (int i=a; i<=b; i++) {
	vector<ll> nxt(n+1, 0);

	for (int j=0; j<=n; j++) {
	    if (dp[j] == 0) continue;
	    ll ways = 1;
	    for (int k=0; k<=n-j; k+=i) {
		if (k==0 || (c<=k/i && k/i<=d)) {
		    nxt[j+k] = add(nxt[j+k], dp[j]*ways);
		}

		//out of the remaining ppl, pick i ppl for the next group
		//now there are (k/i)+1 groups, and order that we picked them doesn't matter.
		ways = ways*nck(n-j-k, i)%mod*inv[k/i+1]%mod;
			
	    }
	}

	swap(nxt, dp);
    }


    cout<<dp[n]<<endl;    

    return 0;
}
