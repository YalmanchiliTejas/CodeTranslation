#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define ppb pop_back()
#define ppf pop_front()
#define all(vec) vec.begin(), vec.end()
#define fol(i,a,b) for(int i=a;i<b;i++)
#define loop(i,a,b) for(int i=a;i>=b;i--)
#define forr(x,arr) for(auto& x:arr)
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-7
#define sz(x) ((lli)(x).size())

using   lli     =   long long;
using   lld     =   long double;
using   ulli    =   unsigned long long int;
using   pll     =   pair<lli, lli>;
using   ttt     =   pair<lli, pll>;
using   vttt    =   vector<ttt>;
using   vll     =   vector<pll>;
using   vl      =   vector<lli>;
using   vi      =   vector<int>;
using   vvi     =   vector<vector<int>>;
using   cd      =   complex<lld>;
const double PI = acos(-1);

#ifndef tejasp
#define trace(...) {}
#define cotra(...) {}
#define end_routine() {}
#define localsys 0
#define endl '\n'
#endif

inline lli mpow(lli a, lli b, lli m=mod) {
    a = a%mod;          b = b%(mod-1);
    if(a<0) a+=mod;     if(b<0) b+=mod-1;
    if(a==0) return 0;
    lli ans = 1;
    while (b) {
        if (b&1) ans=(ans*a)%m;
        a=(a*a)%m; b/=2;
    }
    return ans;
}

#define MAXN  1010
lli fact[MAXN], invf[MAXN], po[MAXN][MAXN];

void __prec()
{
    fact[0]=1;
    fol(i,1,MAXN) fact[i]=(fact[i-1]*i)%mod;
    fol(i,0,MAXN) invf[i]=mpow(fact[i],mod-2);
    fol(i,0,MAXN) fol(j,0,MAXN) po[i][j]=mpow(invf[i],j);
}

lli get(int n, int a, int k, int p)
{
    return (((((fact[n]*invf[a])%mod)*po[k][p])%mod)*invf[p])%mod;
}

std::vector<vl> dp(MAXN,vl(MAXN,0));

int tejas_919(int kkkk)
{
    lli n, m, k, q, u, v, temp=0, ans=0;
    lli a, b, c, d;
    cin>>n>>a>>b>>c>>d;
    trace(n,MAXN)
    dp[a-1][0]=1;
    fol(i,a,b+1) //size of each block
    {
        fol(j,0,MAXN) dp[i][j]=dp[i-1][j];
        fol(k,0,n)
        {
            if(dp[i-1][k]==0) continue;
            fol(j,c,d+1) //number of blocks
            {
                temp=k+(i*j);
                if(temp>n) break;
                dp[i][temp]+=(dp[i-1][k]*get(n-k,n-temp,i,j))%mod;
                dp[i][temp]%=mod;
            }
        }
    }
    cotra(dp)
    cout<<dp[b][n]<<endl;
    return 0;
}

signed main()
{
    #ifdef tejasp
            freopen("input.txt", "rt", stdin);
            freopen("output.txt", "wt", stdout);
    #endif
    if(!localsys) { ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); }
    cout << fixed << setprecision(10);
    __prec();
    int t=1;
    //cin>>t;
    fol(i,0,t) { tejas_919(i+1); }
    end_routine();
    if(localsys) system("pause");
}
