#include <bits/stdc++.h>
#define minus djsf
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

int pw(int x, int y) {
    
    ll ans = 1;
    ll deg = x;
    for (int i=0; i < 30; ++i){
        int ba = (1LL<<i)&y;
        if (ba != 0){
            ans *= deg;
            ans %= mod;
        }
        deg *= deg;
        deg %= mod;
    }
    
	return ans;
}

const int N = 10000007;

int fact[N], rev[N];

int C(int n, int k) {
	int A = fact[n];
	int B = ((ll) rev[k] * rev[n-k]) % mod;
	return ((ll) A * B) % mod;
}
 
signed main()
{
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("P_output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    for (int i=1; i < N; ++i) fact[i] = ((ll) fact[i-1] * i) % mod;
    for (int i=0; i < N; ++i) rev[i] = pw(fact[i], mod-2);

    	//cout << pw(2, 5) << endl;
    

    int n;
    cin >> n;

    int ans = pw(3, n);

    for (int i=n/2+1; i <= n; ++i) {
    	int T = (2*C(n, i)) % mod;
    	T = ((ll) T * pw(2, n - i)) % mod;
    	ans = (ans - T + mod) % mod;
    }

    cout << ans;


	
}