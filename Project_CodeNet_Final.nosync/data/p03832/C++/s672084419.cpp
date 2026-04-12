#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 1005;

int inv[MAX_N],fac[MAX_N],finv[MAX_N];

void make()
{
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(int i=2;i<MAX_N;i++){
		inv[i] = MOD - (ll)inv[MOD%i] * (MOD/i) % MOD;
		fac[i] = (ll)fac[i-1] * i % MOD;
		finv[i] = (ll)finv[i-1] * inv[i] % MOD;
	}
}

int mod_pow(int a, int b)
{
    int res = 1;
    while(b){
        if(b & 1){
            res = (ll)res * a % MOD;
        }
        a = (ll)a * a % MOD;
        b >>= 1;
    }
    return res;
}

int add(int x,int y)
{
    return (x + y)%MOD;
}

int sub(int x,int y)
{
    return (x+MOD-y)%MOD;
}

int mul(int x,int y)
{
    return (ll)x*y%MOD;
}

int dp[MAX_N][MAX_N];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    make();
    int m = b-a+1;
    dp[0][n] = 1;
    rep(i,m){
        rep(j,n+1){
            dp[i+1][j] = dp[i][j];
            for(int k = c; k <= d; k++){
                int rem = j-(i+a)*k;
                if(rem < 0) break;
                dp[i+1][rem] = add(dp[i+1][rem],mul(dp[i][j],mul(mul(fac[j],finv[k]),mul(mod_pow(finv[i+a],k),finv[rem]))));
            }
        }
    }
    cout << dp[m][0] << "\n";
    return 0;
}
