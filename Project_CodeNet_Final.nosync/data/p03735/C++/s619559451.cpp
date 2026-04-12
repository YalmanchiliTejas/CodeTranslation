#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;

pair<ll,ll> p[200001];
int main(){
    int n,xi,yi;
    cin>>n;
    ll lmn=1000100010,lmx=0,rmn=1000100010,rmx=0;
    ll pl,pr;
    rep(i,n){
        cin>>xi>>yi;
        if(xi>yi) swap(xi,yi);
        p[i]=mp(xi,yi);
        if(lmn>xi) lmn=xi,pl=yi;
        if(lmx<xi) lmx=xi;
        if(rmn>yi) rmn=yi;
        if(rmx<yi) rmx=yi,pr=xi;
    }
    ll ans1=(rmx-rmn)*(lmx-lmn);
    sort(p,p+n);
    ll ans2=1000100010;
    ll mx=p[n-1].first;ll mn=1000100010;
    FOR(i,0,n-1){
        //if(p[i].first==pr) continue;
        mx=max(mx,p[i].second);
        mn=min(mn,p[i].second);
        ll mn2=min(mn,p[i+1].first);
        ans2=min(ans2,mx-mn2);
    }
    //cout<<ans1<<" "<<ans2<<endl;
    ll ans=min(ans1,ans2*(rmx-lmn));
    cout<<ans<<endl;
    return 0;
}