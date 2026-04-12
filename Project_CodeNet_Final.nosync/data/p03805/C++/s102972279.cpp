#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ld long double
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

/* Some Libraries */

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vector<vector<bool> > adj(n, vector<bool>(n, false));
    rep(i,m){
        int a,b; cin>>a>>b; a--; b--;
        adj[a][b] = true;
        adj[b][a] = true;
    }
    vi p;
    rep(i,n-1) p.pb(i+1);
    ll ans=0;
    do{
        int now = 0;
        bool ok=true;
        rep(i,n-1){
            if (!adj[now][p[i]]){
                ok = false;
                break;
            }
            now = p[i];
        }
        if (ok) ans++;
    }while(next_permutation(all(p)));
    cout<<ans<<endl;
    return 0;
}
