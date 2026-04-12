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

const int MAX_N = 10005;

int dp[MAX_N][105][2];

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

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n;
    cin >> n;
    dp[0][0][0] = 1;
    int d = len(s);
    rep(i,d){
        int num = (int)(s[i]-'0');
        rep(j,n){
            rep(k,num){
                dp[i+1][(j+k)%n][1] = add(dp[i+1][(j+k)%n][1], add(dp[i][j][0], dp[i][j][1]));
            }
            dp[i+1][(j+num)%n][0] = add(dp[i+1][(j+num)%n][0], dp[i][j][0]);
            dp[i+1][(j+num)%n][1] = add(dp[i+1][(j+num)%n][1], dp[i][j][1]);
            srep(k,num+1,10){
                dp[i+1][(j+k)%n][1] = add(dp[i+1][(j+k)%n][1], dp[i][j][1]);
            }
        }
    }
    cout << sub(add(dp[d][0][0], dp[d][0][1]), 1) << "\n";
    return 0;
}