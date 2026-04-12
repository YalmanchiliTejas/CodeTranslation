#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T,class U> inline bool chmin(T&x,U y){if(x>y){x=y;return true;}return false;}
template<class T,class U> inline bool chmax(T&x,U y){if(x<y){x=y;return true;}return false;}
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m{INT_MAX},M{},L{},r{INT_MAX},mi{},Mi{};
    cin>>n;
    vector<int> x(n),y(n);
    fr(i,n){
        cin>>x[i]>>y[i];
        if(x[i]>y[i]) swap(x[i],y[i]);
        if(chmin(m,x[i])) mi=i;
        chmax(L,x[i]);
        if(chmax(M,y[i])) Mi=i;
        chmin(r,y[i]);
    }
    ll ans{(0ll+L-m)*(M-r)};
    if(mi!=Mi){
        using P=pair<int,int>;
        set<P> st;
        st.emplace(y[mi],-1);
        st.emplace(x[Mi],-1);
        fr(i,n) if(i!=mi and i!=Mi){
            st.emplace(x[i],y[i]);
        }
        chmin(ans,ll(M-m)*(st.rbegin()->first-st.begin()->first));
        while(st.begin()->first<st.begin()->second){
            int x,y;
            tie(x,y)=*st.begin();st.erase(st.begin());
            st.emplace(y,x);
            chmin(ans,ll(M-m)*(st.rbegin()->first-st.begin()->first));
        }
    }
    cout<<ans<<'\n';
}