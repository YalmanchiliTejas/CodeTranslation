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
    int h,w; cin>>h>>w;
    vector<string> s(h);
    vector<bool> f(h),g(w);
    rep(i,h) cin>>s[i];
    rep(i,h){
        rep(j,w)if(s[i][j]=='#'){
            f[i] = true;
            break;
        }
    }
    rep(j,w){
        rep(i,h)if(s[i][j]=='#'){
            g[j] = true;
            break;
        }
    }
    rep(i,h){
        if (!f[i]) continue;
        rep(j,w)if(g[j]){
            cout<<s[i][j];
        }
        cout<<endl;
    }
    return 0;
}
