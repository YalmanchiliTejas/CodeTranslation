#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
using ll=long long;
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N;
    cin>>N;
    vector<ll> A(N);
    rep(i,N){cin>>A.at(i);}
    if(N%2==0){
        ll ans;
        vector<ll> L(N/2+1),R(N/2+1);
        rep(i,N/2){
            L.at(i+1)=L.at(i)+A.at(2*i);
            R.at(i+1)=R.at(i)+A.at(N-1-2*i);
        }
        rep(i,N/2+1){
            ll now=L.at(i)+R.at(N/2-i);
            if(i==0){ans=now;}
            ans=max(ans,now);
        }
        cout<<ans<<endl;
        return 0;
    }

    //N奇数
    ll ans=0;
    rep(i,(N+1)/2){ans+=A.at(2*i);}
    vector<ll> ad((N-1)/2),adwa((N+1)/2);
    rep(i,(N-1)/2){
        ad.at(i)=A.at(2*i+1)-A.at(2*i+2);
    }
    rep(i,(N-1)/2){
        adwa.at(i+1)=adwa.at(i)+ad.at(i);
    }
    set<pair<ll,ll>> s;
    rep(i,(N+1)/2){
        s.insert({adwa.at(i),i});
    }

    ll kotae;
    rep(i,(N+1)/2){
        ll ansn=ans-A.at(2*i);
//cout<<ansn<<endl;
        pair<ll,ll> p;
        p=*rbegin(s);
        ll now=p.first-adwa.at(i);
        ansn+=now;

//cout<<ansn<<endl;
        if(i==0){kotae=ansn;}
        kotae=max(kotae,ansn);
        s.erase({adwa.at(i),i});
    }
    cout<<kotae<<endl;
    //cout<<ans<<endl;

    return 0;
}
