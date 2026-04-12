#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto (a): (b))
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
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl
#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl

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

const int MAX_N = 100005;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pll> vec(n);
    rep(i,n){
        int a,b;
        cin >> a >> b;
        if(a < b) swap(a,b);
        vec[i] = pll(a,b);
    }
    ll mx1=0,mx2=0,mn1=INF,mn2=INF;
    rep(i,n){
        cmx(mx1,vec[i].fi),cmx(mx2,vec[i].se);
        cmn(mn1,vec[i].fi),cmn(mn2,vec[i].se);
    }
    ll cand1 = (mx1-mn1)*(mx2-mn2);
    ll mlen = mx1-mn2;
    priority_queue<P> que;
    ll mx,mn=INF;
    rep(i,n){
        cmn(mn,vec[i].fi);
        que.push(P(vec[i].fi,vec[i].se));
    }
    while(!que.empty()){
        P p = que.top();
        mx = p.fi;
        cmn(cand1,mlen*(mx-mn));
        que.pop();
        if(p.se < 0){
            break;
        }
        cmn(mn,(ll)p.se);
        que.push(P(p.se,-1));
    }
    cout << cand1 << "\n";
    return 0;
}
