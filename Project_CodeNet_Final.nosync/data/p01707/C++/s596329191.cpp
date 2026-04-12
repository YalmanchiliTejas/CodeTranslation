#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(a, b) for(auto (a): (b))
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define show(x) cout <<#x<<" = "<<(x)<<endl
#define spair(p) cout <<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(i,v.size())cout<<" "<<v[i];cout<<endl
#define sset(s) cout<<#s<<":";each(i,s)cout <<" "<<i;cout<<endl

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 2002;

ll inv[MAX_N],fac[MAX_N],finv[MAX_N];
ll dp[MAX_N][MAX_N];
ll sm[MAX_N][MAX_N];
ll times[MAX_N];

void make()
{
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(int i=2;i<MAX_N;i++){
		inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
		fac[i] = fac[i-1] * (ll) i % MOD;
		finv[i] = finv[i-1] * inv[i] % MOD;
	}
}

int main()
{
    make();
    while(1){
        int n,x;
        ll D;
        cin >> n >> D >> x;
        if(n == 0){
            break;
        }
        rep(i,n+1){
            rep(j,n+1){
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        rep(i,n){
            rep(j,n+1){
                sm[i+1][j] = 0;
            }
        }
        rep(j,n+1){
            sm[0][j] = 1;
        }
        rep(i,n){
            for(int j = i+1;j <= n;j++){
                if(j >= i+x){
                    dp[i+1][j] = (sm[i][j-1] + MOD - sm[i][j-x]) % MOD;
                }else{
                    dp[i+1][j] = sm[i][j-1];
                }
            }
            ll bf = 0;
            for(int j = i+1;j <= n;j++){
                bf = (bf + dp[i+1][j]) % MOD;
                sm[i+1][j] = bf;
            }
        }
        ll bf = 1;
        rep(i,n){
            bf = bf * ((D-i)%MOD) % MOD;
            times[i] = bf;
        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            ans = (ans + (dp[i][n] * times[i-1] % MOD) * finv[i]) % MOD;
        }
        cout << ans << "\n";
    }
}