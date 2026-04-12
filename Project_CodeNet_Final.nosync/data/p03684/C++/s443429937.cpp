#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define pll pair<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vpll vector<pll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ln length()
#define M 1000000007
ll n;
pll pts[100005];
map<pll,ll> mark;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    set<pll> tem;
    rep(i,1,n) {
        ll u,v;cin>>u>>v;
        tem.insert(mp(u,v));
    }
    n=0;
    for(pll xp:tem) pts[++n]=xp;
    if(n == 1){
        cout<<0<<endl;
        return 0;
    }
    set<pll> xval,yval;

    rep(i,1,n) {
        xval.insert(pts[i]);
        yval.insert(mp(pts[i].S,pts[i].F));
    }

    priority_queue<pair<ll,pll> ,vector< pair<ll,pll>  > ,greater<pair<ll,pll>  > >pq;
    pq.push(mp(0,pts[1]));
    ll ans=0;
    while(!pq.empty()){
        auto xp=pq.top();
        pq.pop();
        if(mark[xp.S]) continue;
        //cout<<xp.F<<" "<<xp.S.F<<" "<<xp.S.S<<endl;
        ans+=xp.F;
        mark[xp.S]=1;


        auto it = xval.lower_bound(xp.S);
        it++;
        if(it!=xval.end()) {
           // cout<<(*it).F<<" "<<(*it).S<<endl;
            if(!mark[*it]) pq.push(mp((*it).F-xp.S.F,*it));
        }
        it--;

        if(it!=xval.begin()) {
            //cout<<(*it).F<<" "<<(*it).S<<endl;
            it--;
            if(!mark[*it]) pq.push(mp(-(*it).F+xp.S.F,*it));

        }


        auto it2 = yval.lower_bound(mp(xp.S.S,xp.S.F));
        it2++;
        if(it2!=yval.end()) {
            if(!mark[mp((*it2).S,(*it2).F)]) pq.push(mp((*it2).F-xp.S.S,mp((*it2).S,(*it2).F)));
        }
        it2--;
        if(it2!=yval.begin()) {
            it2--;;
            if(!mark[mp((*it2).S,(*it2).F)]) pq.push(mp(-(*it2).F+xp.S.S,mp((*it2).S,(*it2).F)));
        }

    }

    cout<<ans<<'\n';
}
