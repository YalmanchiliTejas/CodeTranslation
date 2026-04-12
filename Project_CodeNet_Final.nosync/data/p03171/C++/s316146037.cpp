#include <bits/stdc++.h>
#define ll long long
#define INF (1LL << 60)
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

const int MAX_N = 3005;

ll dp[MAX_N][MAX_N][2];
ll a[MAX_N];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n+1){
        dp[i][i][n%2] = 0;
    }
    srep(i,1,n+1){
        rep(j,n-i+1){
            int k = i+j;
            int te = (n-i)%2;
            if(te == 0){
                dp[j][k][0] = max(dp[j+1][k][1]+a[j], dp[j][k-1][1]+a[k-1]);
            }else{
                dp[j][k][1] = min(dp[j+1][k][0]-a[j], dp[j][k-1][0]-a[k-1]);
            }
        }
    }
    // rep(i,n){
        // srep(j,i,n+1){
            // cout << i << " " << j << " " << dp[i][j][(n-(j-i))%2] << "\n";
        // }
    // }
    cout << dp[0][n][0] << "\n";
    return 0;
}