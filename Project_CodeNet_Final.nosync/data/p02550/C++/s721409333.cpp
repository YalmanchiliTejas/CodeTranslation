#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()
#define chmax(x,y) x=max(x,y)




int main(){
    ll n,x,m; cin>>n>>x>>m;
    vector<int> che(1e5+5,0);
    ll now=x%m;
    int cnt=0;
    while(che[now]==0){
        che[now]=1;
        now*=now;
        now%=m;
        cnt++;
    }
    vector<ll> candi;
    candi.push_back(now);
    now*=now;
    now%=m;
    while(candi[0]!=now){
        candi.push_back(now);
        now*=now;
        now%=m;
    }
    cnt-=candi.size();
    if(n<=cnt){
        ll ans=0;
        now=x%m;
        rep(i,n){
            ans+=now;
            now*=now;
            now%=m;
        }
        cout<< ans <<endl;
        return 0;
    }
    ll ans=0;
    now=x%m;
    rep(i,cnt){
        ans+=now;
        now*=now;
        now%=m;
    }
    ll kari=0;
    for(auto &v: candi){
        kari+=v;
    }
    n-=cnt;
    ans+=kari*(n/candi.size());
    n%=candi.size();
    rep(i,n){
        ans+=candi[i];
    }
    cout<< ans <<endl;
    return 0;
}