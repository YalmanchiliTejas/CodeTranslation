#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    ll N;
    cin >> N;
    vector<Pll> ball(N);
    ll uppermax=0,uppermin=INF,lowermax=0,lowermin=INF;
    ll maxid,minid;
    rep(i,N){
        ll x,y;
        cin >> x >> y;
        if (x<y) swap(x,y);
        if (chmax(uppermax,x)) maxid=i;
        chmin(uppermin,x);
        chmax(lowermax,y);
        chmin(lowermin,y);
        ball[i]=Pll(x,y);
    }
    ll ans=(uppermax-uppermin)*(lowermax-lowermin);
    ll restmin=INF;
    rep(i,N){
        if (i==maxid) continue;
        if (chmin(restmin,ball[i].second)) minid=i;
    }
    if (ball[minid].second<lowermin){
        cout << ans << endl;
        return 0;
    }
    ll a=ball[maxid].second,b=ball[minid].first;
    ll rangemin=min(a,b),rangemax=max(a,b);
    vector<Pll> outofrange;
    ll newrangemin=rangemin,newrangemax=rangemax;
    rep(i,N){
        if (i==maxid||i==minid) continue;
        ll x=ball[i].first,y=ball[i].second;
        if (!(rangemin<=x&&x<=rangemax)&&!(rangemin<=y&&y<=rangemax)){
            chmin(newrangemin,x);
            chmax(newrangemax,y);
        }
    }
    rangemin=newrangemin,rangemax=newrangemax;
    rep(i,N){
        if (i==maxid||i==minid) continue;
        ll x=ball[i].first,y=ball[i].second;
        if (!(rangemin<=x&&x<=rangemax)&&!(rangemin<=y&&y<=rangemax)){
            outofrange.push_back(Pll(x,y));
        }
    }
    sort(outofrange.begin(),outofrange.end());
    reverse(outofrange.begin(),outofrange.end());
    int s=outofrange.size();
    if (s==0){
        cout << min(ans,(uppermax-lowermin)*(rangemax-rangemin)) << endl;
        return 0;
    }
    outofrange.push_back(Pll(rangemax,rangemin));
    ll Left=rangemin;
    rep(i,s){
        ll Right=outofrange[i+1].first,y=outofrange[i].second;
        chmin(Left,y);
        chmin(ans,(uppermax-lowermin)*(Right-Left));
    }
    cout << ans << endl;
}