#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

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
    int n; cin>>n;
    string s; cin>>s;
    vector<bool> ans(n);
    rep(i,4){
        ans[0]=(i&1)? true : false;
        ans[1]=(i&2)? true : false;
        FOR(j,2,n-1){
            if (s[j-1]=='o'){
                ans[j] = (ans[j-1])?ans[j-2]:!ans[j-2];
            }else{
                ans[j] = (ans[j-1])?!ans[j-2]:ans[j-2];
            }
        }
        bool ok=true;
        rep(j,n){
            int prev = (j-1+n)%n;
            int next = (j+1)%n;
            if (s[j]=='o'){
                if (ans[j] && ans[prev]!=ans[next]) ok=false;
                if (!ans[j] && ans[prev]==ans[next]) ok=false;
            }else{
                if (ans[j] && ans[prev]==ans[next]) ok=false;
                if (!ans[j] && ans[prev]!=ans[next]) ok=false;
            }
        }
        if (ok){
            rep(j,n) cout<<((ans[j])?'S':'W');
            cout<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}
