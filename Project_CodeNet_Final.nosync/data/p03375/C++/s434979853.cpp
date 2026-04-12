#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
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

const int MAX_N = 3005;
int MOD;

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

int comb(int a,int b)
{
	if(a<b){
		return 0;
	}
	return fac[a] * ((ll)finv[b] * finv[a-b] % MOD) % MOD;
}

inline int add(int x,int y)
{
    return (x + y)%MOD;
}

inline int sub(int x,int y)
{
    return (x+MOD-y)%MOD;
}

inline int mul(int x,int y)
{
    return (ll)x*y%MOD;
}
int t[9000005];
int tt[3005];
int S[3005][3005];

void Stirling(int N)
{
    S[0][0] = 1;
    rep(i,N){
        rep(j,i+1){
            S[i+1][j+1] = add(S[i][j],mul(j+1,S[i][j+1]));
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> MOD;
    make();
    t[0] = 1;
    rep(i,n*n){
        t[i+1] = mul(t[i],2);
    }
    tt[0] = 2;
    rep(i,n){
        tt[i+1] = mul(tt[i],tt[i]);
    }
    Stirling(n+1);
    int ans = 0;
    rep(k,n+1){
        int cri = 0;
        rep(i,k+1){
            cri = add(cri,mul(t[i*(n-k)],S[k+1][i+1]));
        }
        if(k % 2){
            ans = sub(ans,mul(cri,mul(tt[n-k],comb(n,k))));
        }else{
            ans = add(ans,mul(cri,mul(tt[n-k],comb(n,k))));
        }
    }
    cout << ans << "\n";
    return 0;
}
