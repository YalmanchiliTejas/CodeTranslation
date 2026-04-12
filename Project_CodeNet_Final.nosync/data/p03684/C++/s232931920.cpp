#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define outmat(v) for(auto i : v){for(auto j : i) cout << j << " ";cout << endl;}
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define infi 1900000000
#define infl 1100000000000000000
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
#define csp << " " <<
#define outset(n) cout << fixed << setprecision(n);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> using ve = vector<T>;
template<typename T> using pq2 = priority_queue<T>;
template<typename T> using pq1 = priority_queue<T,vector<T>,greater<T>>;
template <typename T> bool chmax(T &a, T b) {if(a < b) {a = b;return 1;}return 0;}
template <typename T> bool chmin(T &a, T b) {if(a > b) {a = b;return 1;}return 0;}




int main()
{
    int N;
    cin >> N;
    
    ve<pii> x(N),y(N);
    rep(i,N){
        int a,b;
        cin >> a >> b;
        x[i] = {a,i};
        y[i] = {b,i};
    }
    sort(all(x));
    sort(all(y));
    
    
    ve<ve<pii>> G(N);
    rep(i,N-1){
        G[x[i].se].pb({abs(x[i].fi-x[i+1].fi), x[i+1].se});
        G[y[i].se].pb({abs(y[i].fi-y[i+1].fi), y[i+1].se});
        G[x[i+1].se].pb({abs(x[i].fi-x[i+1].fi), x[i].se});
        G[y[i+1].se].pb({abs(y[i].fi-y[i+1].fi), y[i].se});
    }
    
    
    pq1<pii> A;
    vi f(N,1);
    A.push({0,0});
    
    ll ans = 0;
    
    while (!A.empty()) {
        
        pii a = A.top();
        A.pop();
        
        if(!f[a.se]) continue;
        //cout << "111" csp a.se csp a.fi << endl;
        f[a.se] = 0;
        ans += (ll)(a.fi);
        //cout << ans << endl;
        for (auto p : G[a.se]) {
            if(!f[p.se]) continue;
            A.push(p);
            //cout << p.fi csp p.se << endl;
        }
        
    }
    
    
    
    cout << ans << endl;
    

    return 0;
}
