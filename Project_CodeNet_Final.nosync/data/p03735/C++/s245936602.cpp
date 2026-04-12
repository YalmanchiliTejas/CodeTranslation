#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout << fixed << setprecision(20);

    ll n;
    cin>>n;
    if(n==1){
        cout << 0 << endl;
        return 0;
    }
    ll x[n],y[n];
    ll pma=0,pmi=0;
    ll ma=0,mi=1e18;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        if(x[i] > y[i]) swap(x[i],y[i]);
        if(ma < max(x[i],y[i])){
            ma = max(x[i],y[i]);
            pma = i;
        }
        if(mi > min(x[i],y[i])){
            mi = min(x[i],y[i]);
            pmi = i;
        }
        if(ma == max(x[i],y[i]) && pmi==pma){
            pma = i;
        }
        if(mi == min(x[i],y[i]) && pmi == pma){
            pmi = i;
        }
    }
    ll ans = 1e18;
    ll l=1e18,r=0;
    for(int i=0;i<n;i++){
        if(i==pmi && i==pma);
        else if(i==pma) r = max(r,min(x[i],y[i]));
        else if(i==pmi) l = min(l,max(x[i],y[i]));
        else {
            r = max(r, min(x[i],y[i]));
            l = min(l, max(x[i],y[i]));
        }
    }
    ans = (ma - l) * (r - mi);
    if(pmi != pma){
        ll dif = ma - mi;
        array<ll,2> a[n];
        multiset<ll> st;
        for(int i=0;i<n;i++){
            a[i] = {x[i],i};
            st.insert(x[i]);
        }
        sort(a,a+n);
        st.insert(y[a[0][1]]);
        auto itr = st.begin();
        auto h = itr;
        h++;
        st.erase(itr,h);
        itr =  st.end();
        itr--;
        ma = *itr;
        ans = min(ans, dif * (ma - *st.begin()));
        for(int i=1;i<n;i++){
            auto t = st.lower_bound(a[i][0]);
            auto k = t;
            k++;
            st.erase(t,k);
            st.insert(y[a[i][1]]);
            itr = st.end();
            itr--;
            ans = min(ans, dif * (*itr - *st.begin()));
        }
    }
    cout << ans << endl;
}
