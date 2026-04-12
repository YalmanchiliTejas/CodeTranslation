#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;cin>>n;
    vector<P> v(n);
    ll mi=1e10,ma=-1;
    for(int i=0;i<n;i++){
        ll x,y;cin>>x>>y;
        if(x>y) swap(x,y);
        mi=min(mi,x);
        ma=max(ma,y);
        v[i]=P(x,y);
    }
    sort(v.begin(),v.end());
    ll rmin=1e10;
    for(int i=0;i<n;i++) rmin=min(rmin,v[i].second);
    ll res=(v[n-1].first-mi)*(ma-rmin);
    set<P> st; // blue candidate
    st.insert(P(v[0].second,-1LL)); 
    for(int i=1;i<n;i++) st.insert(P(v[i].second,i));
    while(true){
        ll dif=(*st.rbegin()).first-(*st.begin()).first;
        res=min(res,dif*(ma-mi));

        P p=(*st.rbegin());
        st.erase(p);
        if(p.second==-1) break;
        st.insert(P(v[p.second].first,-1LL));        
    }
    cout<<res<<endl;
}