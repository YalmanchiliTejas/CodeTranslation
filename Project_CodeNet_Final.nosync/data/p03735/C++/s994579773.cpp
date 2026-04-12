#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
ll int MOD=998244353;
#define INF 1e9
#define N 310000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int n;
    cin>>n;
    vector<pii> v;
    ll int x[N],y[N];
    rep(i,n){
        cin>>x[i]>>y[i];
        v.pb({x[i],i});v.pb({y[i],i});
    }
    sort(v.begin(),v.end());
    rep(i,n){
        if(x[i]<y[i]) swap(x[i],y[i]);
    }
    ll int xM=0,xm=INF,yM=0,ym=INF;
    rep(i,n){
        if(x[i]>xM) xM=x[i];
        if(x[i]<xm) xm=x[i];
        if(y[i]>yM) yM=y[i];
        if(y[i]<ym) ym=y[i];
    }
    ll int ans1=(xM-xm)*(yM-ym);
    ll int a=v[0].first,b=v[2*n-1].first;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> p;
    ll int d=0;
    rep(i,n){
        if(y[i]==a){
            p.push({x[i],(ll)i});
            d=max(d,x[i]);
        }
        else {
            p.push({y[i],(ll)i});
            d=max(d,y[i]);
        }
    }
    ll int c=p.top().first,range=d-c;
    while(1){
        pii pp=p.top();
        if(pp.first==x[pp.second]){
            break;
        }
        else if(x[pp.second]!=b){
            p.pop();
            p.push({x[pp.second],pp.second});
            c=p.top().first;d=max(d,x[pp.second]);
            range=min(range,d-c);
        }
        else break;
    }
    ll ans2=(b-a)*range;
    cout<<min(ans1,ans2);
    return 0;
}
