#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define pii pair<ll, ll>
#define p3i pair<pii, ll>
#define pll pair<ll, ll>
#define p3l pair<pll, ll>
#define lseg L, (L+R)/2, N*2+1
#define rseg (L+R)/2+1, R, N*2+2
#define ub upper_bound
#define lb lower_bound
#define p_q priority_queue
#define MN 1000000009

ll n, x, y, D, X, Y;
ll ans;
pii t;
priority_queue<pair<ll, pii> > pq;
set<pii> sx, sy;
ll dis(ll X, ll Y, ll X2, ll Y2){
    return min(max(X-X2, X2-X), max(Y-Y2, Y2-Y));
}
int main(){
    cin >> n;
    for (ll l=0; l<n; ++l){
        cin >> x >> y;
        sx.insert(mp(x, y));
        sy.insert(mp(y, x));
        if (l==0) pq.push(mp(0, mp(x, y)));
    }
    while(!pq.empty()){
        D=-pq.top().x; X=pq.top().y.x; Y=pq.top().y.y; pq.pop();
        //cout << X << ' ' << Y << ' ' << D << endl;
        if (sx.lb(mp(X, Y))==sx.end() ||
            *sx.lb(mp(X, Y))!=mp(X, Y)) continue;
        sx.erase(mp(X, Y));
        sy.erase(mp(Y, X));
        ans+=D;
        if (sx.lb(mp(X, Y))!=sx.end()){
            t=*sx.lb(mp(X, Y));
            pq.push(mp(-dis(X, Y, t.x, t.y), t));
        }
        if (sx.lb(mp(X, Y))!=sx.begin()){
            t=*--sx.lb(mp(X, Y));
            pq.push(mp(-dis(X, Y, t.x, t.y), t));
        }
        if (sy.lb(mp(Y, X))!=sy.end()){
            t=*sy.lb(mp(Y, X));
            x=t.x; y=t.y; t=mp(y, x);
            pq.push(mp(-dis(X, Y, t.x, t.y), t));
        }
        if (sy.lb(mp(Y, X))!=sy.begin()){
            t=*--sy.lb(mp(Y, X));
            x=t.x; y=t.y; t=mp(y, x);
            pq.push(mp(-dis(X, Y, t.x, t.y), t));
        }
    }
    cout << ans;
    return 0;
}
